cmake_minimum_required(VERSION 4.0.0 FATAL_ERROR)

project(minlang VERSION 0.0.1 DESCRIPTION "a miniture language similar to BASIC")

set(SOURCES)

file(GLOB_RECURSE SOURCES
     "src/*.cpp"
     "src/*.h"
)

add_executable(minlang ${SOURCES})