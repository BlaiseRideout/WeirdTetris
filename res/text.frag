varying vec2 tcoord;

uniform sampler2D tex;

void main(void) {
    gl_FragColor = vec4(1.0, 1.0, 1.0, texture2D(tex, vec2(tcoord.x, tcoord.y)).a);
}
