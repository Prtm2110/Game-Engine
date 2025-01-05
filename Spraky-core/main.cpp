#include <iostream>
#include <GL/glew.h>
#include "x64/src/graphics/window.h"
#include "x64/src/maths/vec2.h"

int main() {
    using namespace sparky;
    using namespace graphics;
    using namespace maths;

    // Create a window
    Window window("Sparky!!", 800, 600);
    glClearColor(0.2f, 0.3f, 0.8f, 0.9f);

    // Initialize OpenGL VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
       
	vec2 vector(2.0f, 3.0f);
	vec2 vec23(3.0f, 4.0f);
	vector = vector + vec23;
	std::cout << vector  << std::endl;


    while (!window.closed()) {
        window.clear();

        // Check if 'A' key is pressed
        /*if (window.isKeyPressed(GLFW_KEY_A)) {
            std::cout << "A is pressed!" << std::endl;
        }
        double x, y;
		window.getMousePosition(x, y);  
		std::cout << x << ", " << y << std::endl;*/

        // Draw a simple triangle
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        // Update the window
        window.update();
    }
    return 0;
}
