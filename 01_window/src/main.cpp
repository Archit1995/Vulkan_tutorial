#define GLFW_INCLUDE_VULKAN

#include<GLFW/glfw3.h>//Create widowing context using Graphics library framework- takes care of UI (keyboard,mouse,joystick etc.)

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include<glm/vec4.hpp>
#include<glm/mat4x4.hpp>

#include<iostream>
#include<vector>

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);// GLFW defaults to OpenGL. GLFW_NO_API tells glfw not to default to OpenGL context.   
    GLFWwindow *window=glfwCreateWindow(800,600,"Vulkan Window",nullptr,nullptr);

    uint32_t Count=0;
    // Vulkan instance created. 
    std::vector<VkExtensionProperties> extensions(Count);

    vkEnumerateInstanceExtensionProperties(nullptr,&Count,extensions.data());

    for(const auto& ext: extensions){
        std::cout<<ext.extensionName<< "is a supported extension \n";
    }
    std::cout<<Count<<" extensions supported\n";    
    glm::mat4 m;
    glm::vec4 v;
    auto test=m*v;
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;



}

