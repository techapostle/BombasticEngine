// src/AssetManager.cpp
// Author: Kian Dadkhah

#include "AssetManager.h"
#include <iostream>
#include <SDL2/SDL_image.h>

namespace BombasticEngine {
  // Constructor implementation.
  AssetManager::AssetManager() {}

  // Destructor implementation.
  AssetManager::~AssetManager() {
    // Iterate over the textureMap and destroy each texture.
    for (auto& pair : textureMap) {
      SDL_DestroyTexture(pair.second);
    }
  }

  // loadTexture implementation.
  bool AssetManager::loadTexture(const std::string& id, const std::string& filePath) {
    // Load an image from the specified file path into an SDL_Surface object; return if it fails.
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if (!loadedSurface) {
      std::cerr << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
      return false;
    }
    // Create an SDL_Texture from the loaded SDL_Surface; return if it fails.
    SDL_Texture* texture = SDL_CreateTextureFromSurface(/* renderer */, loadedSurface);
    if (!texture) {
      std::cerr << "Unable to create texture from " << filePath << "! SDL Error: " << SDL_GetError() << std::endl;
      return false;
    }
    // Add the texture to the textureMap.
    textureMap[id] = texture;
    // Destroy the SDL_Surface.
    // SDL_FreeSurface(loadedSurface);
    // Return true if the texture is loaded successfully.
    return true;
  }

  // unloadTexture implementation.
  void AssetManager::unloadTexture(const std::string& id) {
    // Checkif the texture with the given ID exists before trying to destroy and erase it.
    auto it = textureMap.find(id);
    if (it != textureMap.end()) {
      SDL_DestroyTexture(it->second);
      textureMap.erase(it);
    } else {
      std::cerr << "Unable to unload texture with ID " << id << "! ID not found." << std::endl;
    }
  }

  // getTexture implementation.
  SDL_Texture* AssetManager::getTexture(const std::string& id) const {
    // Check if the texture with the given ID exists before trying to return it.
    auto it = textureMap.find(id);
    if (it != textureMap.end()) {
      return it->second;
    }
    // If the texture is not found, return nullptr.
    return nullptr;
  }

} // namespace BombasticEngine
