cmake_minimum_required(VERSION 3.6.0)
project(SearchEngTest)

add_executable(SearchEngTest test.cpp ${INC}/ConverterJSON.h ${SRC}/ConverterJSON.cpp ${INC}/InvertedIndex.h ${SRC}/InvertedIndex.cpp ${INC}/SearchServer.h ${SRC}/SearchServer.cpp)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

include_directories(${INC} ${SRC})

target_link_libraries(SearchEngTest PRIVATE gtest_main)
target_link_libraries(SearchEngTest PRIVATE nlohmann_json::nlohmann_json)

include(GoogleTest)
gtest_discover_tests(SearchEngTest)