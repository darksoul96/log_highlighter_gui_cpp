#include <stdio.h>
#include "LogWindow.hpp"
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


void LogWindow::Create(const LogInformation& logInformation) {
    uint lineNumber = 1;
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_FirstUseEver);
    ImGui::Begin(logInformation.title.c_str());
    ImVec2 avail = ImGui::GetContentRegionAvail();
    ImGui::BeginChild("LogRegion", avail, true, ImGuiWindowFlags_HorizontalScrollbar);
    for (const auto& line : logInformation.logLines) {
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 150, 150, 255));
        ImGui::Text("%5d", lineNumber++);
        ImGui::PopStyleColor();
        ImGui::SameLine();
        
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


