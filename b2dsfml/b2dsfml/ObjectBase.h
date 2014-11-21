#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

enum ObjectShapeType
{
	OSTCircle = 0,
	OSTRectangle
};

class ObjectBase
{
public:
	ObjectBase(ObjectShapeType type, float size, bool dynamicBody);
	~ObjectBase();

	void SetPosition(float x, float y);
	void SetRotation(float radians);

	void Move();

private:
	ObjectShapeType m_type;
	b2Body* m_b2body;
};

