/*
  Dreiecke
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <glew.h>
#include <freeglut.h>
#include <FreeImage.h>

GLuint loadShaders(const char* vertexFilePath,
 const char* fragmentFilePath,
 const char* geometryFilePath,
 const char* tesscontrolFilePath,
 const char* tessevaluationFilePath,
 const char* computeFilePath);
GLint height=100,width=100;
enum VAO_IDs {Triangles,NumVAOs};
enum Buffer_IDs {ArrayBuffer,NumBuffers};
enum Attrib_IDs {vPosition,vColor};
GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
const GLuint NumVertices=6;
GLuint program; 

void init(void)
{printf("\n%s",(char*)glGetString(GL_RENDERER));
 printf("\n%s",(char*)glGetString( GL_VERSION));
 printf("\n%s\n",(char*)glGetString( GL_SHADING_LANGUAGE_VERSION));
 program = loadShaders("Programme/Dreiecke.vs", "Programme/Dreiecke.fs", "", "", "", "");
 glUseProgram(program);
 glGenBuffers(NumBuffers,Buffers); //Bereitstellen von namen f�r Buffer Objects
 glGenVertexArrays(NumVAOs,VAOs);//Bereitstellen von namen f�r Vertex Array Objects

 GLfloat vertices[NumVertices][2]={
  {-0.90,-0.90},{0.85,-0.90},{-0.90,0.85},{0.90,-0.85},{0.90,0.90},{-0.85,0.90}};
 glBindVertexArray(VAOs[Triangles]);//Erzeugen und Aktivieren eines Vertex Array Objects
 glBindBuffer(GL_ARRAY_BUFFER,Buffers[ArrayBuffer]);//Erzeugen und Aktivieren eines Buffer Objects
 glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);//Zuweisung von Server-Speicher zur Datenspeicherung
 glVertexAttribPointer(vPosition,2,GL_FLOAT,GL_FALSE,0,(void*)0);//Spezifizieren der Shader Variable f�r das Buffer Object
 glEnableVertexAttribArray(vPosition); }//Aktivieren einer Shader Varibale

void display(void)
{glClear(GL_COLOR_BUFFER_BIT); //L�schen des Frame Buffers
  glBindVertexArray(VAOs[Triangles]);//Erzeugen und Aktivieren eines Vertex Array Objects
  glVertexAttrib3f(vColor,1,0,0);//Spezifikation einer Shader Variable f�r konst. Wert
  glDrawArrays(GL_TRIANGLES,0,NumVertices/2);
  glVertexAttrib3f(vColor,0,1,0);
  glDrawArrays(GL_LINE_LOOP,3,NumVertices/2);
 glFlush(); }

void reshape(int w, int h) {
  width=w;
  height=h; }

int main(int argc, char** argv) {
	glutInit(&argc, argv);//Initialisierung von HLUT mit Argument�bergabe
	glutInitDisplayMode(GLUT_RGBA);//Initialisieren von Anzeigepuffern der Grafikkarte
	glutInitWindowSize(512,512);//Festlegen der Fenstergr��e
	glutInitContextVersion(4,5);  // (4,2) (3,3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	 //GLUT_COMPATIBILITY_PROFILE
	glutCreateWindow(argv[0]);//Erzeugen eines OpenGL-f�higen Fensters
	glewExperimental=GL_TRUE;
	if (glewInit()) printf("Error"); 
	init();
	glutReshapeFunc(reshape);//Setzen der Fenster�nderung(reshape) Callback Funktion
	glutDisplayFunc(display);//Setzen der Fenster�nderung(display) Callback Funktion
	glutMainLoop();
}
