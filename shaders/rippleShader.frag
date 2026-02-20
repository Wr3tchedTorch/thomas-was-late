varying vec4 vColor;
varying vec2 vTexCoord;

uniform sampler2D uTexture;
uniform float uTime;

void main() {
    vec2 coord = vTexCoord;
    
    float wave = sin(coord.y * 10.0 + uTime * 2.0);
    
    coord.x += wave * 0.0025; 

    gl_FragColor = vColor * texture2D(uTexture, coord);
}