// Feito por Marco Antonio Nemetala Garcia
#include "State.h"
#include "Sprite.h"


State::State()
{
    // Inicializa o quitRequested
    quitRequested = false;
    // Instancia a classe Sprite:
    //Sprite inicio("img/penguinface.png");
    // bg = Sprite("img/ocean.jpg");
    // music = Music();
}

void State::LoadAssets()
{


}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::Update(float dt)
{
    // Caso aperte o batão X da janela ou aperte ALT+F4 
    if(SDL_QuitRequested())
    {
        quitRequested = true;
    }
}

// Função que renderiza o jogo, Entidades, cenários, HUD, entre outros;
void State::Render()
{
    // Chamar o Render do fundo (bg) 
    //bg.Render(512,300);
}

State::~State()
{
}