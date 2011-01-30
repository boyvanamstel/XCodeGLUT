/*
 *  Renderer.h
 *  XCodeGLUT
 *
 *  Created by Boy van Amstel on 05-10-10.
 *  Copyright 2010 boyvanamstel.nl. All rights reserved.
 *
 */

#include <stdlib.h>
#include <GLUT/glut.h>

class Renderer {
	public:
		Renderer();
		void display(void);
		void reshape (int width, int height);	
		void setOffColor(float red, float green, float blue);
	private:
		//bool movingUp = false; // Whether or not we are moving up or down
		float yLocation; // Keep track of our position on the y axis.
		float yRotationAngle; // The angle of rotation for our object
		float r, g, b;
};
