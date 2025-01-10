#include <iostream>
#include <GL/glew.h>
#include "x64/src/graphics/window.h"
#include "x64/src/maths/math.h"
#include "x64/src/utils/fileutils.h"
#include "x64/src/graphics/shader.h"    


int main() {
    using namespace sparky;
    using namespace graphics;
    using namespace maths;
    using namespace utils;

    // Create a window
    Window window("Sparky!!", 1280, 800);
    glClearColor(0.2f, 0.3f, 0.8f, 0.9f);

    // Initialize OpenGL VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
  
	Shader shader("x64/src/shaders/basic.vert", "x64/src/shaders/basic.frag");
	//std::cout << position << std::endl;

    while (!window.closed()) {
        window.clear();
        
        window.update();
    }
    return 0;
}
