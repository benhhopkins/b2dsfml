#include "stdafx.h"
#include "World.h"

#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "WindowManager.h"
#include "ObjectBase.h"

World::World() :
b2World(b2Vec2(0.0f, 10.0f))
{
}

World::~World(){}

void World::RunWorld()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_pairBit;
	flags += b2Draw::e_centerOfMassBit;
	WindowManager::I().GetDebugDraw().SetFlags(flags);
	SetDebugDraw(&WindowManager::I().GetDebugDraw());

	// Since the Box2D world is tuned for meters, and works with averagely sized objects,
	//  we'll zoom in with the view.
	sf::View view;
	view.setSize(sf::Vector2f(80, 60));
	view.setCenter(sf::Vector2f(40, 30));
	WindowManager::I().setView(view);

	auto obj = std::make_shared<ObjectBase>(OSTCircle, 1.0f, true);
	auto obj2 = std::make_shared<ObjectBase>(OSTRectangle, 15.0f, false);
	auto obj3 = std::make_shared<ObjectBase>(OSTRectangle, 15.0f, false);
	auto obj4 = std::make_shared<ObjectBase>(OSTRectangle, 15.0f, false);

	obj->SetPosition(40, 10);
	obj2->SetPosition(40, 51.5);
	obj3->SetPosition(70, 43);
	obj3->SetRotation(b2_pi / 4.0f);
	obj4->SetPosition(10, 45);
	obj4->SetRotation(b2_pi / 8.0f + b2_pi);

	while (WindowManager::I().isOpen())
	{
		// Handle events
		sf::Event event;
		while (WindowManager::I().pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				WindowManager::I().close();
				break;
			}
		}

		float32 timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;

		Step(timeStep, velocityIterations, positionIterations);

		obj->Move();

		WindowManager::I().clear(sf::Color::Black);

		DrawDebugData();

		WindowManager::I().display();
	}
}