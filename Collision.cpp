#include "Common.h"

void Collision::BallvsEdge(Ball ball) {
	//reset collision variables
	BallvsEdges[0] = false;
	BallvsEdges[1] = false;
	BallvsEdges[2] = false;
	BallvsEdges[3] = false;

	if (ball.posY - ball.radius <= 0) {
		//colliding with the top
		BallvsEdges[1] = true;
	} else if (ball.posY + ball.radius >= SCREEN_HEIGHT) {
		//colliding with the bottom
		BallvsEdges[3] = true;
	}
	if (ball.posX - ball.radius <= 0) {
		//colliding with the left
		BallvsEdges[0] = true;
		score = 0;
	} else if (ball.posX + ball.radius >= SCREEN_WIDTH) {
		//colliding with the right
		BallvsEdges[2] = true;
		score = 0;
	}
}

void Collision::BallvsPaddles(Ball ball, Paddle a, Paddle b) {
	BallvsPaddle[0] = false;
	BallvsPaddle[1] = false;
	
	if (ball.posX + ball.radius >= b.posX - b.width / 2 && ball.posY + ball.radius >= b.posY - b.height / 2 && ball.posY - ball.radius <= b.posY + b.height / 2) {
		BallvsPaddle[0] = true;
		score++;
	} else if (ball.posX - ball.radius <= a.posX + b.width / 2 && ball.posY + ball.radius >= a.posY - a.height / 2 && ball.posY - ball.radius <= a.posY + a.height / 2) {
		BallvsPaddle[1] = true;
		score++;
	}
}
