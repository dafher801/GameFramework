#pragma once

#include <vector>
#include "Wall.h"

class WallManager
{
public:
	static WallManager * getInstance();

	void PushBackWall(Wall * wall);
	void DeleteWall(Wall * wall);

	void draw();
	void update();
	void clean();

	std::vector<Wall*> getWalls() const;

private:
	WallManager() {}

	static WallManager * _instance;

	std::vector<Wall*> _walls;
};