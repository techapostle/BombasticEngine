// src/GameEngine.h
// author: Kian Dadkhah
// Version: 1.0.0

#pragma once

#include "InputManager.h"
#include "RenderingEngine.h"

namespace BombasticEngine {
/**
 * @brief GameEngine
 * @brief The GameEngine class is responsible for managing the game's lifecycle.
 * @brief It is responsible for initializing the engine's resources and states, running the main loop, and shutting down the engine.
 */
class GameEngine {
public:
    /**
     * @brief Construct a new Game Engine object
     * 
     * @param width set the width of the window
     * @param height set the height of the window
     */
    GameEngine(int width, int height);

    /** 
     * @brief Public method to initiate the engine's processes. This method acts as a controller that calls the private methods in sequence.
    */
    void Start();

private:
    /**
     * @brief Set up the engine's resources and states.
     * Should be called at the beginning of the engine's lifecycle.
     */
    void Initialize();
    
    /**
     * @brief Contains the main loop where the game logic, updates, and rendering occur.
     * This method is runnning continuously until the game or application is closed.
     */
    void GameLoop();
    
    /**
     * @brief Shut down the engine and perform cleanup.
     * This method should be called at the end of the engine's lifecycle.
     */
    void Shutdown();
    
    // InputManager instance: Handles user inputs from various devices.
    InputManager inputManager;
    // RenderingEngine instance: Initializes SDL, creates a window, and renders textures.
    RenderingEngine renderingEngine;
};

} // namespace BombasticEngine
