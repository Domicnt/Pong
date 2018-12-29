#include "Common.h"

void Collision::BallvsEdge(Ball &ball) {
	for (int i = 0; i < 4; i++) {
		if (ball.points[i].x > SCREEN_WIDTH - 1 || ball.points[i].x < 0 + 1) {
			move.resetBall(ball);
		}
		if (ball.points[i].y > SCREEN_HEIGHT - 1) {
			ball.points[i].y = SCREEN_HEIGHT - 1;
			ball.points[i].velY = 0;
			ball.points[i].velX *= EdgeFriction;
		} else if (ball.points[i].y < 0 + 1) {
			ball.points[i].y = 0 + 1;
			ball.points[i].velY = 0;
			ball.points[i].velX *= EdgeFriction;
		}
	}
}

void Collision::BallvsPaddles(Ball &ball, Paddle a, Paddle b, int &score) {
	for (int i = 0; i < 4; i++) {
		if (ball.points[i].x <= a.x + a.width / 2 && ball.points[i].y <= a.y + a.height / 2 && ball.points[i].y >= a.y - a.height / 2) {
			ball.points[i].x = a.x + a.width / 2;
			ball.points[i].velX = 0;
			ball.points[i].forceY += a.velY * Friction;
			if (lastCollision == 2) {
				lastCollision = 1;
				score++;
			} else {
				lastCollision = 1;
			}
		} else if (ball.points[i].x >= b.x - b.width / 2 && ball.points[i].y <= b.y + b.height / 2 && ball.points[i].y >= b.y - b.height / 2) {
			ball.points[i].x = b.x - b.width / 2;
			ball.points[i].velX = 0;
			ball.points[i].forceY += b.velY * Friction;
			if (lastCollision == 1) {
				lastCollision = 2;
				score++;
			} else {
				lastCollision = 2;
			}
		}
	}
}

void Collision::PaddlesvsEdge(Paddle &a, Paddle &b) {
	if (a.y - a.height / 2 < 0) {
		a.y = a.height / 2;
		a.velY = 0;
	} else if (a.y + a.height / 2 > SCREEN_HEIGHT) {
		a.y = SCREEN_HEIGHT - a.height / 2;
		a.velY = 0;
	}
	if (b.y - b.height / 2 < 0) {
		b.y = b.height / 2;
		b.velY = 0;
	} else if (b.y + a.height / 2 > SCREEN_HEIGHT) {
		b.y = SCREEN_HEIGHT - b.height / 2;
		b.velY = 0;
	}
}

Ball::Ball(){
	x = (float)round(SCREEN_WIDTH / 2);
	y = (float)round(SCREEN_HEIGHT / 2);

	radius = 20;

	srand(time(NULL)); // need to make it actually random, time is always the same rn

	for (int i = 0; i < 4; i++) {
		points[i].forceX = 0;
		points[i].forceY = 0;
		points[i].velX = rand() % 3 + 1;
		points[i].velY = rand() % 3 + 1;
	}

	points[0].x = x;
	points[0].y = y - radius;

	points[1].x = x - radius;
	points[1].y = y;

	points[2].x = x;
	points[2].y = y + radius;

	points[3].x = x + radius;
	points[3].y = y;

	springs[0].a = &points[0];
	springs[0].b = &points[1];
	springs[0].optimalDistance = sqrt(pow(points[0].x - points[1].x, 2) + pow(points[0].y - points[1].y, 2));
	springs[1].a = &points[1];
	springs[1].b = &points[2];
	springs[1].optimalDistance = sqrt(pow(points[1].x - points[2].x, 2) + pow(points[1].y - points[2].y, 2));
	springs[2].a = &points[2];
	springs[2].b = &points[3];
	springs[2].optimalDistance = sqrt(pow(points[2].x - points[3].x, 2) + pow(points[2].y - points[3].y, 2));
	springs[3].a = &points[3];
	springs[3].b = &points[0];
	springs[3].optimalDistance = sqrt(pow(points[3].x - points[0].x, 2) + pow(points[3].y - points[0].y, 2));
	springs[4].a = &points[0];
	springs[4].b = &points[2];
	springs[4].optimalDistance = radius * 2;
	springs[5].a = &points[1];
	springs[5].b = &points[3];
	springs[5].optimalDistance = radius * 2;

	return;
}

Paddle::Paddle(){
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;

	width = 20;
	height = 100;

	velY = 0;
	return;
}