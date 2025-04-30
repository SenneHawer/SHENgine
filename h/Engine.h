#pragma once
#include "Window.h"
#include <iostream>
#include <string>

class Engine{
    public:
    Engine(int x);
    ~Engine();

    void Initialize();
    void Run();
    void Clear();

    private:

    void Update();
    void Render();
    void HandleInput();

    bool m_bIsRunning;
    Window* m_pWindow;
};