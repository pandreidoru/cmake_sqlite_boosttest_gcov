#
# Created by Andrei - Doru Pata on 31/05/18.
#
set(SOURCE_FILES
    main.cpp
    Data.cpp)

#    set(HEADER_FILES xxx.hpp)

set(HEADER_PERSIST_FILES ../inc/Data.hpp)

foreach (FILE ${HEADER_PERSIST_FILES})
    string(REPLACE ".hpp" "-odb.cpp" ODB_RESULT_FILE ${FILE})
    add_custom_command(
            OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${ODB_RESULT_FILE}
            COMMAND odb --database sqlite
            --hxx-suffix .hpp --ixx-suffix .ipp --cxx-suffix .cpp
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../inc/
            --generate-query --generate-schema --schema-format embedded
            ${CMAKE_CURRENT_SOURCE_DIR}/${FILE}
            DEPENDS ${FILE}
            COMMENT "Building odb for ${FILE}"
    )
    list(APPEND SOURCE_FILES ${ODB_RESULT_FILE})
endforeach ()

add_executable(
        ${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${HEADER_PERSIST_FILES})

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           /usr/include/odb
                           ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(${PROJECT_NAME}
                      libsqlite3.so
                      libodb.so
                      libodb-sqlite.so)