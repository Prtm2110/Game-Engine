#include <GLFW/glfw3.h>
#include <iostream>
#include  "x64/src/graphics/window.h"


int main() {
	using namespace sparky;
	using namespace graphics;
	Window window("sparky!!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 0.9f);

	while (!window.closed())
	{
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f,-0.5f);
		glVertex2f(0.5f,0.5f);
		glVertex2f(0.5f,-0.5f);
		glEnd();

		window.update();
	}
	return 0;
}
