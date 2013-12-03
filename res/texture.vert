attribute vec3 vertexPosition;
attribute vec2 vertexUV;
attribute vec2 tilePosition;
attribute vec3 tileColor;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

varying vec2 tcoord;
varying vec3 color;

void main(void) {
	mat4 VP = P * V;

	vec3 position_world = (M * vec4(vertexPosition, 1.0)).xyz + vec3(25.0 * tilePosition.x, 25.0 * tilePosition.y, 0.0);

    gl_Position = VP * vec4(position_world, 1.0);
    tcoord = vertexUV;

    color = tileColor;
}