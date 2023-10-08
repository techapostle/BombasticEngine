// src/RenderingEngine.cpp
// author: Kian Dadkhah

#include "RenderingEngine.h"
#include <SDL2/SDL_image.h>
#include <iostream>

namespace BombasticEngine {
  // Constructor implementation
  RenderingEngine::RenderingEngine(int width, int height) {
    // Initialize SDL's video subsystem; return if it fails.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
      return;
    }
    // Creat an SDL window with the specified width and height; return if it fails.
    window = SDL_CreateWindow("Bombastic Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
      return;
    }
    // Create an SDL renderer with hardware acceleration for the window; return if it fails.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
      return;
    }
    // Initialize SDL_image with PNG support; return if it fails.
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
      return;
    }
  }

  // Destructor implementation
  RenderingEngine::~RenderingEngine() {
    // Destroy the renderer.
    SDL_DestroyRenderer(renderer);
    // Destroy the window.
    SDL_DestroyWindow(window);
    // Quit SDL_image.
    IMG_Quit();
    // Quit SDL.
    SDL_Quit();
  }

  // RenderTexture implementation
  void RenderingEngine::RenderTexture(const std::string& filePath, int x, int y) {
    // Load an image from the specified file path into an SDL_Surface object; return if it fails.
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if (!loadedSurface) {
      std::cerr << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
      return;
    }
    // Create an SDL_Texture from the loaded SDL_Surface; return if it fails.
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!texture) {
      std::cerr << "Unable to create texture from " << filePath << "! SDL Error: " << SDL_GetError() << std::endl;

      //TODO: Throw an exception
      return;
    }
    // Define a rectangle for rendering the texture, with the specified (x, y) coordinates and the width and height of the loaded surface.
    SDL_Rect renderQuad = { x, y, loadedSurface->w, loadedSurface->h };
    // Render the texture to the screen at the specified rectangle.
    SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);

    // Clean up the texture.
    SDL_DestroyTexture(texture);
  }

  // isValid implementation
  bool RenderingEngine::isValid() const {
    return window != nullptr && renderer != nullptr;
  }

  // getWidth implementation
  int RenderingEngine::getWidth() const {
    return width;
  }

  // getHeight implementation
  int RenderingEngine::getHeight() const {
    return height;
  }

} // namespace BombasticEngine