#version 330 core

in vec4 texcoord;
out vec4 frag_color;
uniform sampler2D texture;
out vec2 coords;

void main(){
    //frag_color = vec4(1.0, 0.0, 0.0, 1.0);
    coords = texcoord.xz;
    frag_color = texture2D(texture, coords);
}