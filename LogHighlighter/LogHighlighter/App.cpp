#include "App.h"
#include "imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

constexpr ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);

void App::Init() {
    glfwInit();
    
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
    ImGui_ImplOpenGL3_Init("#version 120");
}

void App::RenderFrame() {
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(m_Window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
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


void App::Run(const LogInformation& log_information) {
    Init();
    
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
        
        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
       
        //Call Log Window Rendering
        m_LogWindow.Create(log_information);
        
        ImGui::End();

        RenderFrame();
        glfwSwapBuffers(m_Window);
    }
    
    Cleanup();
}
