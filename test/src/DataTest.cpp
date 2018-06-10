//
// Created by Andrei - Doru Pata on 09/06/18.
//
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <Data.hpp>
#include <Data-odb.hpp>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/sqlite/database.hxx>
#include <schema-catalog.hxx>

using namespace odb::core;

BOOST_AUTO_TEST_SUITE(DataSuiteTest)
  
  BOOST_AUTO_TEST_CASE(Create) {
    try {
      auto db = std::make_shared<odb::sqlite::database>("data.db",
                                                        SQLITE_OPEN_READWRITE
                                                        | SQLITE_OPEN_CREATE);
      auto data_1 = persist::Data{ 1, "data 1" };
      auto data_2 = persist::Data{ 2, "data 2" };
      auto data_3 = persist::Data{ 3, "data 3" };
      auto data_4 = persist::Data{ 4, "data 4" };
      
      transaction t(db->begin());
      schema_catalog::create_schema(*db);
      
      BOOST_TEST(db->persist(data_1) == 1);
      BOOST_TEST(db->persist(data_2) == 2);
      BOOST_TEST(db->persist(data_3) == 3);
      BOOST_TEST(db->persist(data_4) == 4);
      
      
      t.commit();
    }
    catch (const odb::exception& e) {
      BOOST_FAIL(e.what());
    }
  }
  
  BOOST_AUTO_TEST_CASE(Read) {
    try {
      auto db = std::make_shared<odb::sqlite::database>("data.db",
                                                        SQLITE_OPEN_READWRITE
                                                        | SQLITE_OPEN_CREATE);
      typedef odb::query<persist::Data> query;
      typedef odb::result<persist::Data> result;
      
      transaction t(db->begin());
      
      for (auto& data: db->query<persist::Data>(query::id > 2))
        BOOST_TEST(data.id_ > 2);
      
      t.commit();
    }
    catch (const odb::exception& e) {
      BOOST_FAIL(e.what());
    }
  }

BOOST_AUTO_TEST_SUITE_END()
