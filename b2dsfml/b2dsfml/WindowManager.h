#pragma once

#include "SFML\Graphics.hpp"
#include "DebugDraw.h"

class WindowManager : public sf::RenderWindow
{
public:
	static WindowManager& I()
	{
		static WindowManager instance;
		return instance;
	}

	DebugDraw& GetDebugDraw() {
		return m_debugDraw;
	}

private:
	WindowManager();
	~WindowManager();
	WindowManager(WindowManager const&);
	void operator=(WindowManager const&);

	DebugDraw m_debugDraw;
};

