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
file( GLOB EXES src/*.cpp )
foreach( srcpath ${EXES} )
    get_filename_component(exename ${srcpath} NAME_WE)
    add_executable( ${exename} ${srcpath} )
    # target_link_libraries( ${srcpath} Lib )
endforeach( srcpath ${EXES} )
