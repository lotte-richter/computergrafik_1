#version 450 core  // 420, 330 core , compatibility
in vec4 Color;
out vec4 fColor;
void main() {
 //fColor = Color; 
 fColor = vec4(Color.r ,Color.g, Color.b, 0.5); //Transparenz festgelegt
 }