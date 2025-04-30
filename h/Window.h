#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Window
{
    public:
    Window(int width, int height, const std::string title);
    ~Window();

    bool Initialize();
    void Update();
    //void Clear();

    void PollEvents();
    bool ShouldClose() const;

    GLFWwindow* GetWindow() const;
    int GetWidth() const;
    int GetHeight() const;
    bool IsKeyPressed(int key) const;
    void GetMousePosition(double& x, double& y) const;

    void SwapBuffers();

    private:
    GLFWwindow* m_pWindow;
    int m_width, m_height;
    std::string m_title;

    bool m_isInitialized;

};