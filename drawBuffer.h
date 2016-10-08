#pragma once
#include"Draw.h"
#include <stdlib.h>	
#include <algorithm>
class drawBuffer: public Draw
{
public:
	void drawOnPixelBuffer()
	{
		Draw *bufferr=new Draw;
		//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	const int i = rand() % width, j = rand() % height;
	bufferr->drawPixel(i, j, 0.0f, 0.0f, 0.0f);

		// drawing a line
	//TODO: anti-aliasing
	
	 
		//TODO: try moving object


	//TODO: try moving object
	};
};