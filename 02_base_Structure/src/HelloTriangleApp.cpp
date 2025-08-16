
#include "HelloTriangleApp.h"

    void HelloTriangleApp::run(){
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
    VkInstance instance;//data member to hold the handle to the instance:
    GLFWwindow* window= nullptr;
    const VkAllocationCallbacks *pAllocator=nullptr;
    void HelloTriangleApp:: initWindow(){
        // Step1 initialize glfw. NOTE functions are lower case glfw
        glfwInit();
        // General sturcture of glfwWindowHint(QUESTION,ANSWER), where QUESTION and ANSWER are macros. Code things like this if you want to implement choices.
        glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
        // where QUESTION = GLFW_CLIENT_API → "Which graphics API do you want?" and 
        // ANSWER = GLFW_NO_API → "None, I’ll handle it myself." since GLFW by default asssumes OpenGL
        
        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);//QUESTION: Do you want the window to be resizable. ANSWER: No
        
        // Initialize parameters for window creation
        const uint32_t WIDTH=800;
        const uint32_t HEIGHT=600;
        // std::string window_name="Vulkan";
        const char* window_name = "Vulkan";
        GLFWmonitor *monitor=nullptr;
        GLFWwindow *share=nullptr;

        // Create Window
        window= glfwCreateWindow(WIDTH,HEIGHT,window_name,monitor,share);

    }
    void HelloTriangleApp:: initVulkan(){
        /* initialize the Vulkan library by creating an instance. The instance is the connection between 
        your application and the Vulkan library and creating it involves specifying some details about 
        your application to the driver.*/
        createInstance();
    }
    /*A lot of information in Vulkan is passed through structs instead of function parameters and we'll
     have to fill in one more struct to provide sufficient information for creating an instance. */
    void HelloTriangleApp:: createInstance(){

        VkApplicationInfo appInfo{};
        appInfo.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName="Hello Triangle";
        int major=0;
        int minor=0;
        int patch=0;
        appInfo.applicationVersion=VK_MAKE_VERSION(major,minor,patch);
        appInfo.pEngineName="No Engine";
        appInfo.engineVersion=VK_MAKE_VERSION(major,minor,patch);
        appInfo.apiVersion=VK_API_VERSION_1_0;

        uint32_t extensionCount=0;
        const char *pLayerName=nullptr;
        uint32_t *pPropertyCount=&extensionCount;
        vkEnumerateInstanceExtensionProperties(pLayerName,pPropertyCount,nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        VkExtensionProperties *pProperties=extensions.data();
        vkEnumerateInstanceExtensionProperties(pLayerName,pPropertyCount,pProperties);
        std::cout <<extensionCount<<" available extensions:\n";
        for (const auto& ext : extensions) {
            std::cout << "\t" << ext.extensionName << "\n";
        }


        /* This struct tells the Vulkan driver which global extensions and validation layers we want to use. */

        VkInstanceCreateInfo createInfo{};
        createInfo.sType=VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo=&appInfo;

        /*The next 2 layers tells the Vulkan driver which global extensions and validation layers we want to use. */

        uint32_t glfwExtensionCount=0;
        const char** glfwExtensions;
        glfwExtensions=glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        createInfo.enabledExtensionCount=glfwExtensionCount;
        createInfo.ppEnabledExtensionNames=glfwExtensions;

        // Global validation layer are empty for now.
        createInfo.enabledLayerCount=0;

        const VkInstanceCreateInfo *pCreateInfo=&createInfo;
        
        VkInstance *pInstance= &instance;
        VkResult result=vkCreateInstance(pCreateInfo,pAllocator,pInstance);

        if(result!=VK_SUCCESS){
            throw std::runtime_error("failed to create instance!");
        }
        }
        void HelloTriangleApp:: mainLoop(){
            while(!glfwWindowShouldClose(window)){
                glfwPollEvents();//Event processing functions, keeps track of clicks, key press etc. 
            }
        }

    void HelloTriangleApp:: cleanup(){
        vkDestroyInstance(instance,pAllocator);
        glfwDestroyWindow(window);
        glfwTerminate();
    }
