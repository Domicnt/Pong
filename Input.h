#include "Common.h"
#pragma once

class Input {
	public:
		//pressing of keys
		void keyboardInput(SDL_Event &e);

		//clicking or moving the mouse
		void mouseInput(SDL_Event& e);
		int mousePosX;
		int mousePosY;

		//1 - w, 2 - s, 3 - UP, 4 - DOWN
		bool pressedKeys[4];

	private:

		const Uint8 *keyboard_state_array;

};