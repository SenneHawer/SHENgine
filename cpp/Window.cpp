#include "Window.h"

Window::Window(int width, int height, const std::string title)
:m_width(width),
m_height(height),
m_title(title),
m_isInitialized(false)
{}

Window::~Window(){
    glfwDestroyWindow(m_pWindow);
    glfwTerminate();
    //Clear();
}

bool Window::Initialize()
{
    if (m_isInitialized) return m_isInitialized;

    if (!glfwInit()){
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        exit(EXIT_FAILURE);
        m_isInitialized = false;
    }

    m_pWindow = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (!m_pWindow){
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
        m_isInitialized = false;
    }

    glfwMakeContextCurrent(m_pWindow);
    glfwSwapInterval(1);

    m_isInitialized = true;
    return m_isInitialized;
}

//void Window::Clear(){
//    delete m_pWindow;

//    m_isInitialized = false;
//}

void Window::PollEvents(){
    glfwPollEvents();
}

bool Window::ShouldClose() const{
    return glfwWindowShouldClose(m_pWindow);
}

GLFWwindow* Window::GetWindow() const{
    return m_pWindow;
}

int Window::GetWidth() const{
    return m_width;
}

int Window::GetHeight() const{
    return m_height;
}

void Window::SwapBuffers(){
    glfwSwapBuffers(m_pWindow);
}

bool Window::IsKeyPressed(int key) const {
    return glfwGetKey(m_pWindow, key) == GLFW_PRESS;
}

void Window::GetMousePosition(double& x, double& y) const {
    glfwGetCursorPos(m_pWindow, &x, &y);
}