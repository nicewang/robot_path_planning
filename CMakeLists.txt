cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ 11 standard
set(CMAKE_CXX_STANDARD 11)

# Add subdirectories and compile separately
add_subdirectory(monte_carlo_tree_search)
add_subdirectory(rapidly_exploring_random_tree)

# Clean all
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
)
