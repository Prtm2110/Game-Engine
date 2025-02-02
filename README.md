# 🐰 Rabbit3D

A lightweight, modern 3D graphics rendering engine built with OpenGL. This project serves as both a learning tool and a functional 3D renderer.

![Rendering Example](docs/3DRABBIT.gif)

## ✨ Key Features

- **Modern OpenGL Rendering Pipeline**
  - Hardware-accelerated 3D graphics rendering
  - Shader-based rendering system
  - Vertex and Index buffer abstractions
  
- **Mathematics Library**
  - Vector operations (Vec2, Vec3, Vec4)
  - Matrix transformations (4x4 matrices)
  - Quaternion support
  - Camera and projection utilities

- **Window Management**
  - GLFW-based window creation and management
  - Event handling system
  - Input management (keyboard, mouse)
  - Multiple window support

- **Graphics Features**
  - Mesh rendering
  - Texture loading and management
  - Basic material system
  - Simple lighting model

## 🚀 Getting Started

### Prerequisites

- **C++ Development Environment**
  - Visual Studio 2019/2022 (Windows)
  - GCC 7+ (Linux)
  - Clang 8+ (macOS)
- **Dependencies** (included in repository)
  - GLEW 2.1.0
  - GLFW 3.3+
  - OpenGL 4.3+

### Building the Project

#### Windows (Visual Studio)
1. Open `Spraky.sln` in Visual Studio
2. Select build configuration (Debug/Release)
3. Build solution (F7)

#### Linux/macOS
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## Usage

1. **Initialize the Window**: Use the Windows module to create a window with a specified size and title.

2. **Set Up Rendering Context**: Load shaders, initialize buffers, and set up the rendering pipeline.

3. **Implement Math Utilities**: Use the math module to handle transformations, projections, and other mathematical operations required for 3D rendering.

4. **Render Loop**: Create a render loop to handle rendering, input, and window updates.

### Code Example

Here is a basic example to render a triangle:


```cpp
#include "x64/src/graphics/window.h"
#include "x64/src/graphics/shader.h"
#include "x64/src/graphics/renderer2d.h"
#include "x64/src/maths/maths.h"
//Keep relative imports in mind

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
