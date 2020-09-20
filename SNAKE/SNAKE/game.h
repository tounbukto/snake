#include"Snake.h"
#include "Snake.h"
#include "Apple.h"
class game
{

	public:
		game();
		~game();
		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void catchEvent();
		void update(Snake S, Apple A);
		void render(Snake S, Apple A);
		void clear();
		bool running();
		bool eat(Snake& S,Apple A);
		bool underSnake(Snake S, Apple& A);
		SDL_Renderer* getRender(){ return this->renderer; }

	private : 
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
		

	
};

