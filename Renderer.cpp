/*
 *  Renderer.cpp
 *  XCodeGLUT
 *
 *  Created by Boy van Amstel on 05-10-10.
 *  Copyright 2010 boyvanamstel.nl. All rights reserved.
 *
 */

#include "Renderer.h"

Renderer::Renderer() {
	//movingUp = false; // Whether or not we are moving up or down
	yLocation = 0.0f; // Keep track of our position on the y axis.
	yRotationAngle = 0.0f; // The angle of rotation for our object
	r = g = b = 1.0f;
};

void Renderer::setOffColor(float red, float green, float blue) {
	r = red;
	g = green;
	b = blue;
}

void Renderer::display(void) {
	
	glRotatef(yRotationAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yRotationAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(yRotationAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidCube(2);

	glRotatef(2 * yRotationAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(2 * yRotationAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(2 * yRotationAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(r, g, b);
    glutSolidCube(2);
	
	glRotatef(-yRotationAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(-yRotationAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(-yRotationAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidCube(2);

	glRotatef(2 * -yRotationAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(2 * -yRotationAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(2 * -yRotationAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(r, g, b);
    glutSolidCube(2);
	
	/*
	 if (movingUp) // If we are moving up
	 yLocation -= 0.005f; // Move up along our yLocation
	 else // Otherwise
	 yLocation += 0.005f; // Move down along our yLocation
	 
	 if (yLocation < -3.0f) // If we have gone up too far
	 movingUp = false; // Reverse our direction so we are moving down
	 else if (yLocation > 3.0f) // Else if we have gone down too far
	 movingUp = true; // Reverse our direction so we are moving up
	 */
	
	yRotationAngle += 0.05f; // Increment our rotation value
	
	if (yRotationAngle > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
		yRotationAngle -= 360.0f; // Subtract 360 degrees off of our rotation
	
}

void Renderer::reshape (int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
	
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
	
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}
