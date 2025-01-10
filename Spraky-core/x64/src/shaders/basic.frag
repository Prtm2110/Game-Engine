#version 330 core

in vec4 position; // Remove location qualifier

out vec4 color;

void main()
{
    color = vec4(1.0, 0.0, 0.0, 1.0); // Set the fragment color to red
}

