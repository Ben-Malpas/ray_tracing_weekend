# Add source files
set(HEADER_FILES
	camera.hpp
	colour.hpp
	hittable.hpp
	hittable_list.hpp
	interval.hpp
	ray.hpp
	ray_tracing_weekend.hpp
	sphere.hpp
	vec3.hpp
)

set(SOURCE_FILES
	ray_tracing_weekend.cpp
)

# Add source to this project's executable.
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
