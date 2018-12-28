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

	float velY;
	float velX;

	float forceX;
	float forceY;

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
		void BallvsPaddles(Ball &ball, Paddle a, Paddle b);
		void PaddlesvsEdge(Paddle &a, Paddle &b);

		int score = 0;
	private:

};