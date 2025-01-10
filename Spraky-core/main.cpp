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
    glClearColor(0.2f, 1.3f, 0.8f, 0.9f);

    // Initialize OpenGL VAO
   
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	GLuint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

    GLuint vbo, ibo;
	glGenBuffers(1, &vbo);  
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Shader shader("x64/src/shaders/basic.vert", "x64/src/shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", mat4::tranlation(vec3(8, 4.5, 0)));
    shader.setUniform2f("light_pos", vec2(8.0f, 4.5f)); // Center of the square
    shader.setUniform4f("colour",    vec4(0.0f, 0.0f, 0.0f, 1.0f )); // Black color for the glow

    while (!window.closed()) {
        window.clear();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        window.update();
    }
    return 0;
}
