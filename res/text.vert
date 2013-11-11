#version 330 core
in vec3 vertexPosition;
in vec2 vertexUV;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out vec2 tcoord;

void main(void) {
	mat4 MVP = P * V * M;

    gl_Position = MVP * vec4(vertexPosition, 1.0);
    tcoord = vertexUV;
}