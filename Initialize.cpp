#include "Common.h"

void Initialize::init() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//Create window
	window = SDL_CreateWindow("SDL Testing things", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//Create vsynced renderer for window
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Initialize renderer color
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	(IMG_Init(imgFlags) & imgFlags);
}

/*
Paddle Initialize::createPaddle() {
	Paddle paddle;



	return paddle;
}*/

Ball Initialize::createBall() {
	Ball ball;
	ball.x = (float)round(SCREEN_WIDTH / 2);
	ball.y = (float)round(SCREEN_HEIGHT / 2);

	ball.radius = 20;

	ball.points[0].x = ball.x + ball.radius;
	ball.points[0].y = ball.y + ball.radius;
	ball.points[0].forceY = 1;
	ball.points[1].x = ball.x + ball.radius;
	ball.points[1].y = ball.y - ball.radius;
	ball.points[1].forceY = 1;
	ball.points[2].x = ball.x - ball.radius;
	ball.points[2].y = ball.y - ball.radius;
	ball.points[2].forceY = 1;
	ball.points[3].x = ball.x - ball.radius;
	ball.points[3].y = ball.y + ball.radius;
	ball.points[3].forceY = 1;

	ball.springs[0].a = &ball.points[0];
	ball.springs[0].b = &ball.points[1];
	ball.springs[0].optimalDistance = sqrt(pow(ball.points[0].x - ball.points[1].x,2) + pow(ball.points[0].y - ball.points[1].y, 2));
	ball.springs[1].a = &ball.points[1];
	ball.springs[1].b = &ball.points[2];
	ball.springs[1].optimalDistance = sqrt(pow(ball.points[1].x - ball.points[2].x, 2) + pow(ball.points[1].y - ball.points[2].y, 2));
	ball.springs[2].a = &ball.points[2];
	ball.springs[2].b = &ball.points[3];
	ball.springs[2].optimalDistance = sqrt(pow(ball.points[2].x - ball.points[3].x, 2) + pow(ball.points[2].y - ball.points[3].y, 2));
	ball.springs[3].a = &ball.points[3];
	ball.springs[3].b = &ball.points[0];
	ball.springs[3].optimalDistance = sqrt(pow(ball.points[3].x - ball.points[0].x, 2) + pow(ball.points[3].y - ball.points[0].y, 2));

	return ball;
}


void Initialize::close() {
	draw.free();

	//Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
