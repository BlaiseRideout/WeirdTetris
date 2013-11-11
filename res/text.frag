#version 330 core
in vec2 tcoord;

uniform sampler2D tex;

out vec4 fragColor;

void main(void) {
    fragColor = vec4(1.0f, 1.0f, 1.0f, texture2D(tex, vec2(tcoord.x, tcoord.y)).a);
}
