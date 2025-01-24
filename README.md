# Rabbit Renderer

Rabbit Renderer is a lightweight 3D graphics rendering engine inspired by The Cherno's Rabbit Game Engine series. Built using OpenGL, GLEW, and GLFW, this project serves as a learning tool and a functional 3D renderer with modular components for graphics rendering, mathematics, and window management.

## Features

- **3D Rendering**: Render high-quality 3D graphics with OpenGL.
- **Math Module**: Provides utilities for matrix, vector, and transformation calculations.
- **Windows Module**: Handles window creation, input events, and context management via GLFW.
- **Case Handling**: Robust error and input handling mechanisms for smooth operation.

## Getting Started

Follow these steps to set up and run the Rabbit Renderer on your system.

### Prerequisites

Ensure you have the following installed:

- **C++ Compiler**: GCC/Clang/MSVC
- **GLEW**: OpenGL Extension Wrangler Library
- **GLFW**: OpenGL Framework for window management

### Cloning the Repository

```bash
git clone <repository-url>
cd Rabbit-renderer
```

### Building the Project

1. Create a build directory:

   ```bash
   mkdir build && cd build
   ```

2. Configure the build system with CMake:

   ```bash
   cmake ..
   ```

3. Build the project:

   ```bash
   make
   ```

### Running the Renderer

After building the project, you can run the renderer executable:

```bash
./Rabbit_renderer
```

## Usage

1. **Initialize the Window**: Use the Windows module to create a window with a specified size and title.

2. **Set Up Rendering Context**: Load shaders, initialize buffers, and set up the rendering pipeline.

3. **Implement Math Utilities**: Use the math module to handle transformations, projections, and other mathematical operations required for 3D rendering.

4. **Render Loop**: Create a render loop to handle rendering, input, and window updates.

### Code Example

Here is a basic example to render a triangle:

```cpp
#include "Window.h"
#include "Math.h"
#include "Renderer.h"

int main() {
    Window window(800, 600, "Rabbit Renderer");
    Renderer renderer;

    while (!window.shouldClose()) {
        renderer.clear();
        renderer.drawTriangle(); // Replace with your own draw call
        window.update();
    }

    return 0;
}
```

## Contributing

Contributions are welcome! Feel free to open issues, suggest features, or submit pull requests to improve this project.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
