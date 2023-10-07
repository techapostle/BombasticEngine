// src/InputManager.cpp
// Author: Kian Dadkhah

#include "InputManager.h"
#include <iostream>

namespace BombasticEngine {

  // Constructor implementation.
  InputManager::InputManager() {}

  // Destructor implementation.
  InputManager::~InputManager() {}

  // Update implementation.
  void InputManager::update() {
    // Poll for events. If there is an event, process it.
    while (SDL_PollEvent(&event)) {
      std::cout << "Event polled: " << event.type << std::endl; // Debugging line

      // If the event is a key press, update the key map.
      if (event.type == SDL_KEYDOWN) {
        keyMap[event.key.keysym.scancode] = true;
      }
      // If the event is a key release, update the key map.
      if (event.type == SDL_KEYUP) {
        keyMap[event.key.keysym.scancode] = false;
      }
    }
  }

  // isKeyPressed implementation.
  bool InputManager::isKeyPressed(SDL_Scancode key) const {
    auto it = keyMap.find(key);
    // If the key is found in the map, return its state.
    if (it != keyMap.end()) {
      return it->second;
    }
    // Otherwise, return false.
    return false;
  }

} // namespace BombasticEngine
