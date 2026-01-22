#pragma once
#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"

namespace ImGui
{
    class ScopedStyle
    {
    public:
        ScopedStyle(ImGuiCol_ key, ImU32 color)
        {
            type = Color;
            ImGui::PushStyleColor(key, color);
        }

        ScopedStyle(ImGuiStyleVar_ key, ImU32 color)
        {
            type = Color;
            ImGui::PushStyleVar(key, color);
        }

        ~ScopedStyle()
        {
            if (type == Color)
                ImGui::PopStyleColor();
            else if (type == Var)
                ImGui::PopStyleVar();
            else
                fprintf(stderr, "Incorrect ScopedStyle type!");
        }

    private:
        enum Type
        {
            None,
            Color,
            Var
        };
        Type type;
    };

    inline void TextCenteredOnLine(const char* label, float alignment = 0.5f)
    {
        ImGuiStyle& style = ImGui::GetStyle();

        float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
        float avail = ImGui::GetContentRegionAvail().x;

        float off = (avail - size) * alignment;
        if (off > 0.0f)
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

        ImGui::Text("%s", label);
    }

    inline bool ButtonCenteredOnLine(const char* label, float alignment = 0.5f)
    {
        ImGuiStyle& style = ImGui::GetStyle();

        float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
        float avail = ImGui::GetContentRegionAvail().x;

        float off = (avail - size) * alignment;
        if (off > 0.0f)
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

        return ImGui::Button(label);
    }

    inline void HorizontalSpace(float space)
    {
        ImGui::Dummy(ImVec2(space, 0.f));
        ImGui::SameLine();
    }

    inline void VerticalSpace(float space)
    {
        ImGui::Dummy(ImVec2(0.f, space));
    }

    // set viewport to prevent the tooltip from becoming its own window
    inline void HelpMarker(const char* desc, float hsize = 35.f, bool canLeaveViewport = false)
    {
        ImGui::TextDisabled("(?)");
        if (IsItemHovered(ImGuiHoveredFlags_ForTooltip))
        {
            if (!canLeaveViewport)
                ImGui::SetNextWindowViewport(ImGui::GetWindowViewport()->ID);
            ImGui::BeginItemTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * hsize);
            ImGui::TextUnformatted(desc);
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }

#define CalculateSize(result, ...)                                                              \
    {                                                                                           \
        ImGui::BeginDisabled(true);                                                             \
        ImVec2 cursorPos = ImGui::GetCursorPos();                                               \
        float alpha = ImGui::GetStyle().Alpha;                                                  \
                                                                                                \
        /*draw everything with 0 alpha to calculate the size that the child frame should have*/ \
        ImGui::GetStyle().Alpha = 0;                                                            \
        ImGui::BeginGroup();                                                                    \
        __VA_ARGS__;                                                                            \
        ImGui::EndGroup();                                                                      \
        result = ImGui::GetItemRectSize();                                                      \
        ImGui::GetStyle().Alpha = alpha;                                                        \
        ImGui::SetCursorPos(cursorPos);                                                         \
        ImGui::EndDisabled();                                                                   \
    }

#define DrawInChild(childID, ...)           \
    {                                       \
        ImVec2 offset;                      \
        CalculateSize(offset, __VA_ARGS__); \
                                            \
        /*actually draw the stuff*/         \
        ImGui::BeginChild(childID, offset); \
        __VA_ARGS__;                        \
        ImGui::EndChild();                  \
    }

#define DrawInChildSpanHorizontal(childID, ...)          \
    {                                                    \
        ImVec2 offset;                                   \
        CalculateSize(offset, __VA_ARGS__);              \
        float height = offset.y;                         \
                                                         \
        /*actually draw the stuff*/                      \
        ImGui::BeginChild(childID, ImVec2(0.f, height)); \
        __VA_ARGS__;                                     \
        ImGui::EndChild();                               \
    }

} // namespace ImGui