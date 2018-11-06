#include "Game.h"
#include "Player.h"
#include "TextureManager.h"

void Player::draw()
{
	SDLGameObject::draw();
}

Player::Player(const LoaderParams * params)
	: SDLGameObject(params)
{
	TheTextureManager::Instance()->load("assets/bullet.png", "bullet", Game::Instance()->getRenderer());
}

void Player::update()
{
	_velocity.setX(0);
	_velocity.setY(0);
	handleInput();

	_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();

	for (std::vector<Bullet*>::iterator iter = _bullets.begin(); iter != _bullets.end(); iter++)
		(*iter)->update();
}

void Player::clean()
{
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

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
		_bullets.push_back(new Bullet(new LoaderParams(
			_position.getX(), _position.getY(), _width, _height, "bullet")));

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		_velocity.setX(1);
}
