#include "Common.h"
#pragma once

class Move {
	public:
		void resetBall(Ball &ball);
		void resetPaddles(Paddle &a, Paddle &b);

		void moveBall(Ball &ball);
		void movePaddles(Paddle &a, Paddle& b, bool pressedKeys[6]);

};