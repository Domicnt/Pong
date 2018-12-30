#include "Common.h"

int main(int argc, char args[]) {
	initialize.init();

	//event handler
	SDL_Event e;

	//set the timescale - not currently in use
	float timescale = 1;

	Ball ball;

	Paddle player1, player2;
	move.resetPaddles(player1, player2);

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
		
		collision.PaddlesvsEdge(player1, player2);
		collision.BallvsPaddles(ball, player1, player2);
		collision.BallvsEdge(ball);

		move.movePaddles(player1, player2, input.pressedKeys);
		move.moveBall(ball);

		draw.drawBall(ball, initialize.renderer);
		draw.drawPaddle(player1, initialize.renderer);
		draw.drawPaddle(player2, initialize.renderer);

		draw.drawScore(initialize.renderer, collision.score);

		//renders to screen
		SDL_RenderPresent(initialize.renderer);
	}
	//closes everything
	initialize.close();
	return 0;
}