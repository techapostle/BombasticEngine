WELCOME, to the Bombastic Engine source repository! This engine implements advanced 2D graphics and physics, with 3D support planned for the future. Feel free to contribute, update documentation, or just take it for a spin. This project is currently in its early stages and may not work as intended. As a work-in-progress engine, I will be continously updating its components to work with the newest technologies once it has a solid foundation. The purpose of this engine is for it to support my indie game developmer arc as I learn and explore the amazing world of video games.  

### Current Capabilities
   - Renders a single image of Obama as a texture
   - Loads a single audio of Obama saying, "My fellow Americans!"
      - User can play, pause, or loop the loaded audio.

### Phase 1: Design and Planning

1. **Engine Architecture:**

   - **Core Module:** Main loop, initialization, and shutdown.
   - **Rendering Module:** 2D rendering with future support for 3D.
   - **Input Module:** Handling user inputs.
   - **Physics Module:** Basic collision detection for 2D (extendable to 3D).
   - **Audio Module:** Sound effects and music playback.

2. **Technology Stack:**

   - **Language:** C++.
   - **Graphics Library:** SDL2 for 2D rendering (with potential to integrate OpenGL for 3D).
   - **Audio Library:** SDL2_mixer or OpenAL.
   - **Physics:** Custom lightweight physics for 2D, with potential to integrate a library like Bullet for 3D.

3. **Development Environment:** Visual Studio or Code::Blocks with the necessary libraries installed.

### Phase 2: Implementation (CURRENT)

1. **Core Module:**

   - Implement the main loop.
   - Implement initialization and shutdown procedures.

2. **Rendering Module:**

   - Set up SDL2 and create a window.
   - Implement basic 2D rendering functions.
   - Design the module to allow easy extension to 3D with OpenGL.

3. **Input Module:**

   - Implement input handling for keyboard and mouse.

4. **Physics Module:**

   - Implement basic 2D collision detection.
   - Design the module to be extendable to 3D.

5. **Audio Module:**
   - Implement audio playback functions using the chosen audio library.

### Phase 3: Testing and Debugging

- Test each module individually and then together as a whole.
- Debug any issues that arise during testing.

### Phase 4: Documentation and Future Planning

- Document the engine's architecture, modules, and usage.
- Plan for future features and improvements, including 3D support.

### Implementation Details:

- Each module should be implemented in separate source and header files.
- Use object-oriented principles to design each module.
- Write clean, modular, and well-documented code.

### Core Modules

- Game Engine: The core class which runs the engine
- Rendering Engine: The class which uses SDL to initialize and render the window

### Modules

Great! Now that we have the core and rendering modules set up, we can proceed with the following modules:

### 1. **Input Handling Module:**

- This module will handle user inputs from various devices like keyboard, mouse, or game controllers.
- We can create classes like `InputManager` to abstract the input handling process.

### 2. **Audio Module:**

- Implementing an audio module using OpenAL or another suitable library to play background music, sound effects, etc.
- We can create classes like `AudioManager` to manage audio resources and playback.

### 3. **Physics Module:**

- Implementing basic 2D physics for movement, collision detection, and response.
- We might need classes for `RigidBody`, `Collider`, etc.

### 4. **Scene Management:**

- Implementing a system to manage different game scenes or levels.
- Classes like `SceneManager`, `Scene`, or `GameObject` might be necessary.

### 5. **Asset Management:**

- Developing a system to efficiently load, store, and retrieve game assets like textures, audio files, etc.
- Consider creating an `AssetManager` class for this purpose.

### 6. **GUI System:**

- Implementing a system for creating and managing in-game user interfaces, menus, buttons, etc.

### 7. **Scripting (Optional):**

- The engine will use Lua for scripting.
