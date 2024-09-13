cmake_minimum_required(VERSION 3.13.3 FATAL_ERROR)

if (APPLE)
project(OSLib C CXX OBJC OBJCXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
else()
project(OSLib C CXX)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
endif()

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")

add_library(OSLib STATIC)
target_include_directories(OSLib PUBLIC src)

if (APPLE)
file(GLOB_RECURSE appleSources CONFIGURE_DEPENDS "src/*.mm")
target_sources(OSLib PRIVATE ${appleSources} ${sources})
else()
target_sources(OSLib PRIVATE ${sources})
endif()

target_precompile_headers(OSLib PUBLIC src/ospch.hpp)

if (NOT WIN32)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

if (WIN32)

elseif(APPLE)

endif()