#include "Common.h"
#pragma once

class Move {
	public:
		void resetBall(Ball &ball);
		void resetPaddles(Paddle &a, Paddle &b);

		void moveBall(Ball &ball);
		void movePaddles(Paddle &a, Paddle& b, bool pressedKeys[4]);

		void resolveBallvsEdge(Ball &ball, bool BallvsEdges[4]);
		void resolveBallvsPaddles(Ball &ball, Paddle &a, Paddle &b, bool BallvsPaddle[2]);
	private:
		const int maxBallVel = 5;
		const int maxPaddleVel = 3;
};