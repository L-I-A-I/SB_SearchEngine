cmake_minimum_required(VERSION 3.6.0)

add_executable(SearchEng main.cpp ${INC}/ConverterJSON.h ConverterJSON.cpp ${INC}/InvertedIndex.h InvertedIndex.cpp ${INC}/SearchServer.h SearchServer.cpp)

target_include_directories(SearchEng PUBLIC ${INC})

target_link_libraries(SearchEng PRIVATE nlohmann_json::nlohmann_json)