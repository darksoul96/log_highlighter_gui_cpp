#include <stdio.h>
#include <iostream>
#include "LogWindow.hpp"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


void LogWindow::Create(const std::vector<ParsedTextColored>& parsedTextList, bool& wrapText, const bool useLightBackground) {
    
    unsigned int lineNumber = 1;
    static char searchBuffer[128] = "";
    static std::string previousSearch;
    static std::vector<const ParsedTextColored*> filteredList;

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_FirstUseEver);
    ImGui::Begin("Parsed Log");
    
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Text("FPS: %.1f | Frame: %.3f ms", io.Framerate, 1000.0f / io.Framerate);
    
    ImVec2 avail = ImGui::GetContentRegionAvail();


    if (useLightBackground) {
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(248, 248, 245, 255));
    }

    ImGui::Text("Search:");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(150);
    ImGui::InputText("##search", searchBuffer, IM_ARRAYSIZE(searchBuffer));
    ImGui::SameLine();
    ImGui::Checkbox("Wrap lines", &wrapText);

    

    bool searchExists = searchBuffer[0] != '\0';
    bool searchMatches = previousSearch == searchBuffer;


    if (!searchMatches) {
        previousSearch = searchBuffer;
        filteredList.clear();

        if (searchExists) {
            for (const auto& line : parsedTextList) {
                if (line.text.find(searchBuffer) != std::string::npos) {
                    filteredList.push_back(&line);
                }
            }
        }
    }
    
    ImGui::BeginChild("LogRegion", avail, true, ImGuiWindowFlags_HorizontalScrollbar);

    ImGuiListClipper clipper;

    if (searchExists) {
        clipper.Begin(static_cast<int>(filteredList.size()));

        while (clipper.Step()) {
            for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i) {
                const auto& line = filteredList[i];
                DrawLine(*line, wrapText, i);
            }
        }
    } else {
        clipper.Begin(static_cast<int>(parsedTextList.size()));
        while (clipper.Step()) {
            for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i) {
                const auto& line = parsedTextList[i];
                DrawLine(line, wrapText, i);
            }
        }
    }

    if (useLightBackground) {
        ImGui::PopStyleColor();
    }

    ImGui::EndChild();
}


void LogWindow::DrawLine(const ParsedTextColored& line, const bool& wrapText, const int& index) {
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 150, 150, 255));
    ImGui::Text("%5d", index + 1);
    ImGui::PopStyleColor();

    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Text, line.color);
    if (wrapText) {
        ImGui::TextWrapped("%s", line.text.c_str());
    } else {
        ImGui::TextUnformatted(line.text.c_str());
    }
    ImGui::PopStyleColor();
}