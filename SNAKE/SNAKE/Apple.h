#pragma once
#include "SDL.h"
class Apple
{
	public  :
		Apple() { shape.w = shape.h= 20; };
		~Apple() {};
		void Creat();
		void update();
		SDL_Rect getApple(){ return shape; }
	private :
		SDL_Rect shape;
};

