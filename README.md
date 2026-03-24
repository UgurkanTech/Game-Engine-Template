# C++ OpenGL Game Engine Template with CMake, ImGUI, and GLFW

Welcome to this comprehensive game engine template built in C++ with modern development practices. This template provides a solid foundation for creating your own game engine, featuring OpenGL for rendering, ImGUI for debugging and UI development, and GLFW for cross-platform window management.

## Overview

This project is structured into three main components:

- **Core Library**: A shared library that contains the foundational engine functionality, including rendering, window management, input handling, and utility classes. Both the Editor and Runtime executables depend on this library.

- **Editor**: An interactive development environment for designing and testing game scenes. It includes an ImGUI-based interface for real-time debugging, visualization, and configuration of engine features.

- **Runtime**: A lean executable for playing and testing your game builds. It focuses on performance and provides a clean interface for game execution.

## Key Features

| Feature | Description |
|---------|-------------|
| **Cross-Platform** | Works seamlessly on Windows, macOS, and Linux with minimal configuration |
| **Modern C++** | Built with C++11 standard for broad compiler compatibility and stability |
| **CMake Build System** | Clean, maintainable build configuration that handles dependencies automatically |
| **OpenGL Rendering** | Hardware-accelerated 3D rendering using the OpenGL API |
| **ImGUI Integration** | Immediate-mode GUI for real-time debugging, metrics, and development tools |
| **Modular Architecture** | Well-separated Core library with clean interfaces for extension |

## Dependencies

This project uses Git submodules to manage external dependencies:

- **GLFW**: Cross-platform window and input library
- **ImGUI**: Immediate-mode GUI library with OpenGL backend

## Prerequisites

Before building, ensure you have the following installed:

- **CMake** (version 3.5.0 or higher)
- **C++ Compiler** supporting C++11 (GCC 4.8+, Clang 3.3+, MSVC 2013+)
- **Git** (for submodule management)
- **OpenGL** drivers compatible with your graphics hardware

## Building from Source

### 1. Clone the Repository

```bash
git clone --recurse-submodules https://github.com/yourusername/game-engine.git
cd game-engine
```

> **Note**: The `--recurse-submodules` flag is essential to clone the Git submodules (GLFW and ImGUI). If you've already cloned without this flag, run `git submodule update --init --recursive`.

### 2. Configure the Build

```bash
mkdir build
cd build
cmake ..
```

### 3. Build the Project

```bash
cmake --build .
```

### 4. Run the Executables

After building, you'll find:

- **Editor**: `bin/Editor` - The development environment
- **Runtime**: `bin/Runtime` - The game player executable

On Linux/macOS, you can run them directly:
```bash
./bin/Editor
./bin/Runtime
```

On Windows:
```cmd
bin\Editor.exe
bin\Runtime.exe
```

## Project Structure

```
game-engine/
├── CMakeLists.txt           # Root CMake configuration
├── README.md
├── CORE/                    # Shared library source
│   └── src/
├── EDITOR/                  # Editor executable source
│   └── src/
├── RUNTIME/                 # Runtime executable source
│   └── src/
├── resources/               # Game assets (fonts, textures, etc.)
├── submodules/              # Git submodules (GLFW, ImGUI)
└── app.rc                   # Windows resource file
```

## Usage

### Core Library API

The Core library provides:

- **OpenGL Context Management**: Through GLFW integration
- **Input Handling**: Keyboard, mouse, and gamepad input
- **Window Management**: Cross-platform window creation and event handling
- **Rendering Pipeline**: Basic OpenGL rendering setup and management
- **Utility Classes**: Math utilities, file loading, and helper functions

### Editor Features

- Scene visualization with real-time rendering
- Property inspectors for game objects
- Console for logging and debugging output
- Performance metrics and profiling tools

### Runtime Features

- Optimized execution environment
- Game loop management
- Resource loading and management
- Save/load functionality for game states

## Customization

To extend this engine:

1. Add your source files to the appropriate `src/` directories
2. Update `CMakeLists.txt` to include new source files (or use `file(GLOB ...)` for automatic discovery)
3. Link against the Core library in your executables
4. Add resources to the `resources/` directory

## Troubleshooting

### Common Build Issues

**Submodules not found**: Run `git submodule update --init --recursive`

**OpenGL not found**: Ensure your system has OpenGL development headers installed. On Ubuntu: `sudo apt install libopengl-dev`

**GLFW build errors**: Ensure you have the required system dependencies. On Ubuntu: `sudo apt install xorg-dev libglu1-mesa-dev`

**Missing resources**: The build system copies the resources directory to `bin/resources/`. Ensure your code looks for resources relative to this location.

## License

This project is provided as-is for educational and development purposes.

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests to improve the engine.

## Acknowledgments

- Built with [GLFW](https://www.glfw.org/) for window management
- UI powered by [Dear ImGUI](https://github.com/ocornut/imgui)
- Build system powered by [CMake](https://cmake.org/)
```

Note: I assumed the project root was `Game-Engine/` based on the directory listing. If the README should be at a different location or if you'd like to add specific details (like your GitHub username, license information, or screenshots), please let me know and I'll adjust the content accordingly.