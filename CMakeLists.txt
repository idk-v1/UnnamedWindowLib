cmake_minimum_required(VERSION 3.16)
project(UnnamedWindowLib C)

set(CMAKE_C_STANDARD 11)

message(STATUS "Configuring UnnamedWindowLib")

# Header-only library
# Save project root as a variable (this is the correct source dir)
set(UNNAMEDWINDOWLIB_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

add_library(UnnamedWindowLib INTERFACE)

# For Later when you have sourcs
#
# add_library(UnnamedWindowLib
#     idk/src/foo.c
#     idk/src/bar.c
# )
#
#
target_include_directories(UnnamedWindowLib INTERFACE
        $<BUILD_INTERFACE:${UNNAMEDWINDOWLIB_ROOT_DIR}/idk/include>
        $<INSTALL_INTERFACE:include>
)

# use main.c as a test
add_executable(UnnamedWindowLibTest
        main.c
)

# Link test executable to the header-only library
target_link_libraries(UnnamedWindowLibTest PRIVATE UnnamedWindowLib)
