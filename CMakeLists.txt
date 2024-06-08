cmake_minimum_required(VERSION 3.6.0)
project(SB_Search_Engine)

set(INC ${CMAKE_SOURCE_DIR}/include)
set(SRC ${CMAKE_SOURCE_DIR}/src)

file(GLOB SRCS
${INC}/*
${SRC}/*
)
list(REMOVE_ITEM SRCS ${SRC}/main.cpp)

add_subdirectory(nlohmann_json)
add_subdirectory(src)
add_subdirectory(test)
