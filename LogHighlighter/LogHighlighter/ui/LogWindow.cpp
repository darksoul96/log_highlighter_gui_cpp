#include <stdio.h>
#include "LogWindow.h"
#include "../imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <string>
#include <vector>


void LogWindow::Create(const LogInformation& log_information) {
    // Simple window
    ImGui::Begin(log_information.title.c_str());
    
    ImGui::BeginChild("LogRegion", ImVec2(0, 800), true, ImGuiWindowFlags_HorizontalScrollbar);
    // Loop through your log lines
    for (const auto& line : log_information.log_lines) {
        if (line.find("ERROR") != std::string::npos) {
            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 100, 100, 255)); // Red
            ImGui::TextUnformatted(line.c_str());
            ImGui::PopStyleColor();
        } else {
            ImGui::TextUnformatted(line.c_str());
        }
    }
    ImGui::EndChild();
}


