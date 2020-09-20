#include "SDL.h"
#include"game.h"
using namespace std;
int main(int argc ,char ** argv )
{
    game MyGame;
    Snake snake;
    Apple apple;
    apple.Creat();
    MyGame.init("SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
    
    while (MyGame.running()) {
        if (MyGame.eat(snake,apple)) {
            apple.Creat();
            while (MyGame.underSnake(snake, apple))
                apple.update();
        }
        snake.move();
        MyGame.render(snake, apple);
        MyGame.catchEvent();
        if (snake.death())break;
        SDL_Delay(120);
    }
    MyGame.clear();
    return 0;
}

