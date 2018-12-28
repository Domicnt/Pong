#include "Common.h"

void Move::resetBall(Ball &ball) {
	
}

void Move::resetPaddles(Paddle &a, Paddle &b) {
	a.x = 25;
	a.y = SCREEN_HEIGHT / 2;

	b.x = SCREEN_WIDTH - 25;
	b.y = SCREEN_HEIGHT / 2;
}


void Move::moveBall(Ball &ball) {
	float k = .5;
	float difference;
	float slope;
	for (int i = 0; i < 4; i++) {//need to make the '4' into the size of the array of points or springs
		//change velocity by force
		ball.points[i].velX += ball.points[i].forceX;
		ball.points[i].velY += ball.points[i].forceY;

		//change position by velocity
		ball.points[i].x += ball.points[i].velX;
		ball.points[i].y += ball.points[i].velY;

		//reset forces
		ball.points[i].forceX = (float)round(0);
		ball.points[i].forceY = 0.1;
	}
	for (int i = 0; i < 6; i++) {//need to make the '6' into the size of the array of points or springs
		//calculate change in forces due to springs
		ball.springs[i].currentDistance = sqrt(pow(ball.springs[i].a->x - ball.springs[i].b->x , 2) + pow(ball.springs[i].a->y - ball.springs[i].b->y , 2));
		difference = abs(ball.springs[i].optimalDistance - ball.springs[i].currentDistance);
		if (difference != 0) {
			slope = (ball.springs[i].a->y - ball.springs[i].b->y) / (ball.springs[i].a->x - ball.springs[i].b->x);
			ball.springs[i].a->forceX += -((ball.springs[i].a->x - ball.springs[i].b->x) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * k;
			ball.springs[i].a->forceY += -((ball.springs[i].a->y - ball.springs[i].b->y) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * k;
		
			ball.springs[i].b->forceX += -((ball.springs[i].b->x - ball.springs[i].a->x) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * k;
			ball.springs[i].b->forceY += -((ball.springs[i].b->y - ball.springs[i].a->y) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * k;
		}
	}
}

void Move::movePaddles(Paddle &a, Paddle &b, bool pressedKeys[4]) {
	if (pressedKeys[0]) {//w
		a.velY -= 1;
	}
	if (pressedKeys[1]) {//s
		a.velY += 1;
	}

	if (pressedKeys[2]) {//UP
		b.velY -= 1;
	}
	if (pressedKeys[3]) {//DOWN
		b.velY += 1;
	}

	a.velY /= 1.1;
	b.velY /= 1.1;

	a.y += a.velY;
	b.y += b.velY;
}