attribute vec3 vertexPosition;
attribute vec2 vertexUV;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

varying vec2 tcoord;

void main(void) {
	mat4 MVP = P * V * M;

    gl_Position = MVP * vec4(vertexPosition, 1.0);
    tcoord = vertexUV;
}