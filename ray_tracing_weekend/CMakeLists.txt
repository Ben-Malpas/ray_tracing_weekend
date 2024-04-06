# CMakeList.txt : CMake project for ray_tracing_weekend, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ray_tracing_weekend "ray_tracing_weekend.cpp" "ray_tracing_weekend.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ray_tracing_weekend PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
