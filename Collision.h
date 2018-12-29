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

	//constructor
	Paddle();
};

struct Ball {
	float x;
	float y;

	int radius;

	//at four just to make testing thing easier, it should be at 8 or 16
	Point points[4];
	Spring springs[6];

	//constructor
	Ball();
};


class Collision {
	public:
		void BallvsEdge(Ball &ball);
		void BallvsPaddles(Ball &ball, Paddle a, Paddle b, int &score);
		void PaddlesvsEdge(Paddle &a, Paddle &b);

		int lastCollision; // to keep track of which paddle the ball last touched, for scoring reasons
	private:

};