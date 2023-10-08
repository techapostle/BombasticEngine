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

    // isValid: Returns true if the engine is initialized successfully.
    bool isValid() const;

    // Get functions
    // getWidth: Returns the width of the window.
    int getWidth() const;
    // getHeight: Returns the height of the window.
    int getHeight() const;
    
    // ... Other methods ...

    // Clears the renderer, preparing it for new drawing operations with SDL's SDL_RenderClear function.
    void clear() const;
    // Display the renderer, updating the window with the drawn content with SDL's SDL_RenderPresent function.
    void display() const;
    // Function to add a delay to cap the frame rate.
    void delay(int milliseconds) const;

private:
    SDL_Window* window;    // Pointer to the SDL_Window object representing the window created.
    SDL_Renderer* renderer; // Pointer to the SDL_Renderer object for rendering textures.

    int width;  // Width of the window.
    int height; // Height of the window.
};

} // namespace BombasticEngine
