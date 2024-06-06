cmake_minimum_required(VERSION 3.6.0)
project(SearchEng)

include_directories(${INC})

add_executable(SearchEng main.cpp ${SRCS})

target_link_libraries(SearchEng PRIVATE nlohmann_json::nlohmann_json)