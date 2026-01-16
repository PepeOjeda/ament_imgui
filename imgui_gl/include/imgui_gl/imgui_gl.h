#pragma once
#include <imgui.h>
#include <string>

struct GLFWwindow;

class ImguiGL
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

    static constexpr ImGuiConfigFlags FlagsFixedLayout()
    {
        return ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    }

    static void SetNextWindowFullscreen()
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGui::SetNextWindowSize({io.DisplaySize.x, io.DisplaySize.y});

        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowViewport(main_viewport->ID);
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y));
    }

    static bool ShouldClose();

public:
    static inline GLFWwindow* window;
    static inline ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

private:
    static inline std::string window_title_str;
    static inline std::string filepath;
};