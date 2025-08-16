cmake_minimum_required(VERSION 3.16)
project(VulkanWindow LANGUAGES CXX)
add_executable(vulkan_window src/main.cpp)#where vulkan_window is the name of the target object file. g++ main.cpp -o 
target_link_libraries(vulkan_window PRIVATE  glfw vulkan dl pthread X11 Xxf86vm Xrandr Xi )

