

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
    bs_test.cpp) # to run test replace bs_main.cpp with bs_test.cpp

target_link_libraries(bookShop 
PUBLIC 
    mylib)