#include "App.hpp"
#include <iostream>
#include "imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

constexpr ImVec4 g_clearColor = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);


bool App::Initialize(int argc, char** argv) {
    
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <path-to-log-file> <path-to-rule-file>" << std::endl;
        return false;
    }
    
    
    std::string filepath = argv[1];
    std::string rulesFilepath = argv[2];
    size_t logFilesize =  FileManagement::CountFileLines(filepath);
    
    this->m_logInformation.title = "Log";
    this->m_logInformation.logLines.reserve(logFilesize);
    
    FileManagement::ReadFile(filepath, this->m_logInformation.logLines);
    this->m_highlightRules = FileManagement::LoadLineRules(rulesFilepath);
    
    return true;
}

void App::InitWindow() {
    glfwInit();
    
    // Force OpenGL 3.2 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Optional but useful:
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    m_Window = glfwCreateWindow(1280, 720, "Log Highlighter", nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    // Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 150");
}

void App::RenderFrame() {
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(m_Window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(g_clearColor.x, g_clearColor.y, g_clearColor.z, g_clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


void App::Cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void App::Run() {
    InitWindow();
    
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
        
        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
       
        //Call Log Window Rendering
        m_LogWindow.Create(this->m_logInformation, this->m_highlightRules);
        
        ImGui::End();

        RenderFrame();
        glfwSwapBuffers(m_Window);
    }
    
    Cleanup();
}
