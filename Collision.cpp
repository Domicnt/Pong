#include "Common.h"

void Collision::BallvsEdge(Ball ball) {
	
}

void Collision::BallvsPaddles(Ball ball, Paddle a, Paddle b) {
	
}

void Collision::PointvsEdges(Point &point) {
	if (point.x > SCREEN_WIDTH) point.x = SCREEN_WIDTH;
	else if (point.x < 0) point.x = 0;
	if (point.y > SCREEN_HEIGHT) point.y = SCREEN_HEIGHT;
	else if (point.y < 0) point.y = 0;
}
