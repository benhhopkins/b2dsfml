#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class World : public b2World
{
public:
	static World& I()
	{
		static World instance;
		return instance;
	}

	void RunWorld();
	void AddObjects();

private:
	World();
	~World();
	World(World const&);
	void operator=(World const&);
};

