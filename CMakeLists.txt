cmake_minimum_required(VERSION 3.17)
project(Dragon3D)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES Dragon3DLight.cpp Sources/Camera.cpp Headers/Camera.h Sources/Quaternion.cpp Headers/Quaternion.h Sources/ObjLoader.cpp Headers/ObjLoader.h)

include_directories(${PROJECT_SOURCE_DIR}/GLFW/include ${PROJECT_SOURCE_DIR}/glew/include ${PROJECT_SOURCE_DIR}/Headers/glm)

link_directories(${PROJECT_SOURCE_DIR}/GLFW/lib ${PROJECT_SOURCE_DIR}/glew/lib ${PROJECT_SOURCE_DIR}/Headers/glm)

add_executable(Dragon3D ${SOURCE_FILES})

target_link_libraries(Dragon3D opengl32 glew32 glfw3)