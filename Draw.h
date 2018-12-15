#include "Common.h"
#pragma once

class Draw {
	public:
		void drawBall(Ball a, SDL_Renderer* renderer);
		void drawPaddle(Paddle a, SDL_Renderer* renderer);

		void drawScore(short int score, SDL_Renderer* renderer);

		SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
		void free();

		void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, float angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	private:

		SDL_Texture* Texture;

		int textureWidth;
		int textureHeight;
};