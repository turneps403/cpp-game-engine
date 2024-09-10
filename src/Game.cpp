#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Game::Game() {
    isRunning = false;
    std::cout << "Game constructor called!" << std::endl;
}

Game::~Game() {
    std::cout << "Game destructor called!" << std::endl;
}

void Game::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL" << std::endl;
        return;
    }

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWigth =  800; //displayMode.w;
    windowHeight = 600; //displayMode.h;

    window = SDL_CreateWindow(
        NULL, // title
        SDL_WINDOWPOS_CENTERED, // left x corner
        SDL_WINDOWPOS_CENTERED, // top y corner
        // 800, 600,
        windowWigth, windowHeight,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        std::cerr << "Error creating SDL window" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(
        window, 
        -1, // monitor id, -1 is the default one
        0 // specific flags for a render
    );
    if (!renderer) {
        std::cerr << "Error creating SDL renderer" << std::endl;
        return;
    }

    // run real fullscreen, not a window& change video mode at all.
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    isRunning = true;
}

void Game::ProcessInput() {
    SDL_Event sdlEvent;
    while(SDL_PollEvent(&sdlEvent)) {
        switch(sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
                    isRunning = false;
                }
                break;
        }
    }

}

void Game::Setup(){
    // Imitialize game objects
}

void Game::Update(){}

void Game::Render(){
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255); // rgba gray
    SDL_RenderClear(renderer);

    // // Draw a rectangle
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // rgba white
    // SDL_Rect player = { 10, 10, 20, 20 }; // x, y, w, h
    // SDL_RenderFillRect(renderer, &player);

    // Loads a PNG texture
    SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect dstRect = { 10, 10, 32, 32 }; // x, y, w, h
    SDL_RenderCopy(
        renderer, texture, 
        NULL, // source full (not a part)
        &dstRect // destштфешщт rect on canvas
    );
    SDL_DestroyTexture(texture);

    SDL_RenderPresent(renderer);
}

void Game::Run() {
    Setup();
    while(isRunning) {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
