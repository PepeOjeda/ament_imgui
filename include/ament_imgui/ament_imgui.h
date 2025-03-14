#pragma once
#include <imgui.h>

struct GLFWwindow;

class AmentImgui
{
public:
    static void Setup(const char* ini_file_path = nullptr,
                      const char* window_title = "imgui_window",
                      float width = 550,
                      float height = 600,
                      ImGuiConfigFlags flags = ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable);
    static void Close();
    static void StartFrame();
    static void Render();

    static GLFWwindow* window;

    static constexpr ImGuiConfigFlags FlagsFixedLayout()
    {
        return ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    }

    static void SetNextWindowFullscreen()
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGui::SetNextWindowSize({io.DisplaySize.x, io.DisplaySize.y});
        ImGui::SetNextWindowPos(ImVec2(0, 0));
    }
};