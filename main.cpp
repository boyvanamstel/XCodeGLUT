#include <iostream>

#include <stdlib.h>
#include <GLUT/glut.h>

#include <math.h>

#include "Renderer.h"

bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)

GLfloat redDiffuseMaterial[] = {1.0, 0.0, 0.0}; //set the material to red
GLfloat whiteSpecularMaterial[] = {1.0, 1.0, 1.0}; //set the material to white
GLfloat greenEmissiveMaterial[] = {0.0, 1.0, 0.0}; //set the material to green
GLfloat whiteSpecularLight[] = {1.0, 1.0, 1.0}; //set the light specular to white
GLfloat blackAmbientLight[] = {0.0, 0.0, 0.0}; //set the light ambient to black
GLfloat whiteDiffuseLight[] = {1.0, 1.0, 1.0}; //set the diffuse light to white
GLfloat blankMaterial[] = {0.0, 0.0, 0.0}; //set the diffuse light to white
GLfloat mShininess[] = {128}; //set the shininess of the material

float xpos = 0, ypos = 0, zpos = 5.0f, xrot = 0, yrot = 0;

Renderer r;

#define BUFFER_SIZE (4096 * 8)

void camera(void) {
    glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
}

void keyOperations(void) {
	if (keyStates[GLUT_KEY_LEFT]) { // If the left arrow key has been pressed
		// Perform left arrow key operations
	}
}

void display(void) {
	keyOperations();
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our <a title="window" href="http://www.swiftless.com/tutorials/opengl/window.html">window</a> to red
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
	
	camera();
	
	r.display();
	
	glutSwapBuffers();	
}
void reshape(int width, int height) {
	r.reshape(width, height);
}

void keyPressed(unsigned char key, int x, int y) {
	keyStates[key] = true; // Set the state of the current key to pressed
	
	//printf("KEY PRESSED!!!1");
	
	if (key=='q') {
		xrot += 1;
		if (xrot >360) xrot -= 360;
	}
	if (key=='z') {
		xrot -= 1;
		if (xrot < -360) xrot += 360;
	}
	if (key=='w') {
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f); 
		xpos += float(sin(yrotrad)) ;
		zpos -= float(cos(yrotrad)) ;
		ypos -= float(sin(xrotrad)) ;
	}
	if (key=='s') {
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f); 
		xpos -= float(sin(yrotrad));
		zpos += float(cos(yrotrad)) ;
		ypos += float(sin(xrotrad));
	}
	if (key=='d') {
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * 0.2;
		zpos += float(sin(yrotrad)) * 0.2;
	}
	if (key=='a') {
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad)) * 0.2;
		zpos -= float(sin(yrotrad)) * 0.2;
	}
	if (key=='1') {
		r.setOffColor(1.0f, 1.0f, 1.0f);
	}
	if (key=='2') {
		r.setOffColor(0.5f, 0.0f, 0.0f);
	}
	
	
	if (key==27) {
		exit(0);
	}
	
}

void keyUp(unsigned char key, int x, int y) {
	keyStates[key] = false; // Set the state of the current key to not pressed
}

void initSound() {

}

int main(int argc, char **argv) {
	
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize (500, 500); // Set the width and height of the window
	glutInitWindowPosition (100, 100); // Set the position of the window
	glutCreateWindow ("Awesome OpenGL window"); // Set the title for the window
	
	glEnable(GL_BLEND); // Enable blending
	
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST); // Enable depth support
	
	glEnable (GL_LIGHTING); // Enable lights 
	glEnable(GL_LIGHT0); 
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);	
	glEnable(GL_COLOR_MATERIAL); // Enable color material
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
	
	initSound();
	
	/*
	 GLfloat density = 0.3;
	 GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
	 glEnable (GL_FOG);
	 glFogi (GL_FOG_MODE, GL_EXP2);
	 glFogfv (GL_FOG_COLOR, fogColor);
	 glFogf (GL_FOG_DENSITY, density);
	 glHint (GL_FOG_HINT, GL_NICEST);
	 */
	
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering
	
	glutIdleFunc(display); // Tell GLUT to use the method "display" as our idle method as well
	
	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping
	
	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
	glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events
	
	glutMainLoop(); // Enter GLUT's main loop
}
