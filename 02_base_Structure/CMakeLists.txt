cmake_minimum_required(VERSION 3.16)
project(HelloTriangleApp LANGUAGES CXX)
add_executable(HelloTriangleApp src/main.cpp src/HelloTriangleApp.cpp)
target_link_libraries(HelloTriangleApp PRIVATE  glfw vulkan dl pthread X11 Xxf86vm Xrandr Xi )