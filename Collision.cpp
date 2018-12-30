#include "Common.h"

void Collision::BallvsEdge(Ball &ball) {
	for (int i = 0; i < sizeof(ball.points) / sizeof(ball.points[0]); i++) {
		if (ball.points[i].x > SCREEN_WIDTH - 1 || ball.points[i].x < 0 + 1) {
			move.resetBall(ball);
			score = 0;
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

void Collision::BallvsPaddles(Ball &ball, Paddle a, Paddle b) {
	for (int i = 0; i < sizeof(ball.points) / sizeof(ball.points[0]); i++) {
		if (ball.points[i].x <= a.x + a.width / 2 && ball.points[i].y <= a.y + a.height / 2 && ball.points[i].y >= a.y - a.height / 2) {
			ball.points[i].x = a.x + a.width / 2;
			ball.points[i].velX = 0;
			ball.points[i].forceY += a.velY * Friction;
			if (lastCollision != 1) {
				lastCollision = 1;
				score++;
			} else {
				lastCollision = 1;
			}
		} else if (ball.points[i].x >= b.x - b.width / 2 && ball.points[i].y <= b.y + b.height / 2 && ball.points[i].y >= b.y - b.height / 2) {
			ball.points[i].x = b.x - b.width / 2;
			ball.points[i].velX = 0;
			ball.points[i].forceY += b.velY * Friction;
			if (lastCollision != 2) {
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
	for (int i = 0; i < sizeof(points) / sizeof(points[0]); i++) {
		points[i].x = x + radius * cos((i + 1) * (Pi * 2) / (sizeof(points) / sizeof(points[0])));
		points[i].y = y + radius * sin((i + 1) * (Pi * 2) / (sizeof(points) / sizeof(points[0])));
		points[i].forceX = 0;
		points[i].forceY = 0;
		points[i].velX = 3;
		points[i].velY = 3;
	}

	

	int b = 0;
	for (int i = 0; i < (sizeof(points) / sizeof(points[0])); i++) {
		springs[i].a = &points[i % (sizeof(points) / sizeof(points[0]))];
		springs[i].b = &points[(i + 1) % (sizeof(points) / sizeof(points[0]))];
		springs[i].optimalDistance = sqrt(pow(springs[i].a->x - springs[i].b->x, 2) + pow(springs[i].a->y - springs[i].b->y, 2));
	}
	for (int i = (sizeof(points) / sizeof(points[0])); i < (sizeof(springs) / sizeof(springs[0])); i++) {
		springs[i].a = &points[b % (sizeof(points) / sizeof(points[0]))];
		springs[i].b = &points[(b + 2) % (sizeof(points) / sizeof(points[0]))];
		springs[i].optimalDistance = sqrt(pow(springs[i].a->x - springs[i].b->x, 2) + pow(springs[i].a->y - springs[i].b->y, 2));
		b++;
	}


	return;
}

Paddle::Paddle(){
	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;

	width = 20;
	height = 100;

	velY = 0;
	velX = 0;
	return;
}