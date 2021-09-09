// Feito por Marco Antonio Nemetala Garcia
#include "State.h"
#include "Sprite.h"


// Construtor da Classe State e inicializa os contrutores de membros;
State::State() : bg("img/ocean.jpg"), music("audio/stageState.ogg")
{
    // Inicializa o quitRequested
    quitRequested = false;
    // Instancia a classe Sprite:
    // Sprite inicio("img/penguinface.png");
    // bg = Sprite("img/ocean.jpg");
    // music = Music();
}

void State::LoadAssets()
{
}

// Retorna true se foi requisitado para sair do jogo;
bool State::QuitRequested()
{
    return quitRequested;
}

// Checagem relativa ao encerramento do jogo.
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
    bg.Render();
}

State::~State()
{
}