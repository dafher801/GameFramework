#include "Bullet.h"

Bullet::Bullet(const LoaderParams * params)
	: SDLGameObject(params) {}

void Bullet::update()
{
	SDLGameObject::update();
}
