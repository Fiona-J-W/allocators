project(Printing-Allocator)

# to shut up cmake, I have no clue what version this needs:
cmake_minimum_required(VERSION 2.8)


# create sane environment
#####################################################################

# Sadly, this doesn't seem to work:
#set_property(GLOBAL PROPERTY CXX_STANDARD 11)
#set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

# Ok, so let's just hardcode all the flags instead:
# TODO: make this portable
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++14" )

# targets
#####################################################################

include_directories("include")

file(GLOB library_headers "include/pa/*.hpp")
file(GLOB demo_file "src/demo/main.cpp")

add_executable(demo ${demo_file})
