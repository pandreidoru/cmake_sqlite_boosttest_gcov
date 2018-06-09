#
# Created by Andrei - Doru Pata on 31/05/18.
#
cmake_minimum_required(VERSION 3.11)
project(cpp_persist)

set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

include(EnableExtraCompilerWarnings)
globally_enable_extra_compiler_warnings()

add_subdirectory(src)
add_subdirectory(test/src)