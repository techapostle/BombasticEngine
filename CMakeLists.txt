cmake_minimum_required(VERSION 3.10)

# set the project name
project(BombastEngine)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(
  BombasticEngine
  src/main.cpp
  src/GameEngine.cpp
  # src/RenderingEngine.cpp
  src/InputManager.cpp  
)

# Find packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Include directories
target_include_directories(BombasticEngine PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include")
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# If we have libraries to link, use target_link_libraries
# target_link_libraries(BombasticEngine name_of_library)
target_link_libraries(BombasticEngine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
