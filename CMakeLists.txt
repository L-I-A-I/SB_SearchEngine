cmake_minimum_required(VERSION 3.6.0)
project(SearchEng)
project(SearchEngTest)

set(INC ${CMAKE_SOURCE_DIR}/include)
set(SRC ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(nlohmann_json)
add_subdirectory(test)