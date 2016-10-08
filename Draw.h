#include<math.h>
#include <GLFW/glfw3.h>
static const int width = 640;
static const int height = 480;
static float *pixels=  new float[width*height * 3];
class Draw{
public:


	void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
	{
		pixels[(i + width* j) * 3 + 0] = red;
		pixels[(i + width* j) * 3 + 1] = green;
		pixels[(i + width* j) * 3 + 2] = blue;
	}

	void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
	{
		Draw *_drawLine=new Draw;
		if (i0 == i1) 
		{
			for (int l = j0; l <= j1; l++)
			{
				_drawLine->drawPixel(i0, l, red, green, blue);
			}
		}
		else 
		{
			for (int i = i0; i <= i1; i++)
			{
				const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

				_drawLine->drawPixel(i, j, red, green, blue);

			}
		};

	}
	void drawCircle(const double& i, const double& j, const int& r, const float& red, const float& green, const float& blue)
	{
		Draw *_drawCircle=new Draw;
		double d = 0.0;
		float angle = 360.0;
		double x = 0, y = 0;
		for (angle = 0;angle < 360;angle++)
		{
			d = angle*(3.14 / 180);
			x = i + r*sin(d);
			y = j + r*cos(d);
			_drawCircle->drawPixel(x, y, red, green, blue);
			_drawCircle->drawPixel(x + 1, y, red, green, blue);
			_drawCircle->drawPixel(x, y - 1, red, green, blue);

		};

	}
		void getCursorPos1(GLFWwindow* window,double a,double b,int r){
		Draw *get1=new Draw;
	double xpos=0,ypos=0;
	glfwGetCursorPos(window,&xpos,&ypos);
	int distance=sqrt((xpos-a-r)*(xpos-a-r)+(ypos-b-r*2)*(ypos-b-r/2));
	if(distance<=3*r/2&&distance>=r/2){
		get1->drawCircle(a, b, r, 0.0f,0.0f, 1.0f);
	}
}
void getCursorPos2(GLFWwindow* window,double a,double b,int r){
	Draw *get2=new Draw;
	double xpos=0,ypos=0;
	glfwGetCursorPos(window,&xpos,&ypos);
	double distance=sqrt((xpos-a-r)*(xpos-a-r)+(ypos-b-r*8)*(ypos-b-r*8));
	if(distance<=r*3/2&&distance>=r/2){
		get2->drawCircle(a, b, r, 0.0f,0.0f, 1.0f);
	}
}
	void diagnol(){
		Draw *_diagnol=new Draw;

		_diagnol->drawLine(20, 150, 70, 200, 0.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 151, 70, 201, 1.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 152, 70, 202, 1.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 150, 70, 200, 0.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 151, 70, 201, 1.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 152, 70, 202, 1.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 370, 70, 420, 0.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 371, 70, 421, 1.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 372, 70, 422, 1.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 370, 70, 420, 0.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 371, 70, 421, 1.0f, 0.0f, 0.0f);
		_diagnol->drawLine(20, 372, 70, 422, 1.0f, 0.0f, 0.0f);

	}
	void twoCircle(){
		Draw *_twoCircle=new Draw;
		_twoCircle->drawCircle(170,170,20,1.0f,0.0f,0.0f);
		_twoCircle->drawCircle(170,400,20,1.0f,0.0f,0.0f);

	}
	void Square(){
		Draw *_square= new Draw;
		_square->drawLine(260, 150, 260, 200, 1.0f, 0.0f, 0.0f);
		_square->drawLine(260, 200, 310, 200, 1.0f, 0.0f, 0.0f);
		_square->drawLine(310, 150, 310, 200, 1.0f, 0.0f, 0.0f);
		_square->drawLine(260, 150, 310, 150, 1.0f, 0.0f, 0.0f);

		_square->drawLine(260, 370, 260, 420, 1.0f, 0.0f, 0.0f);
		_square->drawLine(260, 420, 310, 420, 1.0f, 0.0f, 0.0f);
		_square->drawLine(310, 370, 310, 420, 1.0f, 0.0f, 0.0f);
		_square->drawLine(260, 370, 310, 370, 1.0f, 0.0f, 0.0f);
	}
	void Cross(){
		Draw *_cross=new Draw;
		_cross->drawLine(370, 150, 415, 200, 1.0f, 0.0f, 0.0f);
		_cross->drawLine(370, 200, 415, 150, 1.0f, 0.0f, 0.0f);
		_cross->drawLine(370, 370, 415, 420, 1.0f, 0.0f, 0.0f);
		_cross->drawLine(370, 420, 415, 370, 1.0f, 0.0f, 0.0f);
	}
	void DownArrow(){
		Draw *_down=new Draw;
		_down->drawLine(490, 170, 510, 150, 1.0f, 0.0f, 0.0f);
		_down->drawLine(510, 150, 530, 170, 1.0f, 0.0f, 0.0f);
		_down->drawLine(510, 150, 510, 200, 1.0f, 0.0f, 0.0f);
		_down->drawLine(490, 400, 510, 370, 1.0f, 0.0f, 0.0f);
		_down->drawLine(510, 370, 530, 400, 1.0f, 0.0f, 0.0f);
		_down->drawLine(510, 370, 510, 420, 1.0f, 0.0f, 0.0f);
	}
	void RightArrow(){
		Draw *_right=new Draw;
		_right->drawLine(20, 60, 70, 60, 1.0f, 0.0f, 0.0f);
		_right->drawLine(50, 80, 70, 60,  1.0f, 0.0f, 0.0f);
		_right->drawLine(50, 40, 70, 60, 1.0f, 0.0f, 0.0f);
		_right->drawLine(20, 290, 70, 290, 1.0f, 0.0f, 0.0f);
		_right->drawLine(50, 310, 70, 290,  1.0f, 0.0f, 0.0f);
		_right->drawLine(50, 270, 70, 290, 1.0f, 0.0f, 0.0f);
	}
	void AAA(){
		Draw *_aaa=new Draw;
		_aaa->drawLine(155, 60, 185, 60 , 1.0f, 0.0f, 0.0f);
		_aaa->drawLine(135, 40, 170, 80, 1.0f, 0.0f, 0.0f);
		_aaa->drawLine(170, 80, 205, 40, 1.0f, 0.0f, 0.0f);
		_aaa->drawLine(155, 290, 185, 290 , 1.0f, 0.0f, 0.0f);
		_aaa->drawLine(135, 270, 170, 310, 1.0f, 0.0f, 0.0f);
		_aaa->drawLine(170, 310, 205, 270, 1.0f, 0.0f, 0.0f);
	}
	void Vertical(){
		Draw *_vertical=new Draw;
		_vertical->drawLine(290, 40, 290, 80 , 1.0f, 0.0f, 0.0f);
		_vertical->drawLine(290, 270, 290, 310 , 1.0f, 0.0f, 0.0f);
	}

