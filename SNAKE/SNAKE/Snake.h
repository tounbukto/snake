#pragma once
#include"SDL.h"
class Snake
{
	public :
		Snake();
		~Snake();
		void update();
		void move();
		bool death();
		int getTaille(){ return taille; }
		SDL_Rect getShape(int i) { return shape[i]; }
		void setTaille() { taille++; }


	private :
		int taille = 3;
		SDL_Rect  shape[100];
};

