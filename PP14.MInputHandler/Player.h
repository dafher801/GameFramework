#pragma once

#include <SDL.h>
#include <vector>

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Bullet.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams * params);

	void draw();
	void update();
	void clean();

	std::vector<Bullet*> getBullets() const;

private:
	void handleInput();
};