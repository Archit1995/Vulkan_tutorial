#include<vulkan/vulkan.h>
#include<iostream>
#include<stdexcept>
#include<cstdlib>

class HelloTriangeApp{
    public:
        void run(){
            initVulkan();
            mainLoop();
            cleanup();
        }
    private:
        void initVulkan(){

        }
        void mainLoop(){

        }
        void cleanup(){
            
        }

};
int main(){
    HelloTriangeApp app;
    try{
        app.run();

    }catch(const std::exception& e){
        std::cerr<<e.what()<<"\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
