// include/InputManager.h
// Author: Kian Dadkhah

#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

namespace BombasticEngine {
  /**
   * @brief InputManager
   * @brief The InputManager class is responsible for capturing and processing user inputs.
   * @brief It is a wrapper for SDL's event handling system.
   */
  class InputManager {
    public:
      /**
       * @brief Construct a new Input Manager object
       * 
       */
      InputManager();

      /**
       * @brief Destroy the Input Manager object
       */
      ~InputManager();

      /**
       * @brief Capture and process user inputs each frame.
       */
      void update();

      /**
       * @brief Check if a specific key is pressed.
       * 
       * @param key 
       * @return true 
       * @return false 
       */
      bool isKeyPressed(SDL_Scancode key) const;

    private:
      // Map of key codes to their current state. 
      std::unordered_map<SDL_Scancode, bool> keyMap;

      // Event handler for capturing user inputs.
      SDL_Event event;
  };
} // namespae BombasticEngine