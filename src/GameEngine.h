// src/GameEngine.h
// author: Kian Dadkhah
// Version: 1.0.0

#pragma once

namespace BombasticEngine {

// The GameEngine class serves as the main controller for the Bombastic Engine.
// It is responsible for initializing, running, and shutting down the engine.
class GameEngine {
public:
    // Start: Public method to initiate the engine's processes.
    // This method acts as a controller that calls the private methods in sequence.
    void Start();

private:
    // Initialize: Sets up necessary resources and states for the engine to run.
    // This method should be called at the beginning of the engine's lifecycle.
    void Initialize();
    
    // GameLoop: Contains the main loop where game logic, updates, and rendering are handled.
    // This method keeps running as long as the game is active.
    void GameLoop();
    
    // Shutdown: Cleans up resources and performs necessary tasks to safely terminate the engine.
    // This method should be called at the end of the engine's lifecycle.
    void Shutdown();
};

} // namespace BombasticEngine
