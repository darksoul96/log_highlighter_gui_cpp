#include <stdio.h>
#include "LogWindow.h"
#include "../imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <string>




void LogWindow::Create() {
    // Simple window
    ImGui::Begin("LogHighlighter");
    
    
    ImGui::BeginChild("LogRegion", ImVec2(0, 300), true, ImGuiWindowFlags_HorizontalScrollbar);
    std::string log_lines[] = {"log line 1", "log line 2"};
    // Loop through your log lines
    for (const auto& line : log_lines) {
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


