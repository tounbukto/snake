#include "game.h"
game::game() { window = NULL; renderer = NULL; isRunning = false; }
game::~game(){}
void game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		int flags = 0;
		if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		isRunning = true;
	}
	else isRunning = false;
}

void game::catchEvent() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{	
		case SDL_QUIT :
			isRunning = false;
			break;
		default:
			break;
	}
}

void game::update(Snake S, Apple A) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 51, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &(A.getApple()));
	SDL_SetRenderDrawColor(renderer, 6, 111, 27, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &(S.getShape(0)));
	SDL_SetRenderDrawColor(renderer, 10, 233, 55, SDL_ALPHA_OPAQUE);
	for (int i = 1; i < S.getTaille(); i++)
	{
		SDL_RenderFillRect(renderer, &(S.getShape(i)));
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}
void game::render(Snake S, Apple A) {
	SDL_RenderClear(renderer);
	update(S, A);
	SDL_RenderPresent(renderer);
}

void game::clear() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool game::running() { return isRunning; }

bool game::eat(Snake& S,Apple A) {
	SDL_Rect tmpApple = A.getApple();
	int a = (S.getShape(0).y - tmpApple.y);
	int b = (S.getShape(0).x - tmpApple.x);


	if (a * a + b * b < 400) {

		S.setTaille();
		return true;
	}
	return false;
};

bool game::underSnake(Snake S, Apple& A) {
	 for (int i = 0; i < S.getTaille(); ++i) {
		 int sx = S.getShape(i).x;
		 int sy = S.getShape(i).y;
		 int ax = A.getApple().x;
		 int ay = A.getApple().y;
		 if ((sx - ax) * (sx - ax) + (sy - ay) * (sy - ay) < 400)return true;
	}
	 return false;
}