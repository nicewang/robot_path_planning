cmake_minimum_required(VERSION 3.10)
project(robot_path_planning)

# Set C++ 11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories and compile separately
add_subdirectory(astar)
add_subdirectory(monte_carlo_tree_search)
add_subdirectory(rapidly_exploring_random_tree)

# Clean all
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
)
