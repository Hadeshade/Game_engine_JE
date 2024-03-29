// Feito por Marco Antonio Nemetala Garcia 

#include "Game.h"
#include "State.h"

Game* Game::instance;

State& Game::GetState()
{
    return *state;
}

Game::Game(std::string title, int width, int height)
{
    if(instance == nullptr)
    {
        instance = this;
    }
    else{
        exit(EXIT_FAILURE);
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0)
    {
        // Inicialização das imagens e tratamento do erro;
        int flag_img=IMG_INIT_JPG|IMG_INIT_PNG;
        int initted_img=IMG_Init(flag_img);
        if ((initted_img&flag_img) != flag_img)
        {
            printf("IMG_Init: falhou na inicialização da função\n");
            printf("IMG_Init: %s\n", IMG_GetError());
        }

        // Cria a janela e verifica se ela está alocada corretamente
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        if (window == nullptr)
        {
            printf("Não foi possível criar a aba do jogo: %s\n", SDL_GetError());
            exit(-1);
        }

        // Cria o renderizador do jogo para ser usado na janela
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
        {
            printf("Não foi possível criar o renderizador do jogo: %s\n", SDL_GetError());
            exit(-1);
        }

        // Inicialização do mixer e tratamento do erro;
        int flag_mix=MIX_INIT_OGG;
        int initted_mix=Mix_Init(flag_mix);
        if ((initted_mix&flag_mix) != flag_mix)
        {
            printf("Mix_Init: falhou na inicialização da função\n");
            printf("Mix_Init: %s\n", Mix_GetError());
        }

        // Verifica a função Mix_OPEN_AUDIO e trata o erro caso não abra corretamente!
        if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
        {
            printf("Mix_OpenAudio: %s\n", Mix_GetError());
            exit(2);
        }

        // Inicializa a função Mix_AllocateChannels - não tem como falhar essa função!
        Mix_AllocateChannels(32);

        state = new State();
    }
    else 
    {
        printf("Falha ao executar o SDL_Init: %s\n", SDL_GetError()); // Caso não seja inicializado corretamente o jogo
    }
    
}

Game::~Game()
{
    delete state;
    // Finaliza o OpenAudio inicializada
    Mix_CloseAudio();
    // Finaliza o Mix_Init inicializada
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    // Destroi a window e o renderer;
    SDL_DestroyWindow(window);
    // Finaliza a IMG_Init inicializada
    IMG_Quit();
    // Finaliza o SDL_Init inicializada
    SDL_Quit();
}

Game& Game::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Game("Marco Antonio - 180126792", 1024, 600);
    }
    return *instance;
}

SDL_Renderer* Game::GetRenderer()
{
    return renderer;
}

void Game::Run()
{
    while( (GetState().QuitRequested()) != true)
    {
        GetState().Update(2.1);
        GetState().Render();
        SDL_RenderPresent(renderer);
        // Serve para atrasar o processamento do próximo frame;
        SDL_Delay(33);
    }
}