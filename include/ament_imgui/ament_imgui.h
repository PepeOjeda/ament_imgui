#pragma once
#include <imgui.h>

struct GLFWwindow;

class AMENT_IMGUI{
    public:
        static void setup(const char* ini_file_path = nullptr);
        static void close();
        static void StartFrame();
        static void Render();
    
        static GLFWwindow* window;
};