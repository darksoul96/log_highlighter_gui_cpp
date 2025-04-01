#include <stdio.h>
#include "LogWindow.h"
#include "../imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <string>
#include <vector>


constexpr const char* ERROR_LINE = "ERROR";
constexpr const char* WARN_LINE = "WARN";
constexpr const char* DEBUG_LINE = "DEBUG";
constexpr const char* INFO_LINE = "INFO";
constexpr const char* STACK_LINE_1 = "java:";
constexpr const char* STACK_LINE_2 = "Native Method";

constexpr ImU32 ERROR_COLOR = IM_COL32(230, 57, 70, 255);
constexpr ImU32 WARN_COLOR = IM_COL32(244, 162, 97, 255);
constexpr ImU32 DEBUG_COLOR = IM_COL32(127, 140, 141, 255);
constexpr ImU32 INFO_COLOR = IM_COL32(74, 144, 226, 255);
constexpr ImU32 STACK_COLOR = IM_COL32(233, 196, 106, 255);


void LogWindow::Create(const LogInformation& log_information) {
    // Simple window
    ImGui::Begin(log_information.title.c_str());
    
    ImGui::BeginChild("LogRegion", ImVec2(0, 0), true, ImGuiWindowFlags_HorizontalScrollbar);
    // Loop through your log lines
    for (const auto& line : log_information.log_lines) {
        if (line.find(ERROR_LINE) != std::string::npos) {
            ImGui::PushStyleColor(ImGuiCol_Text, ERROR_COLOR);
            ImGui::TextUnformatted(line.c_str());
            ImGui::PopStyleColor();
        } else if (line.find(WARN_LINE) != std::string::npos) {
            ImGui::PushStyleColor(ImGuiCol_Text, WARN_COLOR);
            ImGui::TextUnformatted(line.c_str());
            ImGui::PopStyleColor();
        } else if (line.find(DEBUG_LINE) != std::string::npos) {
            ImGui::PushStyleColor(ImGuiCol_Text, DEBUG_COLOR);
            ImGui::TextUnformatted(line.c_str());
            ImGui::PopStyleColor();
        } else if (line.find(INFO_LINE) != std::string::npos) {
            ImGui::PushStyleColor(ImGuiCol_Text, INFO_COLOR);
            ImGui::TextUnformatted(line.c_str());
            ImGui::PopStyleColor();
        } else if (line.find(STACK_LINE_1) != std::string::npos || line.find(STACK_LINE_2) != std::string::npos) {
            ImGui::PushStyleColor(ImGuiCol_Text, STACK_COLOR);
            ImGui::TextUnformatted(line.c_str());
            ImGui::PopStyleColor();
        } else {
            ImGui::TextUnformatted(line.c_str());
        }
    }
    ImGui::EndChild();
}


