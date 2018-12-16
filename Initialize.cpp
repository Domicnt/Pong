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
