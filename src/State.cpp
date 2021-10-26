// Feito por Marco Antonio Nemetala Garcia
#include "State.h"
#include "Sprite.h"
#include "Sound.h"
#include "Face.h"
#include "Vec2.h"
#include "TileMap.h"
#include "TileSet.h"
#include <cmath>


// Construtor da Classe State e inicializa os contrutores de membros;
State::State() // : bg("img/ocean.jpg"), music("audio/stageState.ogg")
{
    // Inicializa o quitRequested
    quitRequested = false;
    GameObject* background = new GameObject();
	Sprite* oceanImage = new Sprite("img/ocean.jpg",*background);
	Sound* oceanSound = new Sound(*background,"audio/stageState.ogg");
	TileSet* imagemMapa = new TileSet(std::string("img/tileset.png"), *background, 64, 64);
	TileMap* mapa = new TileMap(*background, std::string("map/tileMap.txt"), imagemMapa);
	background->AddComponent(mapa);
    background->AddComponent(oceanImage);
    background->AddComponent(oceanSound);
    objectArray.emplace_back(background);
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

    Input();
    for (unsigned int i = 0; i < objectArray.size(); i++)
    {
        objectArray[i]->Update(dt);
        if(objectArray[i]->IsDead())
        {
            objectArray.erase(objectArray.begin()+i);
        }

    }
}

// Função que renderiza o jogo, Entidades, cenários, HUD, entre outros;
void State::Render()
{
    // Chamar o Render do fundo (bg) 
    // bg.Render();
    for (unsigned int i = 0; i < objectArray.size(); i++)
    {
        objectArray[i]->Render();
    }

}

State::~State()
{
    objectArray.clear();
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains( (float)mouseX, (float)mouseY ) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::AddObject(int mouseX, int mouseY)
{
    GameObject* enemy = new GameObject();
    Sprite* penguin = new Sprite("img/penguinface.png",*enemy);
	Sound* morre = new Sound(*enemy, "audio/boom.wav");
	Face* vida = new Face(*enemy);
    enemy->box.h = penguin->GetHeight();
    enemy->box.w = penguin->GetWidth();
    enemy->box.x = (float)mouseX;
    enemy->box.y = (float)mouseY;
    enemy->AddComponent(penguin);
    enemy->AddComponent(morre);
	enemy->AddComponent(vida);
    objectArray.emplace_back(enemy);
}