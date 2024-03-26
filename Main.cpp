#include "Game.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 680;

Game* game = nullptr;

int main(int argc, char* argv[])
{


		const int FPS = 60;
		const int frameDelay = 1000 / FPS;

		Uint32 frameStart;
		int frameTime;

		game = new Game();
		game->init("BirchEngine", SCREEN_WIDTH, SCREEN_HEIGHT, false);

		while (game->running())
		{
			//std::cout << "Game loop running..." << std::endl;

			frameStart = SDL_GetTicks();

			game->handleEvents();
			game->update();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
		}


	game->clean();
	return 0;
}