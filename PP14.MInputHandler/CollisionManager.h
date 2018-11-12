#pragma once

class CollisionManager
{
public:
	static CollisionManager * getInstance();

	void update();
	
private:
	CollisionManager() {}

	static CollisionManager * _instance;
};