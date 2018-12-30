#include "Common.h"
#pragma once


struct Point {
	float x, y;
	float velX, velY;
	float forceX, forceY;
};

struct Spring {
	Point* a;
	Point* b;

	float optimalDistance;
	float currentDistance;
};

struct Paddle {
	float x;
	float y;

	int width;
	int height;

	float velY;
	float velX;

	//constructor
	Paddle();
};

struct Ball {
	float x;
	float y;

	int radius;

	Point points[7]; // heptagon cus why not
	Spring springs[2 * sizeof(points) / sizeof(points[0])];

	//constructor
	Ball();
};


class Collision {
	public:
		void BallvsEdge(Ball &ball);
		void BallvsPaddles(Ball &ball, Paddle a, Paddle b);
		void PaddlesvsEdge(Paddle &a, Paddle &b);

		int lastCollision; // to keep track of which paddle the ball last touched, for scoring reasons
		int score = 0; // rally score
	private:

};