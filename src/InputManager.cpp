// src/InputManager.cpp
// Author: Kian Dadkhah

#include "InputManager.h"

namespace BombasticEngine {

  // Constructor implementation.
  InputManager::InputManager() {
    // Get the state of each key and the number of keys.
    keyState = SDL_GetKeyboardState(&numKeys);
  }

  // Destructor implementation.
  InputManager::~InputManager() {
    // Nothing to do here.
  }

  // Update implementation.
  void InputManager::update() {
    // SDL_PumpEvents updates the keyState array with the current state of each key.
    SDL_PumpEvents();
  }

  // isKeyPressed implementation.
  bool InputManager::isKeyPressed(SDL_Scancode key) const {
    // Return the state of the specified key.
    return keyState[key];
  }

} // namespace BombasticEngine
