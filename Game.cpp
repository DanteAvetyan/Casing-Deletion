#include <iostream>
#include "Game.h"
#include "CasingManager.h"
#include <string>

SDL_Event Game::event;

CasingManager casingManager;
static Uint32 lastFrameTime = 0;
static Uint32 currentFrameTime = SDL_GetTicks();

bool Game::isRunning = false;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		//renderer = SDL_CreateRenderer(window, -1, 0);
		/*if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}*/

		isRunning = true;
	}

	/*if (TTF_Init() == -1)
	{
		std::cout << "Error : SDL_TTF" << std::endl;
	}*/

}

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	int x, y;
	Uint32 buttons = SDL_GetMouseState(&x, &y);
	if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		casingManager.createCasing(0, 0, 0);
		std::cout << "Fired" << std::endl;
	}
}

void Game::update()
{
	currentFrameTime = SDL_GetTicks(); // Determine the time passed since the last frame
	Uint32 deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;

	casingManager.update(deltaTime/1000.0f);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::reset()
{
	Game::isRunning = true;
}
