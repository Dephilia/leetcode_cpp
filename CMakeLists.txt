cmake_minimum_required (VERSION 3.17)

# -- Project Information
# Proj info
set(proj_name "leetcode_cpp")
set(ver "0.1")
# Proj cpp ver
set(lang "CXX")
set(lang_ver "14")

project(${proj_name} VERSION ${ver} LANGUAGES ${lang})

# -- Compile Setting
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD ${lang_ver})
# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# -- Include
include_directories( include )

# -- Executable
add_executable(000_helloworld                          src/000_helloworld.cpp)
add_executable(037_sudoku_solver                       src/037_sudoku_solver.cpp)
add_executable(307_Range_Sum_Query_Mutable             src/307_Range_Sum_Query_Mutable.cpp)
add_executable(485_Max_Consecutive_Ones                src/485_Max_Consecutive_Ones.cpp)
add_executable(764_Largest_Plus_Sign                   src/764_Largest_Plus_Sign.cpp)
add_executable(850_Rectangle_Area_II                   src/850_Rectangle_Area_II.cpp)
add_executable(882_Reachable_Nodes_In_Subdivided_Graph src/882_Reachable_Nodes_In_Subdivided_Graph.cpp)
