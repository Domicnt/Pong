#include "Common.h"
#pragma once

class Initialize {
	public:
		void init();

		//Paddle createPaddle();
		Ball createBall();

		void close();
		
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		SDL_Texture* texture = nullptr;
	private:

		const int SCREEN_WIDTH = 640; //1280 by 720 is screen size for this laptop
		const int SCREEN_HEIGHT = 360;

};