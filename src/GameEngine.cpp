// src/GameEngine.cpp
// Author: Kian Dadkhah

#include <iostream>
#include "GameEngine.h"

namespace BombasticEngine {

  // The Start method is the entry point of the engine.
  // It sequentially calls Initialize, GameLoop, and Shutdown methods to control the engine's lifecycle.
  void GameEngine::Start() {
    Initialize();  // Set up the engine.
    GameLoop();    // Enter the main game loop.
    Shutdown();    // Perform cleanup and shut down the engine.
  }

  // The Initialize method sets up the necessary resources and states for the engine.
  // It outputs a message to the console indicating the initialization process has started.
  void GameEngine::Initialize() {
    std::cout << "Bombastic Engine Initialized!" << std::endl;

    // Initialize the SDL and all of its subsystems.
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
      return;
    }

    // Create an SDL window
    window = SDL_CreateWindow("Bombastic Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
      std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
      SDL_Quit();
      return;
    }

    // Create an SDL renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
      std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
      SDL_DestroyWindow(window);
      SDL_Quit();
      return;
    }
  }

  // The GameLoop method contains the main loop where the game logic, updates, and rendering occur.
  // It runs continuously until the game or application is closed.
  void GameEngine::GameLoop() {
    std::cout << "Game Loop Started!" << std::endl;
    bool isRunning = true;
    while (isRunning) {
      inputManager.update();  // Update the input manager.
      // TODO: Implement the update and rendering logic for the game here.
      // This loop will continue running until it's explicitly broken out of.

      // std::cout << "Game Loop Running!" << std::endl;
      
      // Break out of the loop when the user presses the ESC key.
      if (inputManager.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
        isRunning = false;
      }
      if (inputManager.isKeyPressed(SDL_SCANCODE_SPACE)) {
        std::cout << "Spacebar pressed!" << std::endl;
      }

      if (isRunning == false) {
        std::cout << "Game Loop Stopped!" << std::endl;
        break;
      }
    }
    std::cout << "Game Loop Ended!" << std::endl;
  }

  // The Shutdown method cleans up resources and performs tasks necessary for safely terminating the engine.
  // It outputs a message to the console indicating the engine is shutting down.
  void GameEngine::Shutdown() {
    std::cout << "Bombastic Engine Shutdown!" << std::endl;

    // Destroy the renderer and window.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL.
    SDL_Quit();
  }

} // namespace BombasticEngine
