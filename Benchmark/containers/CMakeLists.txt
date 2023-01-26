# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
project ("containers")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# Add source to this project's executable.
add_executable (containers "parse_main.cpp" "tuple1.cpp")

