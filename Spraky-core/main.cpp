#include <iostream>
#include <GL/glew.h>
#include "x64/src/graphics/window.h"
#include "x64/src/maths/maths.h"
#include "x64/src/utils/fileutils.h"
#include "x64/src/graphics/shader.h"    
#include "x64/src/graphics/buffers/buffer.h"
#include "x64/src/graphics/buffers/vertexarray.h"
#include "x64/src/graphics/buffers/indexbuffer.h"
#include "x64/src/graphics/renderable2d.h"
#include "x64/src/graphics/renderer2d.h"
#include "x64/src/graphics/simple2drenderer.h"


int main() {
    using namespace sparky;
    using namespace graphics;
    using namespace maths;
    using namespace utils;

    std::cout << "Creating window..." << std::endl;
    Window window("Sparky!!", 1280, 800);
   
    glClearColor(0.2f, 1.3f, 0.8f, 0.9f);


    mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

   
    
    std::cout << "Loading shader..." << std::endl;
    Shader shader("x64/src/shaders/basic.vert", "x64/src/shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
    shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 4.5, 0)));
    
    Renderable2D sprite(vec3(4, 1, 0), vec2(4, 4), vec4(1, 0, 1, 1), shader);
	Simple2DRenderer renderer;

    shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

    
    
    
    
    std::cout << "Entering main loop..." << std::endl;
    while (!window.closed()) {
      
        window.clear(); 

        double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2(x * 16.0f / 1280.0f, 9.0f - y * 9.0f / 800.0f)); // Center of the square
        
		renderer.submit(&sprite);
		renderer.flush();
       
 
      
        window.update();
    }
    return 0;
}
