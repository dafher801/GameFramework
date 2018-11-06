#pragma once

#include "SDLGameObject.h"
#include "LoaderParams.h"

class Bullet : public SDLGameObject
{
public:
	Bullet(const LoaderParams * params);

	void update();

private:
};