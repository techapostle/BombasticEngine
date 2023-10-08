// include/AssetManager.h
// Author: Kian Dadkhah

#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>

namespace BombasticEngine {
  /**
   * @brief AssetManager
   * @brief The AssetManager class is responsible for loading, unloading and storing assets.
   */

  class AssetManager {
    public:
      AssetManager();
      ~AssetManager();

    /**
     * @brief Load a texture from a file and associate it with an ID.
     * @param id Identifier for the texture.
     * @param filePath File path to the texture.
     * @return true if the texture is loaded successfully, false otherwise.
     */
      bool loadTexture(const std::string& id, const std::string& filePath);
    
    /**
     * @brief Unload a texture associated with an ID.
     * @param id Identifier for the texture to be unloaded.
     */
      void unloadTexture(const std::string& id);
  
    /**
     * @brief Retrieve a texture associated with an ID.
     * @param id Identifier for the texture to be retrieved.
     * @return Pointer to the SDL_Texture object associated with the ID.
     */
      SDL_Texture* getTexture(const std::string& id) const;

    private:
      std::map<std::string, SDL_Texture*> textureMap; // Map of texture IDs to their SDL_Texture pointers.
  };
} // namespace BombasticEngine