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

	float velY;
	float velX;

	float forceX;
	float forceY;

	//float angle;

	Point points[18];
	Spring springs[18];
};

struct Ball {
	float x;
	float y;

	float velY;
	float velX;

	float forceX;
	float forceY;

	float angle;

	float radius;

	//at four just to make testing thing easier, it should be at 8 or 16
	Point points[4];
	Spring springs[4];

	//constructor
	Ball();
};


class Collision {
	public:
		void BallvsEdge(Ball ball);
		void BallvsPaddles(Ball ball, Paddle a, Paddle b);

		void PointvsEdges(Point &point);

		//bool for what edges the ball is colliding with
		bool BallvsEdges[4];

		//bool for if the ball is colliding with either paddle
		bool BallvsPaddle[2];

		int score = 0;
	private:

};