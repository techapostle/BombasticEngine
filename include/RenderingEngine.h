// include/RenderingEngine.h
// author: Kian Dadkhah

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace BombasticEngine {

/**
 * @brief RenderingEngine
 * @brief Responsible for initializing SDL, creating a window and rendering textures. 
 */
class RenderingEngine {
public:
    /**
     * @brief Construct a new Rendering Engine object
     * 
     * @param width set the width of the window
     * @param height set the height of the window
     */
    RenderingEngine(int width, int height);
    
    /**
     * @brief Destroy the Rendering Engine object
     */
    ~RenderingEngine();
    
    /**
     * @brief Renders a texture at a specified position from the given file path.
     * 
     * @param filePath String containing the file path to the texture.
     * @param x Position on the x-axis.
     * @param y Position on the y-axis.
     */
    void RenderTexture(const std::string& filePath, int x, int y);

    /**
     * @brief Returns true if the engine is initialized successfully, false otherwise.
     * 
     * @return true 
     * @return false 
     */
    bool isValid() const;

    /**
     * @brief Get the Width object
     * 
     * @return int Width of the window.
     */
    int getWidth() const;

    /**
     * @brief Get the Height object
     * 
     * @return int Height of the window.
     */
    int getHeight() const;

    /**
     * @brief Get the Renderer object
     * 
     * @return SDL_Renderer* Pointer to the SDL_Renderer object.
     */
    SDL_Renderer* getRenderer() const;
    
    /**
    * @brief Clears the renderer, preparing it for new drawing operations with SDL's SDL_RenderClear function.
    */
    void clear() const;

    /**
    * @brief Display the renderer, updating the window with the drawn content with SDL's SDL_RenderPresent function.
    */
    void display() const;
    
    /**
    * @brief Function to add a delay to cap the frame rate.
    * @param milliseconds The number of milliseconds to delay.
    */
    void delay(int milliseconds) const;

private:
    SDL_Window* window;     // Pointer to the SDL_Window object representing the window created.
    SDL_Renderer* renderer; // Pointer to the SDL_Renderer object for rendering textures.

    int width;  // Width of the window.
    int height; // Height of the window.
};

} // namespace BombasticEngine
