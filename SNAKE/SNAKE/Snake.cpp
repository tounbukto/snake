#include "Snake.h"
#define SW 20
#define SH 20
#define SCW 600
#define SCH 400
Snake::Snake(){
	for (int i = 0; i < taille; i++) {
		shape[i].w = SW;
		shape[i].h = SH;
		shape[i].x = SCW/2-SW - i * SW;
		shape[i].y = SCH/2-SH ;
	}
}
Snake::~Snake() {}
int oldstate = 1;


void  Snake::update() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_d :
					if (oldstate != 2) {oldstate = 1;}break;
				case SDLK_a:
					if (oldstate != 1) {oldstate = 2;}break;
				case SDLK_s:
					if (oldstate != 4) {oldstate = 3;}break;
				case SDLK_w:
					if (oldstate != 3) {oldstate = 4;}break;
				default :
					break;
			}
	default:
		break;
	}
}

void Snake::move() {
	update();
	for(int i= taille-1 ; i>0 ; --i){
		shape[i] = shape[i -1];
	}
	if		(oldstate == 1)shape[0].x = (shape[0].x + shape[0].w + SCW ) % (SCW);
	else if (oldstate == 2)shape[0].x = (shape[0].x - shape[0].w + SCW ) % (SCW);
	else if (oldstate == 3)shape[0].y = (shape[0].y + shape[0].h + SCH ) % (SCH);
	else if (oldstate == 4)shape[0].y = (shape[0].y - shape[0].h + SCH ) % (SCH);
}

bool Snake::death() {
	for (int i = 1;i < taille; ++i) {
		int a = shape[i].x - shape[0].x;
		int b = shape[i].y - shape[0].y;
			if (a*a+b*b < 380) {
				return true;
			}
		
	}
	return false;
}




