// include/InputManager.h
// Author: Kian Dadkhah

#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

namespace BombasticEngine {
  // The InputManager class is responsible for handling user inputs from various devices.
  class InputManager {
    public:
      // Constructor: Initializes the input manager.
      InputManager();

      // Destructor: Cleans up resources.
      ~InputManager();

      // Update: Captures and processes user inputs each frame.
      void update();

      // isKeyPressed: Checks if a specific key is currently pressed.
      bool isKeyPressed(SDL_Scancode key) const;

    private:
      // Map of key codes to their current state. 
      std::unordered_map<SDL_Scancode, bool> keyMap;

      // Event handler for capturing user inputs.
      SDL_Event event;
  };
} // namespae BombasticEngine