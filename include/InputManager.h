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
      // Stores the current state of each key.
      const Uint8* keyState;

      // Stores the number f keys in the keyState array.
      int numKeys;
  };
} // namespae BombasticEngine