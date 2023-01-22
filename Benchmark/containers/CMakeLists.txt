# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("containers")

# Add source to this project's executable.
add_executable (containers "tuple1.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET containers PROPERTY CXX_STANDARD 20)
endif()
