// Adding headers
#pragma once
#define GLFW_INCLUDE_VULKAN //defining a macro
#include <GLFW/glfw3.h>

#include<iostream>
#include<stdexcept>
#include<cstdlib>
#include<vector>
// #ifndef HELLOTRIANGLEAPP_H
// #define HELLOTRIANGLEAPP_H
// #endif 


class HelloTriangleApp{
    public:
        void run();
    private:
        VkInstance instance;
        GLFWwindow *window;
        const VkAllocationCallbacks *pAllocator;
        void initWindow();
        void initVulkan();
        void createInstance();
        void mainLoop();
        void cleanup();
};