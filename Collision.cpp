#include "Common.h"

void Collision::BallvsEdge(Ball ball) {
	
}

void Collision::BallvsPaddles(Ball ball, Paddle a, Paddle b) {
	
}

void Collision::PointvsEdges(Point &point) {
	printf("%f\n", point.y);
	if (point.x > SCREEN_WIDTH) point.x = SCREEN_WIDTH;
	else if (point.x < 0) point.x = 0;
	if (point.y > SCREEN_HEIGHT) point.y = SCREEN_HEIGHT;
	else if (point.y < 0) point.y = 0;
}

Ball::Ball(){
	x = (float)round(SCREEN_WIDTH / 2);
	y = (float)round(SCREEN_HEIGHT / 2);

	radius = 20;

	for (int i = 0; i < 4; i++) {
		points[i].forceX = 0;
		points[i].forceY = .1;
		points[i].velX = 0;
		points[i].velY = 0;
	}

	points[0].x = x + radius;
	points[0].y = y;

	points[1].x = x;
	points[1].y = y + radius;

	points[2].x = x - radius;
	points[2].y = y;

	points[3].x = x;
	points[3].y = y - radius;

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


	return;
}
