#include "Game.h"
#include <iostream>

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	return true;
}

void Game::render()
{
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::update()
{
}

void Game::clean()
{
	std::cout << "cleaning game" << std::endl;
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_running = false;
			break;
		default:
			break;
		}
	}
}
