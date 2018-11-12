#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"

class Wall : public SDLGameObject
{
public:
	Wall(const LoaderParams * params);

	void draw();
	void update();
	void clean();
};