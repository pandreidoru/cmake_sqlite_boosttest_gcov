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
  
  BOOST_AUTO_TEST_CASE(DataTest) {
    
    auto db = std::make_shared<odb::sqlite::database>("data.db",
                                                      SQLITE_OPEN_READWRITE
                                                      | SQLITE_OPEN_CREATE);
    
    {
      unsigned long data_id_1 = 1;
      unsigned long data_id_2 = 2;
      auto data_1 = persist::Data{ data_id_1, "member 1", "member 2" };
      auto data_2 = persist::Data{ data_id_2, "member 1", "member 2" };
      
      transaction t(db->begin());
      schema_catalog::create_schema(*db);
      
      BOOST_TEST(db->persist(data_1) == data_id_1);
      BOOST_TEST(db->persist(data_2) == data_id_2);
      
      t.commit();
    }
  }

BOOST_AUTO_TEST_SUITE_END()
