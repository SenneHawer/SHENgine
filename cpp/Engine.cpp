#include "Engine.h"


Engine::Engine(int x)
:m_bIsRunning(false),
m_pWindow(nullptr)
{
    m_pWindow = new Window(500, 500, "SHENgine");
}

Engine::~Engine(){
    //Clear();
}

void Engine::Initialize(){
    m_pWindow->Initialize();
}

void Engine::Run(){
    if(!m_pWindow->Initialize()){
        std::cerr << "Failed to initialize window!" << std::endl;
        return;
    }

    //player

    //loop
    while (!m_pWindow->ShouldClose()){
        //m_pWindow->Clear();
        m_pWindow->PollEvents();

        Update();
    }
}

void Engine::Clear()
{
    //m_pWindow->Clear();
    delete m_pWindow;
}

void Engine::Update(){



    //Game loop


}

void Engine::Render(){

}

void Engine::HandleInput(){

}
