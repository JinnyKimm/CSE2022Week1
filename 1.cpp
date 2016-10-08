#pragma once
#include <string>
#include <cstring>
#include < cstdlib >
#include <stdlib.h>	
#include <GLFW/glfw3.h>
#include <algorithm>
#include "drawBuffer.h"
int main()
{
	GLFWwindow* window;
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "2015112140", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glClearColor(1, 1, 1, 1); // while background
	while (!glfwWindowShouldClose(window))
	{

		drawBuffer *test= new drawBuffer;

		test->drawOnPixelBuffer();
		for(int b=60;b<410;b++){

			for(int a=50;a<600;a++){
				test->drawCircle(a,b,50,1.0f,0.0f,0.0f);
				a+=115;
			};
			b+=110;
		};


		test->diagnol();
		test->getCursorPos1(window,50,170,50);	test->getCursorPos2(window,50,600,50);
		test->twoCircle();
		test->getCursorPos1(window,165,170,50);test->getCursorPos2(window,170,600,50);
		test->Square();
		test->getCursorPos1(window,285,170,50);
		test->Cross();
			test->getCursorPos1(window,398,170,50);
		test->DownArrow();
					test->getCursorPos1(window,512,170,50);
		test->RightArrow();
							test->getCursorPos2(window,50,60,50);
		test->AAA();
			test->getCursorPos2(window,165,60,50);
		test->Vertical();
			test->getCursorPos2(window,285,60,50);
		test->LeftArrow();
			test->getCursorPos2(window,398,60,50);
		test->UpArrow();
			test->getCursorPos2(window,512,60,50);
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	};
	glfwTerminate();
	delete[] pixels; // or you may reuse pixels array 
	return 0;

}