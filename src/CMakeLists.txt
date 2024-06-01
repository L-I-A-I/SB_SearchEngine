cmake_minimum_required(VERSION 3.6.0)

#[[
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
]]

add_executable(SearchEng main.cpp ${INC}/ConverterJSON.h ConverterJSON.cpp ${INC}/InvertedIndex.h InvertedIndex.cpp ${INC}/SearchServer.h SearchServer.cpp )

target_include_directories(SearchEng PUBLIC ${INC})

#target_link_libraries(SearchEng PRIVATE gtest_main)
target_link_libraries(SearchEng PRIVATE nlohmann_json::nlohmann_json)

#[[
enable_testing()
include(GoogleTest)
gtest_discover_tests(SearchEng)
add_test(NAME example_test COMMAND example)
]]