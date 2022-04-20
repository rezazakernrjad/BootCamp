

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(shape VERSION 1.0)


add_library(mylib STATIC 
main.cpp
src/area_perimeter.cpp
src/compare_shapes.cpp
)

target_include_directories(
    mylib
PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(shape
    main.cpp)
target_link_libraries(shape 
PUBLIC 
    mylib)


message(STATUS "---------------------***********Debug CMakeList************--------------------------")

message(STATUS "All include directories")

get_property(dirs TARGET ${PROJECT_NAME} PROPERTY INCLUDE_DIRECTORIES)

foreach(dir ${dirs})

    message(STATUS "dir='${dir}'")

endforeach()

message(STATUS "-----------------------------------------------------------------------")

# =============================================================================

# Debugger help

# Prints all available variables in the system at the momement.

# I.e available for the script right now

macro(print_all_variables)

    message(STATUS "print_all_variables------------------------------------------{")

    get_cmake_property(_variableNames VARIABLES)

    foreach (_variableName ${_variableNames})

        message(STATUS "${_variableName}=${${_variableName}}")

    endforeach()

    message(STATUS "print_all_variables------------------------------------------}")

endmacro()



print_all_variables()

# End debugger help
