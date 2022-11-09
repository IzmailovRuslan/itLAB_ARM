cmake_minimum_required(VERSION 3.0.0)

project(test_example)

add_executable(test_example main.cpp source/func.cpp source/func.hpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  target_link_libraries(test_example PUBLIC OpenMP::OpenMP_CXX)
endif()
