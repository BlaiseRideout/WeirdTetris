#version 130
in vec3 vertexPosition;
in vec2 vertexUV;
in vec2 tilePosition;
in vec3 tileColor;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out vec2 tcoord;
out vec3 color;

void main(void) {
	mat4 VP = P * V;

	vec3 position_world = (M * vec4(vertexPosition, 1.0f)).xyz + vec3(25 * tilePosition.x, 25 * tilePosition.y, 0.0f);

    gl_Position = VP * vec4(position_world, 1.0);
    tcoord = vertexUV;

    color = tileColor;
}