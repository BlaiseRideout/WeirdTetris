#version 130
in vec2 tcoord;
in vec3 color;

uniform sampler2D tex;

out vec4 fragColor;

void main(void) {
    fragColor = vec4(texture2D(tex, vec2(tcoord.x, tcoord.y)).r * color.r, texture2D(tex, vec2(tcoord.x, tcoord.y)).g * color.g, texture2D(tex, vec2(tcoord.x, tcoord.y)).b * color.b, 1.0f);
}