	void LeftArrow(){
		Draw *_left=new Draw;
		_left->	drawLine(370, 60, 420, 60 , 1.0f, 0.0f, 0.0f);
		_left->drawLine(370, 60, 390, 80, 1.0f, 0.0f, 0.0f);
		_left->drawLine(370, 60, 390, 40,  1.0f, 0.0f, 0.0f);
		_left->	drawLine(370, 290, 420, 290 , 1.0f, 0.0f, 0.0f);
		_left->drawLine(370, 290, 390, 310, 1.0f, 0.0f, 0.0f);
		_left->drawLine(370, 290, 390, 270,  1.0f, 0.0f, 0.0f);
	}
	void UpArrow(){
		Draw *_up=new Draw;
		_up->	drawLine(510, 40, 510, 80 , 1.0f, 0.0f, 0.0f);
		_up->drawLine(490, 60, 510, 80, 1.0f, 0.0f, 0.0f);
		_up->drawLine(510, 80, 530, 60,  1.0f, 0.0f, 0.0f);
		_up->	drawLine(510, 270, 510, 310 , 1.0f, 0.0f, 0.0f);
		_up->drawLine(490, 290, 510, 310, 1.0f, 0.0f, 0.0f);
		_up->drawLine(510, 310, 530, 290,  1.0f, 0.0f, 0.0f);
	}


};