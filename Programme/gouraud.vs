
#version 450 core  // 420, 330 core , compatibility
layout(location=0) in vec4 vPosition;
layout(location=1) in vec4 vColor;
out vec4 color;
void main() {
color=vColor;
gl_Position=vPosition; }