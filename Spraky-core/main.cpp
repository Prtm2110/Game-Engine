#include <iostream>
#include <GL/glew.h>
#include "x64/src/graphics/window.h"
#include "x64/src/maths/math.h"
#include "x64/src/utils/fileutils.h"
#include "x64/src/graphics/shader.h"    
#include "x64/src/graphics/buffers/buffer.h"
#include "x64/src/graphics/buffers/vertexarray.h"
#include "x64/src/graphics/buffers/indexbuffer.h"

int main() {
    using namespace sparky;
    using namespace graphics;
    using namespace maths;
    using namespace utils;

    // Create a window
    std::cout << "Creating window..." << std::endl;
    Window window("Sparky!!", 1280, 800);
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    glClearColor(0.2f, 1.3f, 0.8f, 0.9f);

    // Initialize OpenGL VAO
    std::cout << "Initializing VAO..." << std::endl;
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    GLushort indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    VertexArray vao;
    Buffer* vbo = new Buffer(vertices, 4 * 3, 3);
    IndexBuffer ibo(indices, 6);

    std::cout << "Adding buffer to VAO..." << std::endl;
    vao.addBuffer(vbo, 0);

    mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    std::cout << "Loading shader..." << std::endl;
    Shader shader("x64/src/shaders/basic.vert", "x64/src/shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 4.5, 0)));
    shader.setUniform2f("light_pos", vec2(4.0f, 1.5f)); // Center of the square
    shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f)); // Black color for the glow

    std::cout << "Entering main loop..." << std::endl;
    while (!window.closed()) {
        std::cout << "Clearing window..." << std::endl;
        window.clear();

        std::cout << "Binding VAO ..." << std::endl;
        vao.bind();
        std::cout << "Binding IBO..." << std::endl;
        ibo.bind();

        // Check for OpenGL errors
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error before drawing elements: " << error << std::endl;
        }

        std::cout << "Drawing elements..." << std::endl;
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0); // Use GL_UNSIGNED_SHORT

        // Check for OpenGL errors
        error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL error after drawing elements: " << error << std::endl;
        }

        vao.unbind();

        std::cout << "Updating window..." << std::endl;
        window.update();
    }

    std::cout << "Cleaning up..." << std::endl;
    delete vbo; // Clean up dynamically allocated memory
    return 0;
}
