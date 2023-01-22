# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Benchmark")

# Include sub-projects.
add_subdirectory ("Benchmark")
add_subdirectory ("containers")
add_subdirectory ("Threads")
