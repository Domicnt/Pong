#include "Common.h"

void Move::resetBall(Ball &ball) {

	srand((unsigned)time(0));

	for (int i = 0; i < sizeof(ball.points) / sizeof(ball.points[0]); i++) {
		ball.points[i].x = ball.x + ball.radius * cos((i + 1) * (Pi * 2) / (sizeof(ball.points) / sizeof(ball.points[0])));
		ball.points[i].y = ball.y + ball.radius * sin((i + 1) * (Pi * 2) / (sizeof(ball.points) / sizeof(ball.points[0])));
		ball.points[i].forceX = 0;
		ball.points[i].forceY = 0;
		ball.points[i].velX = 3;
		ball.points[i].velY = 3;
	}

	int b = 0;
	for (int i = 0; i < (sizeof(ball.points) / sizeof(ball.points[0])); i++) {
		ball.springs[i].a = &ball.points[i % (sizeof(ball.points) / sizeof(ball.points[0]))];
		ball.springs[i].b = &ball.points[(i + 1) % (sizeof(ball.points) / sizeof(ball.points[0]))];
		ball.springs[i].optimalDistance = sqrt(pow(ball.springs[i].a->x - ball.springs[i].b->x, 2) + pow(ball.springs[i].a->y - ball.springs[i].b->y, 2));
	}
	for (int i = (sizeof(ball.points) / sizeof(ball.points[0])); i < (sizeof(ball.springs) / sizeof(ball.springs[0])); i++) {
		ball.springs[i].a = &ball.points[i % (sizeof(ball.points) / sizeof(ball.points[0]))];
		ball.springs[i].b = &ball.points[(i + 2) % (sizeof(ball.points) / sizeof(ball.points[0]))];
		ball.springs[i].optimalDistance = sqrt(pow(ball.springs[i].a->x - ball.springs[i].b->x, 2) + pow(ball.springs[i].a->y - ball.springs[i].b->y, 2));
		b++;
	}
}

void Move::resetPaddles(Paddle &a, Paddle &b) {
	a.x = 25;
	a.y = SCREEN_HEIGHT / 2;
	a.velX = 0;
	a.velY = 0;

	b.x = SCREEN_WIDTH - 25;
	b.y = SCREEN_HEIGHT / 2;
	b.velX = 0;
	b.velY = 0;
}


void Move::moveBall(Ball &ball) {
	for (int i = 0; i < sizeof(ball.points) / sizeof(ball.points[0]); i++) {//need to make the '4' into the size of the array of points or springs
		//change velocity by force
		ball.points[i].velX += ball.points[i].forceX;
		ball.points[i].velY += ball.points[i].forceY;

		//change position by velocity
		ball.points[i].x += ball.points[i].velX;
		ball.points[i].y += ball.points[i].velY;

		//reset forces
		ball.points[i].forceX = 0;
		ball.points[i].forceY = 0;
	}
	for (int i = 0; i < sizeof(ball.springs) / sizeof(ball.springs[0]); i++) {
		//calculate change in forces due to springs
		ball.springs[i].currentDistance = sqrt(pow(ball.springs[i].a->x - ball.springs[i].b->x , 2) + pow(ball.springs[i].a->y - ball.springs[i].b->y , 2));
		if (abs(ball.springs[i].optimalDistance - ball.springs[i].currentDistance) != 0) {
			ball.springs[i].a->forceX += -((ball.springs[i].a->x - ball.springs[i].b->x) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * SpringForce;
			ball.springs[i].a->forceY += -((ball.springs[i].a->y - ball.springs[i].b->y) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * SpringForce;
		
			ball.springs[i].b->forceX += -((ball.springs[i].b->x - ball.springs[i].a->x) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * SpringForce;
			ball.springs[i].b->forceY += -((ball.springs[i].b->y - ball.springs[i].a->y) / ball.springs[i].currentDistance) * (ball.springs[i].currentDistance - ball.springs[i].optimalDistance) * SpringForce;
		
			//calculate spring damping
			ball.springs[i].a->forceX += -(ball.springs[i].a->velX - ball.springs[i].b->velX) * SpringDamping;
			ball.springs[i].a->forceY += -(ball.springs[i].a->velY - ball.springs[i].b->velY) * SpringDamping;

			ball.springs[i].b->forceX += -(ball.springs[i].b->velX - ball.springs[i].a->velX) * SpringDamping;
			ball.springs[i].b->forceY += -(ball.springs[i].b->velY - ball.springs[i].a->velY) * SpringDamping;
		}
	}
}

void Move::movePaddles(Paddle &a, Paddle &b, bool pressedKeys[6]) {
	if (pressedKeys[0]) {//w
		a.velY -= .33;
	}
	if (pressedKeys[1]) {//s
		a.velY += .33;
	}
	if (pressedKeys[2]) {//d
		a.velX += .5;
	} else {
		a.velX -= .5;
	}

	if (pressedKeys[3]) {//UP
		b.velY -= .33;
	}
	if (pressedKeys[4]) {//DOWN
		b.velY += .33;
	}
	if (pressedKeys[5]) {//LEFT
		b.velX -= .5;
	} else {
		b.velX += .5;
	}

	a.velY /= 1.1;

	b.velY /= 1.1;

	if (a.x < 25) {
		a.x = 25;
		a.velX = 0;
	} else if (a.x > 75) {
		a.velX -= 1;
	}

	if (b.x > SCREEN_WIDTH - 25) {
		b.x = SCREEN_WIDTH - 25;
		b.velX = 0;
	} else if (b.x < SCREEN_WIDTH - 75) {
		b.velX += 1;
	}

	a.y += a.velY;
	a.x += a.velX;

	b.y += b.velY;
	b.x += b.velX;
}