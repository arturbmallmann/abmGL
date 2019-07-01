#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main() {
 vec2 st = gl_FragCoord.xy/u_resolution;
 gl_FragColor = vec4(0.0,0.0,st.x,1.0);
}