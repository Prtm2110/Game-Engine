#version 330 core

layout(location = 0) in vec3 position;

uniform mat4 pr_matrix;
uniform mat4 ml_matrix;

void main() {
    gl_Position = pr_matrix * ml_matrix * vec4(position, 1.0);
}
