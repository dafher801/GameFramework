#pragma once

#include <iostream>
#include <SDL.h>
#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams * params);

	void draw();
	void update();
	void clean();

private:
	void handleInput();
};