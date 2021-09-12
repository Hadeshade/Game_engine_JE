// Feito por Marco Antonio Nemetala Garcia
#include "State.h"
#include "Sprite.h"
#include "Sound.h"


// Construtor da Classe State e inicializa os contrutores de membros;
State::State() // : bg("img/ocean.jpg"), music("audio/stageState.ogg")
{
    // Inicializa o quitRequested
    quitRequested = false;
    GameObject fundo;
    fundo.AddComponent(new Sprite("img/ocean.jpg",fundo));
    fundo.AddComponent(new Sound(fundo,"audio/stageState.ogg"));
    objectArray.emplace_back(fundo);
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
    // if(SDL_QuitRequested())
    // {
    //     quitRequested = true;
    // }

    // Input();
    for (std::vector<std::unique_ptr<GameObject>>::size_type i = 0; i != objectArray.size(); i++)
    {
        objectArray[i]->Update(dt);
    }
}

// Função que renderiza o jogo, Entidades, cenários, HUD, entre outros;
void State::Render()
{
    // Chamar o Render do fundo (bg) 
    // bg.Render();
    for (std::vector<std::unique_ptr<GameObject>>::size_type i = 0; i != objectArray.size(); i++)
    {
        objectArray[i]->Render();
    }

}

State::~State()
{
    objectArray.clear();
}

void State::Input()
{
    // Não faço ideia o que eu coloco aqui!
}

void State::AddObject(int mouseX, int mouseY)
{
    GameObject enemy;
    enemy.AddComponent(new Sprite("img/penguinface.png",enemy));
    enemy.AddComponent(new Sound(enemy, "audio/boom.wav"));
    objectArray.emplace_back(enemy);
}