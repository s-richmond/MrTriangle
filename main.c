#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#define WindowWidth 800
#define WindowHeight 600

void renderTriangle();
void msleep(int mseconds);
int main(int argc, char* argv[])
{

	printf("Gogogoooo!!\n");
	GLFWwindow *window;
	if(!glfwInit()) //hi
		return -1;

	window = glfwCreateWindow(WindowWidth, WindowHeight, "Hello World", NULL, NULL);
	if(!window){
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	
	while(!glfwWindowShouldClose(window))
	{
				
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		/*Keystate events*/
		if(glfwGetKey(window , GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window,1);
		
		double rate = 0.01;
		double angle = 2.5;
		
		if(glfwGetKey(window, 'W') == GLFW_PRESS)
			glTranslated(0,rate,0);

		if(glfwGetKey(window, 'A') == GLFW_PRESS)
			glRotated(angle,0,0,1);	
	
		if(glfwGetKey(window, 'D') == GLFW_PRESS)
			glRotated(-angle,0,0,1);

		if(glfwGetKey(window, 'S') == GLFW_PRESS)
			glTranslated(0,-rate,0);
		
					
		renderTriangle();

	
		/*update everything*/
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}

void renderTriangle()
{	
	glBegin(GL_LINE_LOOP);  
		glVertex2d(0,.035);
		glVertex2d(-.025,-.025);
		glVertex2d(.025,-.025);
	glEnd();
	glFlush();
}


