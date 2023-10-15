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
  src/RenderingEngine.cpp
  # src/AssetManager.cpp
  src/InputManager.cpp  
  src/AudioManager.cpp
)

# Find packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED NO_MODULE)
find_package(OpenAL REQUIRED)
# FreeALUT is deprecated, but it's the only way to get ALUT on Linux
# find_package(FreeALUT REQUIRED)

# Include directories
target_include_directories(BombasticEngine PUBLIC 
  "${PROJECT_BINARY_DIR}" 
  "${PROJECT_SOURCE_DIR}/include"
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS}
  ${OPENAL_INCLUDE_DIR}
  /usr/include/AL
)

# Link libraries
target_link_libraries(BombasticEngine 
  ${SDL2_LIBRARIES} 
  SDL2_image
  ${OPENAL_LIBRARY} 
  # ${ALUT_LIBRARIES}
  alut
) 
