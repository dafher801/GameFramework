#include "WallManager.h"

WallManager * WallManager::_instance = nullptr;

WallManager * WallManager::getInstance()
{
	if (!_instance)
		_instance = new WallManager;

	return _instance;
}

void WallManager::PushBackWall(Wall * wall)
{
	_walls.push_back(wall);
}

void WallManager::DeleteWall(Wall * wall)
{
	for (std::vector<Wall*>::iterator iter = _walls.begin();
		*iter != wall && iter != _walls.end(); iter++)
	{
		_walls.erase(iter);
	}
}

void WallManager::draw()
{
	for (Wall * iter : _walls)
		iter->draw();
}

void WallManager::update()
{
	for (Wall * iter : _walls)
		iter->update();
}

void WallManager::clean()
{
	for (Wall * iter : _walls)
		iter->clean();
}

std::vector<Wall*> WallManager::getWalls() const
{
	return _walls;
}
