#include "Player.h"
#include "BulletManager.h"

Player::Player(const LoaderParams * params)
	: SDLGameObject(params) {}

void Player::draw()
{
	SDLGameObject::draw();

	BulletManager::getInstance()->draw();
}

void Player::update()
{
	_velocity.setX(0);
	_velocity.setY(0);
	handleInput();

	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();

	BulletManager::getInstance()->update();
}

void Player::clean()
{
	BulletManager::getInstance()->clean();
}

void Player::handleInput()
{
	Vector2D * vec = TheInputHandler::Instance()->getMousePosition();
	_velocity = (*vec - _position) / 100;

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		_velocity.setX(2);

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		_velocity.setX(-2);

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
		_velocity.setY(-2);

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
		_velocity.setY(2);

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		BulletManager::getInstance()->PushBackBullet(new Bullet(new LoaderParams(
			_position.getX(), _position.getY(), 50, 50, "Ball")));
	}
}
