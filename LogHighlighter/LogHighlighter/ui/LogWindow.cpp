#include <stdio.h>
#include <iostream>
#include "LogWindow.hpp"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


void LogWindow::Create(const std::vector<ParsedTextColored>& parsedTextList) {
    
    unsigned int lineNumber = 1;
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_FirstUseEver);
    ImGui::Begin("Parsed Log");
    
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Text("FPS: %.1f | Frame: %.3f ms", io.Framerate, 1000.0f / io.Framerate);
    
    ImVec2 avail = ImGui::GetContentRegionAvail();
    ImGui::BeginChild("LogRegion", avail, true, ImGuiWindowFlags_HorizontalScrollbar);
    

    ImGuiListClipper clipper;
    clipper.Begin(static_cast<int>(parsedTextList.size()));

    while (clipper.Step()) {
        for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i) {
            const auto& line = parsedTextList[i];

            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 150, 150, 255));
            ImGui::Text("%5d", i + 1);
            ImGui::PopStyleColor();

            ImGui::SameLine();

            ImGui::PushStyleColor(ImGuiCol_Text, line.color);
            ImGui::TextUnformatted(line.text.c_str());
            ImGui::PopStyleColor();
        }
    }

    ImGui::EndChild();
}


