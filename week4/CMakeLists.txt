

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(CompareShape VERSION 1.0)


#file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(CompareShape
    main.cpp
    src/area_perimeter.cpp
#    src/compare_shapes.cpp
#    ${SRC_FILES}
    )

target_include_directories(CompareShape
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)



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
