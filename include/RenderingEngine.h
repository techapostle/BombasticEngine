// include/RenderingEngine.h
// author: Kian Dadkhah

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace BombasticEngine {

// The RenderingEngine class is responsible for initializing SDL, creating a window, and rendering textures.
class RenderingEngine {
public:
    // Constructor: Initializes SDL, creates a window of given width and height.
    RenderingEngine(int width, int height);
    
    // Destructor: Cleans up SDL resources.
    ~RenderingEngine();
    
    // RenderTexture: Loads and renders a texture from a given file path at the specified (x, y) coordinates.
    void RenderTexture(const std::string& filePath, int x, int y);

private:
    SDL_Window* window;    // Pointer to the SDL_Window object representing the window created.
    SDL_Renderer* renderer; // Pointer to the SDL_Renderer object for rendering textures.
};

} // namespace BombasticEngine
