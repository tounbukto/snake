#include "Apple.h"
#include<stdlib.h>
#include<time.h>

void Apple::Creat() {
	srand(time(0));
		shape.x = ((rand() % (600 - shape.w))* (rand() % (600 - shape.w)))%(600 - shape.w);
		shape.x /= 20;
		shape.x *= 20;
		shape.y = ((rand() % (400 - shape.h)) * (rand() % (400 - shape.h))) % (400 - shape.h);
		shape.y /= 20;
		shape.y *= 20;
}

void Apple::update() {
	shape.x = (shape.x + shape.w ) % (600 - shape.w);
	shape.y = (shape.y + shape.y) % (400 - shape.h);
}