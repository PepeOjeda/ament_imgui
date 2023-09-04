#pragma once
#include <imgui.h>

struct GLFWwindow;

class AMENT_IMGUI
{
public:
    static void setup(const char* ini_file_path = nullptr, const char* window_title = "imgui_window", float width = 550, float height = 600);
    static void close();
    static void StartFrame();
    static void Render();

    static GLFWwindow* window;
};