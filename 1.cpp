#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
     
#include<algorithm>// std::this_thread::sleep_for
       // std::chrono::seconds
#include "math.h"

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	 if (i0 == i1) {
  for (int l = j0; l <= j1; l++)
  {
   drawPixel(i0, l, red, green, blue);
  }
 }
 else {
  for (int i = i0; i <= i1; i++)
  {
   const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

   drawPixel(i, j, red, green, blue);

  }
 }

}

void circle(const double& i, const double& j, const int& r, const float& red, const float& green, const float& blue)
{
	double d = 0.0;
	float angle = 360.0;
	int x = 0, y = 0;
	for (angle = 0;angle < 360;angle++)
	{
		d = angle*(3.14 / 180);
		x = i + r*sin(d);
		y = j + r*cos(d);
		drawPixel(x, y, red, green, blue);
		drawPixel(x + 1, y, red, green, blue);
		drawPixel(x, y - 1, red, green, blue);

	}

}
void getCursorPos1(GLFWwindow* window,double a,double b,int r){
	double xpos=0,ypos=0;
	glfwGetCursorPos(window,&xpos,&ypos);
	int distance=sqrt((xpos-a-r)*(xpos-a-r)+(ypos-b-r*2)*(ypos-b-r/2));
	if(distance<=3*r/2&&distance>=r/2){
		circle(a, b, r, 0.0f,0.0f, 1.0f);
	}
}
void getCursorPos2(GLFWwindow* window,double a,double b,int r){
	double xpos=0,ypos=0;
	glfwGetCursorPos(window,&xpos,&ypos);
	double distance=sqrt((xpos-a-r)*(xpos-a-r)+(ypos-b-r*8)*(ypos-b-r*8));
	if(distance<=r*3/2&&distance>=r/2){
		circle(a, b, r, 0.0f,0.0f, 1.0f);
	}
}
void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	//for (int i = 0; i<width*height; i++) {
	//	pixels[i * 3 + 0] = 1.0f; // red 
	//	pixels[i * 3 + 1] = 1.0f; // green
	//	pixels[i * 3 + 2] = 1.0f; // blue
	//}

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

		// drawing a line
	//TODO: anti-aliasing
	
	 
		//TODO: try moving object


	//TODO: try moving object
}

int main(void)
{
	GLFWwindow* window;
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glClearColor(1, 1, 1, 1); // while background


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();
				//thickner line
			drawLine(20, 150, 70, 200, 0.0f, 0.0f, 0.0f);
			drawLine(20, 151, 70, 201, 1.0f, 0.0f, 0.0f);
			drawLine(20, 152, 70, 202, 1.0f, 0.0f, 0.0f);
			circle(50, 170, 50, 1.0f, 0.0f, 0.0f);
	    	getCursorPos1(window,50,170,50);


			//two circle
			circle(170,170,20,1.0f,0.0f,0.0f);
			circle(170, 170, 50, 1.0f, 0.0f, 0.0f);
			getCursorPos1(window,170,170,50);
	
	//Square
	drawLine(265, 150, 265, 200, 1.0f, 0.0f, 0.0f);
	drawLine(265, 200, 310, 200, 1.0f, 0.0f, 0.0f);
	drawLine(310, 150, 310, 200, 1.0f, 0.0f, 0.0f);
	drawLine(265, 150, 310, 150, 1.0f, 0.0f, 0.0f);
	circle(290, 170, 50, 1.0f, 0.0f, 0.0f);
	getCursorPos1(window,290,170,50);

	//cross
	drawLine(405, 150, 455, 200, 1.0f, 0.0f, 0.0f);
	drawLine(405, 200, 455, 150, 1.0f, 0.0f, 0.0f);
	circle(430, 170, 50, 1.0f, 0.0f, 0.0f);
	getCursorPos1(window,430,170,50);

	//down arrow
	drawLine(530, 170, 550, 150, 1.0f, 0.0f, 0.0f);
	drawLine(550, 150, 570, 170, 1.0f, 0.0f, 0.0f);
	drawLine(550, 150, 550, 200, 1.0f, 0.0f, 0.0f);
	circle(550, 170, 50, 1.0f, 0.0f, 0.0f);
	getCursorPos1(window,550,170,50);

	//right arrow
	drawLine(20, 60, 70, 60, 1.0f, 0.0f, 0.0f);
	drawLine(50, 80, 70, 60,  1.0f, 0.0f, 0.0f);
	drawLine(50, 40, 70, 60, 1.0f, 0.0f, 0.0f);
	circle(50, 60, 50, 1.0f, 0.0f, 0.0f);
		getCursorPos2(window,50,60,50);

	//A
	drawLine(155, 60, 185, 60 , 1.0f, 0.0f, 0.0f);
	drawLine(135, 40, 170, 80, 1.0f, 0.0f, 0.0f);
	drawLine(170, 80, 205, 40, 1.0f, 0.0f, 0.0f);
	circle(170, 60, 50, 1.0f, 0.0f, 0.0f);
		getCursorPos2(window,170,60,50);

	drawLine(290, 40, 290, 80 , 1.0f, 0.0f, 0.0f);
	circle(290, 60, 50, 1.0f, 0.0f, 0.0f);
		getCursorPos2(window,290,60,50);

	//left arrow
	drawLine(405, 60, 455, 60 , 1.0f, 0.0f, 0.0f);
	drawLine(405, 60, 425, 80, 1.0f, 0.0f, 0.0f);
	drawLine(405, 60, 425, 40,  1.0f, 0.0f, 0.0f);
	circle(430, 60, 50, 1.0f, 0.0f, 0.0f);
			getCursorPos2(window,430,60,50);

	//up arrow
	drawLine(550, 40, 550, 80 , 1.0f, 0.0f, 0.0f);
	drawLine(530, 60, 550, 80, 1.0f, 0.0f, 0.0f);
	drawLine(550, 80, 570, 60,  1.0f, 0.0f, 0.0f);
	circle(550, 60, 50, 1.0f, 0.0f, 0.0f);		
	getCursorPos2(window,550,60,50);

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}

