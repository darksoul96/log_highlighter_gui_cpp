#include <stdio.h>
#include <iostream>
#include "LogWindow.hpp"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


void LogWindow::Create(const LogInformation& logInformation, const std::vector<HighlightRule>& highlightRules) {
    
    unsigned int lineNumber = 1;
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_FirstUseEver);
    ImGui::Begin(logInformation.title.c_str());
    
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Text("FPS: %.1f | Frame: %.3f ms", io.Framerate, 1000.0f / io.Framerate);
    
    ImVec2 avail = ImGui::GetContentRegionAvail();
    ImGui::BeginChild("LogRegion", avail, true, ImGuiWindowFlags_HorizontalScrollbar);
    
    for (const auto& line : logInformation.logLines) {
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 150, 150, 255));
        ImGui::Text("%5d", lineNumber++);
        ImGui::PopStyleColor();
        ImGui::SameLine();
        
        bool matched = false;
        
        for (const auto& rule : highlightRules) {
            if (line.find(rule.PatternRule) != std::string::npos) {
                ImGui::PushStyleColor(ImGuiCol_Text, rule.ColorRule);
                ImGui::TextUnformatted(line.c_str());
                ImGui::PopStyleColor();
                matched = true;
                break;
            }
        }
        
        if (!matched) {
            ImGui::TextUnformatted(line.c_str());
        }
    }
    ImGui::EndChild();
}


