#
# Created by Andrei - Doru Pata on 31/05/18.
#
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
if (Boost_FOUND)
    # Enable dynamic linking.
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREAD ON)

    set(SOURCE_FILES
        TestEntry.cpp
        DataTest.cpp ../../src/Data.cpp)

    #    set(HEADER_FILES xxx.hpp)

    set(HEADER_PERSIST_FILES ../../inc/Data.hpp)

    foreach (FILE ${HEADER_PERSIST_FILES})
        string(REPLACE ".hpp" "-odb.cpp" ODB_RESULT_FILE ${FILE})
        add_custom_command(
                OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${ODB_RESULT_FILE}
                COMMAND odb --database sqlite
                --hxx-suffix .hpp --ixx-suffix .ipp --cxx-suffix .cpp
                --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/
                --generate-query --generate-schema --schema-format embedded
                ${CMAKE_CURRENT_SOURCE_DIR}/${FILE}
                DEPENDS ${FILE}
                COMMENT "Building odb for ${FILE}"
        )
        list(APPEND SOURCE_FILES ${ODB_RESULT_FILE})
    endforeach ()

    add_executable(
            all_tests ${SOURCE_FILES} ${HEADER_FILES} ${HEADER_PERSIST_FILES})

    target_include_directories(all_tests
                               PUBLIC
                               /usr/include/odb
                               ${Boost_INCLUDE_DIR}
                               ${PROJECT_SOURCE_DIR}/inc
                               ${PROJECT_SOURCE_DIR}/test/inc)

    target_link_libraries(all_tests
                          libsqlite3.so
                          libodb.so
                          libodb-sqlite.so
                          ${Boost_LIBRARIES})

    include(CodeCoverage)
    APPEND_COVERAGE_COMPILER_FLAGS()
    set(COVERAGE_EXCLUDES
        '/usr/local/include/boost/*'
        '/usr/include/*'
        '${PROJECT_SOURCE_DIR}/test/*'
        '${PROJECT_SOURCE_DIR}/inc/*-odb.*pp')

    SETUP_TARGET_FOR_COVERAGE(NAME test_coverage
                              EXECUTABLE all_tests
                              DEPENDENCIES all_tests)
endif ()