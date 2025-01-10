#version 330 core

in vec4 position; // Remove location qualifier

out vec4 color;

uniform vec4  colour;
uniform vec2 ligh_Pos;

in vec4 pos;

void main()
{
    float intensity = 1.0 / length(pos.xy - pos.xy);
    color = colour * intensity;

}

