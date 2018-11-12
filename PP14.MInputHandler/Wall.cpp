#include "Wall.h"

Wall::Wall(const LoaderParams * params)
	: SDLGameObject(params) {}

void Wall::draw()
{
	SDLGameObject::draw();
}

void Wall::update()
{
	SDLGameObject::update();
}

void Wall::clean()
{
}
