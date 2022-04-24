

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(bookShop VERSION 1.0)


add_library(mylib STATIC 
src/bookshop.cpp
)

target_include_directories(
    mylib
PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(bookShop
 #bs_test.cpp 
 test_mini.cpp) # to run manualy use bs_main.cpp



#add_executable(runTests test_mini.cpp)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


target_link_libraries(bookShop PUBLIC 
mylib
gtest
gtest_main
${GTEST_LIBRARIES} pthread)
#add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
