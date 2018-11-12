#include "CollisionManager.h"
#include "BulletManager.h"
#include "WallManager.h"

#include <vector>

CollisionManager * CollisionManager::_instance = nullptr;

CollisionManager * CollisionManager::getInstance()
{
	if (!_instance)
		_instance = new CollisionManager;

	return _instance;
}

void CollisionManager::update()
{
	SDL_Point bulletPoint;

	for (Wall * wall : WallManager::getInstance()->getWalls())
	{
		for (Bullet * bullet : BulletManager::getInstance()->getBullets())
		{
			bulletPoint.x = bullet->getRect().x;
			bulletPoint.y = bullet->getRect().y;

			if (SDL_PointInRect(&bulletPoint, &wall->getRect()))
			{
				BulletManager::getInstance()->DeleteBullet(bullet);

				if (wall->getTextureID() == "Wall")
				{
					WallManager::getInstance()->DeleteWall(wall);
					WallManager::getInstance()->PushBackWall(
						new Wall(new LoaderParams(550, 100, 40, 100, "BreakWall")));
				}
			}
		}
	}
}
