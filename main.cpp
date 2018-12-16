#include "Common.h"

int main(int argc, char args[]) {
	initialize.init();

	//event handler
	SDL_Event e;

	//set the timescale
	float timescale = 1;

	//randomness
	srand((unsigned)time(0));
	
	Ball ball;

	//Paddle player1 = initialize.createPaddle();
	//Paddle player2 = initialize.createPaddle();

	//quit flag
	bool quit = false;
	//game loop
	while (!quit) {
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		SDL_SetRenderDrawColor(initialize.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(initialize.renderer);
		SDL_SetRenderDrawColor(initialize.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

		input.keyboardInput(e);
		
		draw.drawBall(ball, initialize.renderer);
		for (int i = 0; i < 4; i++) {
			collision.PointvsEdges(ball.points[i]);
		}
		
		move.moveBall(ball);

		//renders to screen
		SDL_RenderPresent(initialize.renderer);
	}
	//closes everything
	initialize.close();
	return 0;
}