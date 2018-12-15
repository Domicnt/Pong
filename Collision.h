#include "Common.h"
#pragma once

struct Paddle {
	//position
	double posX;
	double posY;

	//y axis speed
	double velocity;

	//angle and angular velocity
	int angle;
	double angularVel;

	//size
	int height;
	int width;
};

struct Ball {
	//position
	double posX;
	double posY;

	//velocity vector
	double velocity;
	int angle;

	//for gravity and such
	double yVel;
	double xVel;

	//size
	int radius;
};

class Collision {
	public:
		void BallvsEdge(Ball ball);
		void BallvsPaddles(Ball ball, Paddle a, Paddle b);

		//bool for what edges the ball is colliding with
		bool BallvsEdges[4];

		//bool for if the ball is colliding with either paddle
		bool BallvsPaddle[2];

		int score = 0;
	private:

};