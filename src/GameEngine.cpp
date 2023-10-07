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
    // TODO: Add initialization code here.
    // This is where you'd typically set up resources, load assets, initialize variables, etc.
  }

  // The GameLoop method contains the main loop where the game logic, updates, and rendering occur.
  // It runs continuously until the game or application is closed.
  void GameEngine::GameLoop() {
    std::cout << "Game Loop Started!" << std::endl;
    while (true) {
      // TODO: Implement the update and rendering logic for the game here.
      // This loop will continue running until it's explicitly broken out of.
      
      // TODO: Implement a condition to break out of the loop when the game ends or the application is closed.
    }
    std::cout << "Game Loop Ended!" << std::endl;
  }

  // The Shutdown method cleans up resources and performs tasks necessary for safely terminating the engine.
  // It outputs a message to the console indicating the engine is shutting down.
  void GameEngine::Shutdown() {
    std::cout << "Bombastic Engine Shutdown!" << std::endl;
    // TODO: Add shutdown code here.
    // This is where you'd typically release resources, save data, and perform other cleanup tasks.
  }

} // namespace BombasticEngine
