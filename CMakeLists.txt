cmake_minimum_required(VERSION 3.16)
project(UnnamedWindowLib C)

set(CMAKE_C_STANDARD 11)

# Header-only library
add_library(UnnamedWindowLib INTERFACE)

# For Later when you have sourcs
#
# add_library(UnnamedWindowLib
#     idk/src/foo.c
#     idk/src/bar.c
# )
#
#


# Public headers location
target_include_directories(UnnamedWindowLib INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/idk/include
)

# use main.c as a test
add_executable(UnnamedWindowLibTest
        main.c
)

# Link test executable to the header-only library
target_link_libraries(UnnamedWindowLibTest PRIVATE UnnamedWindowLib)
