varying vec2 tcoord;
varying vec3 color;

uniform sampler2D tex;

void main(void) {
    gl_FragColor = vec4(texture2D(tex, vec2(tcoord.x, tcoord.y)).r * color.r, texture2D(tex, vec2(tcoord.x, tcoord.y)).g * color.g, texture2D(tex, vec2(tcoord.x, tcoord.y)).b * color.b, 1.0);
}
