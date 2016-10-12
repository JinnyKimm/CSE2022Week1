#include <cstring>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <vector>
#include "math.h"
const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];
using namespace std;
void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}
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
void drawCircle(const double& i, const double& j, const int& r, const float& red, const float& green, const float& blue)
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
class GeometricObjectInterface
{
public:
	virtual void draw()=0;
};

template<class T_OPERATION>
class GeometricObject:public GeometricObjectInterface
{
public:
	void draw()
	{
		T_OPERATION operation;
		operation.draw();
	}
};

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

class Box
{
public:

	void draw()
	{
		drawLine(270, 150, 270, 210, 0.0f, 0.0f, 0.0f);
		drawLine(270, 210, 330, 210, 0.0f, 0.0f, 0.0f);
		drawLine(330, 150, 330, 210, 0.0f, 0.0f, 0.0f);
		drawLine(270, 150, 330, 150, 0.0f, 0.0f, 0.0f);
	}
};

class Circle
{
public:

	void draw()
	{
		drawCircle(170, 170, 50, 0.0f, 0.0f, 0.0f);
	}
};
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

	//GeometricObjectInColor<void> *go=new GeometricObjectInColor<void>;
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();
		vector<GeometricObjectInterface*>  vector;
		vector.push_back(new GeometricObject<Box>);
		vector.push_back(new GeometricObject<Circle>);
		for(int i=0;i<vector.size();i++){
			vector[i]->draw();
		}
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
};