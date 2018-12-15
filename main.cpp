#include "Common.h"

int main(int argc, char args[]) {
	initialize.init();

	//event handler
	SDL_Event e;

	//set the timescale
	float timescale = 1;

	//randomness
	srand((unsigned)time(0));

	//create the ball
	Ball ball;
	//set dimensions
	ball.radius = 15;
	
	//create the players paddles
	Paddle player1, player2;
	//set dimensions
	player1.width = 25;
	player1.height = 100;

	player2.width = 20;
	player2.height = 100;

	//set other aspects
	move.resetBall(ball);
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
		move.moveBall(ball);
		move.movePaddles(player1, player2, input.pressedKeys);

		collision.BallvsEdge(ball);
		move.resolveBallvsEdge(ball, collision.BallvsEdges);

		collision.BallvsPaddles(ball, player1, player2);
		move.resolveBallvsPaddles(ball, player1, player2, collision.BallvsPaddle);

		//draws game objects
		draw.drawBall(ball, initialize.renderer);
		draw.drawPaddle(player1, initialize.renderer);
		draw.drawPaddle(player2, initialize.renderer);
		//draws score
		draw.drawScore(collision.score, initialize.renderer);
		//renders to screen
		SDL_RenderPresent(initialize.renderer);
	}
	//closes everything
	initialize.close();
	return 0;
}