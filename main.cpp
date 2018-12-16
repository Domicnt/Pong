#include "Common.h"

int main(int argc, char args[]) {
	initialize.init();

	//event handler
	SDL_Event e;

	//set the timescale
	float timescale = 1;

	//randomness
	srand((unsigned)time(0));
	/*
	//create the ball
	Ball ball;
	//set dimensions
	ball.radius = 15;
	
	//create the players paddles
	Paddle player1, player2;
	//set dimensions
	player1.width = 20;
	player1.height = 100;

	player2.width = 20;
	player2.height = 100;

	//set other aspects
	move.resetBall(ball);
	move.resetPaddles(player1, player2);
	*/
	Ball ball = initialize.createBall();
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
		//collision.PointvsEdges;
		//move.moveBall(ball);

		//renders to screen
		SDL_RenderPresent(initialize.renderer);
	}
	//closes everything
	initialize.close();
	return 0;
}