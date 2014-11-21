#include "stdafx.h"
#include "WindowManager.h"


WindowManager::WindowManager() :
RenderWindow(sf::VideoMode(800, 600, 32), "SFML+Box 2D"),
m_debugDraw()
{
	setVerticalSyncEnabled(true);
}

WindowManager::~WindowManager()
{
}