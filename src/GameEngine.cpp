// src/GameEngine.cpp
// Author: Kian Dadkhah

#include <iostream>
#include "GameEngine.h"

namespace BombasticEngine {

  // Constructor implementation
  GameEngine::GameEngine(int width, int height) : renderingEngine(width, height), assetManager(renderingEngine.getRenderer()) {}

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

    if (!renderingEngine.isValid()) {
      std::cerr << "Rendering Engine could not be created! SDL Error: " << SDL_GetError() << std::endl;
      return;
    }
  }

  // The GameLoop method contains the main loop where the game logic, updates, and rendering occur.
  // It runs continuously until the game or application is closed.
  void GameEngine::GameLoop() {
    std::cout << "Game Loop Started!" << std::endl;
    bool isRunning = true;
    while (isRunning) {
      // This loop will continue running until it's explicitly broken out of.

      // Rendering logic
      renderingEngine.clear();  // Clear the renderer.
      // For now, we will just render a single texture to the screen.
      renderingEngine.RenderTexture("../src/assets/obama.png", 0, 0);
      renderingEngine.display();  // Display the renderer.
      renderingEngine.delay(16);  // Add a delay to cap the frame rate.
      
      // Input logic
      inputManager.update();  // Update the input manager.
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
  }

} // namespace BombasticEngine
