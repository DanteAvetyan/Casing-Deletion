#pragma once

#include "SDL.h"
#include <iostream>
#include <vector>

class Game
{
	
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void clean();
	void reset();

	static SDL_Event event;

	static bool isRunning;

private:
	SDL_Window* window;
};

