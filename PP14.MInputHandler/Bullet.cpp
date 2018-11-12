#include "Bullet.h"
#include "Game.h"
#include "TextureManager.h"

Bullet::Bullet(const LoaderParams * params)
	: SDLGameObject(params) {}

void Bullet::draw()
{
	TextureManager::Instance()->draw(_textureID,
		_position.getX(), _position.getY(), _width,
		_height, TheGame::Instance()->getRenderer());
}

void Bullet::update()
{
	_velocity.setX(10);
	SDLGameObject::update();
}

void Bullet::clean()
{
}
