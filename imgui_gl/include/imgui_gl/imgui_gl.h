#pragma once
#include <imgui.h>
#include <string>

struct GLFWwindow;

class ImguiGL
{
public:
    void Setup(const char* ini_file_path = nullptr,
               const char* window_title = "imgui_window",
               float width = 550,
               float height = 600,
               ImGuiConfigFlags flags = ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable);
    void Close();
    void StartFrame();
    void Render();

    constexpr ImGuiConfigFlags FlagsFixedLayout()
    {
        return ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    }

    void SetNextWindowFullscreen()
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGui::SetNextWindowSize({io.DisplaySize.x, io.DisplaySize.y});

        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowViewport(main_viewport->ID);
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y));
    }

    bool ShouldClose();

public:
    GLFWwindow* window;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

private:
    std::string window_title_str;
    std::string filepath;
};