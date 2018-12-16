#include "Common.h"

void Move::resetBall(Ball &ball) {
	
}

void Move::resetPaddles(Paddle &a, Paddle &b) {
	
}


void Move::moveBall(Ball &ball) {
	float k = 5;
	for (int i = 0; i < 4; i++) {//need to make the '4' into the size of the array of points or springs
		//change velocity by force
		ball.points[i].velX += ball.points[i].forceX;
		ball.points[i].velY += ball.points[i].forceY;
		
		//change position by velocity
		ball.points[i].x += ball.points[i].velX;
		ball.points[i].y += ball.points[i].velY;

		//calculate the length of springs
		int a = i;
		int b = a + 1;
		if (b = 5) b = 0;

		float deltaX = ball.points[a].x - ball.points[b].x;
		float deltaY = ball.points[a].y - ball.points[b].y;
		ball.springs[i].currentDistance = sqrt( pow(deltaX,2) + pow(deltaY,2));
		float delta = ball.springs[i].optimalDistance - ball.springs[i].currentDistance;

		deltaX /= ball.springs[i].currentDistance;
		deltaY /= ball.springs[i].currentDistance;

		if (ball.springs[i].currentDistance < ball.springs[i].optimalDistance) {
			ball.springs[i].a->forceX += delta * deltaX;
			ball.springs[i].a->forceY += delta * deltaY;
			ball.springs[i].b->forceX -= delta * deltaX;
			ball.springs[i].b->forceY -= delta * deltaY;
		} else if (ball.springs[i].currentDistance > ball.springs[i].optimalDistance) {
			ball.springs[i].a->forceX -= delta * deltaX;
			ball.springs[i].a->forceY -= delta * deltaY;
			ball.springs[i].b->forceX += delta * deltaX;
			ball.springs[i].b->forceY += delta * deltaY;
		}
	}
}

void Move::movePaddles(Paddle &a, Paddle &b, bool pressedKeys[4]) {

}