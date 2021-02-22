# Ideally you want to require the lowest CMake version possible for your
# project. But you have to test that manually, so just go with what you are
# currently using and adjust as you go.
cmake_minimum_required(VERSION 3.16)

# The name of the core library is used as project name.
project(rpg)

# This allows us to include CMake modules located in `./cmake`.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Note that we do not set *any* global properties here!

# A dedicated function is used for setting common compile flags and properties.
include(compile_flags)

# SFML
if(MSVC)
    set(SFML_DIR ${CMAKE_CURRENT_LIST_DIR}/vendor/SFML/lib/cmake/SFML)
endif()

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS graphics audio network)

# RPG Library
file(GLOB_RECURSE src_files src/*.cpp)
add_library(rpg_lib ${src_files})
mylib_cxx_flags(rpg_lib)
target_include_directories(rpg_lib PUBLIC include)
target_link_libraries(rpg_lib PUBLIC sfml-graphics sfml-audio sfml-network)
target_precompile_headers(rpg_lib PUBLIC include/mylib/stdafx.hpp)

# Executable
add_executable(rpg_exec apps/myapp.cpp)
mylib_cxx_flags(rpg_exec)
set_target_properties(rpg_exec PROPERTIES OUTPUT_NAME myapp)
target_link_libraries(rpg_exec PRIVATE rpg_lib)
set_target_properties(rpg_exec PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
