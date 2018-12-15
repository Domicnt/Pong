#include "Common.h"

void Move::resetBall(Ball &ball) {
	ball.posX = SCREEN_WIDTH / 2;
	ball.posY = SCREEN_HEIGHT / 2;

	//from 135 to 225 and from 45 to 315
	if ((rand() % 2) + 1 == 1) {
		ball.angle = (rand() % 90) + 135 + 1;
	} else {
		ball.angle = (rand() % 90) + 315 + 1;
	}
	if (ball.angle >= 360) ball.angle -= 360;
	ball.velocity = maxBallVel;

	ball.xVel = 0;
	ball.yVel = 0;
}

void Move::resetPaddles(Paddle &a, Paddle &b) {
	a.posY = SCREEN_HEIGHT / 2;
	a.posX = 32 + a.width / 2;
	a.velocity = 0;

	b.posY = SCREEN_HEIGHT / 2;
	b.posX = SCREEN_WIDTH - 32 - b.width / 2;
	b.velocity = 0;
}


void Move::moveBall(Ball &ball) {
	//actual movement
	ball.posX += ball.velocity * cos(Pi / 180 * ball.angle);
	ball.posY += ball.velocity * sin(Pi / 180 * ball.angle);

	//gravity and such
	ball.posX += ball.xVel;
	ball.posY += ball.yVel;
}

void Move::movePaddles(Paddle &a, Paddle &b, bool pressedKeys[4]) {

	if (pressedKeys[0] == true && a.posY - a.height / 2 >= 0) {
		a.posY -= maxPaddleVel;
	} if (pressedKeys[1] == true && a.posY + a.height / 2 <= SCREEN_HEIGHT) {
		a.posY += maxPaddleVel;
	}
	if (pressedKeys[2] == true && b.posY - b.height / 2 >= 0) {
		b.posY -= maxPaddleVel;
	} if (pressedKeys[3] == true && b.posY + b.height / 2 <= SCREEN_HEIGHT) {
		b.posY += maxPaddleVel;
	}
}


void Move::resolveBallvsEdge(Ball &ball, bool BallvsEdges[4]) {
	
	if (BallvsEdges[1] == true && ball.angle > 180) {
		//colliding with top
		ball.posY = ball.radius;
		ball.angle = 360 - ball.angle;
	} else if (BallvsEdges[3] == true && ball.angle < 180) {
		//colliding with bottom
		ball.posY = SCREEN_HEIGHT - ball.radius;
		ball.angle = 360 - ball.angle;
	} if (BallvsEdges[0] == true) {
		//colliding with left
		ball.posX += SCREEN_WIDTH;
		move.resetBall(ball);
	} else if (BallvsEdges[2] == true) {
		//colliding with right
		ball.posX -= SCREEN_WIDTH;
		move.resetBall(ball);
	}
	
	if (ball.angle >= 360) ball.angle -= 360;
	else if (ball.angle < 0) ball.angle += 360;
}

void Move::resolveBallvsPaddles(Ball &ball, Paddle &a, Paddle &b, bool BallvsPaddle[2]) {
	if (BallvsPaddle[0] == true) {
		ball.angle = 180 - ball.angle;
	} else if (BallvsPaddle[1] == true) {
		ball.angle = 180 - ball.angle;
	}
}