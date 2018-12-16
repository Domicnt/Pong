#include "Common.h"

void Draw::drawBall(Ball &a, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	for (int i = 0; i < 4; i++) {
		SDL_RenderDrawLine(renderer, (int)round(a.springs[i].a->x), (int)round(a.springs[i].a->y), (int)round(a.springs[i].b->x), (int)round(a.springs[i].b->y));
	}
}

void Draw::drawPaddle(Paddle a, SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

}

SDL_Texture* Draw::loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

void Draw::drawScore(short int score, SDL_Renderer * renderer) {
	int num1 = (int)round(floor(score / 10));
	int num2 = score;
	while (num2 >= 10) {
		num2 -= 10;
	}

	SDL_Rect number1;
	number1.w = 30;
	number1.h = 50;
	number1.y = 0;
	number1.x = num1 * 30;

	SDL_Rect number2;
	number2.w = 30;
	number2.h = 50;
	number2.y = 0;
	number2.x = num2 * 30;

	SDL_Rect destination1;
	destination1.w = 30;
	destination1.h = 50;
	destination1.x = SCREEN_WIDTH / 2 - destination1.w / 2 - 20;
	destination1.y = 30;
	SDL_RenderCopy(renderer, draw.loadTexture("Images/Numbers.png", renderer), &number1, &destination1);
	
	SDL_Rect destination2;
	destination2.w = 30;
	destination2.h = 50;
	destination2.x = SCREEN_WIDTH / 2 - destination2.w / 2 + 20;
	destination2.y = 30;
	SDL_RenderCopy(renderer, draw.loadTexture("Images/Numbers.png", renderer), &number2, &destination2);
}

void Draw::free() {
	if (Texture != nullptr)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
		textureWidth = 0;
		textureHeight = 0;
	}
}

void Draw::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, float angle, SDL_Point* center, SDL_RendererFlip flip) {
	//set rendering space
	SDL_Rect renderQuad = { x, y, textureWidth, textureHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(renderer, Texture, clip, &renderQuad, angle, center, flip);
}