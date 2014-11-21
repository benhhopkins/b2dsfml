#include "stdafx.h"
#include "ObjectBase.h"
#include "World.h"

ObjectBase::ObjectBase(ObjectShapeType type, float size, bool dynamicBody) :
	m_type(type),
	m_b2body(NULL)
{
	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	if (dynamicBody)
	{
		bodyDef.type = b2_dynamicBody;
	}
	else
	{
		bodyDef.type = b2_staticBody;
	}
	bodyDef.position.Set(0.0f, 0.0f);
	m_b2body = World::I().CreateBody(&bodyDef);

	b2FixtureDef fixtureDef;
	b2CircleShape b2circle;
	b2PolygonShape b2Poly;

	if (type == OSTCircle)
	{
		b2circle.m_p.Set(0, 0);
		b2circle.m_radius = size;
		fixtureDef.shape = &b2circle;
	}
	else
	{
		b2Poly.SetAsBox(size, size);
		fixtureDef.shape = &b2Poly;
	}

	if (dynamicBody)
	{
		fixtureDef.density = 1.0f;
		fixtureDef.restitution = 0.2f;
	}
	fixtureDef.friction = 0.8f;

	m_b2body->CreateFixture(&fixtureDef);
	m_b2body->SetAngularDamping(0.5f);
}

ObjectBase::~ObjectBase()
{
	World::I().DestroyBody(m_b2body);
}

void ObjectBase::SetPosition(float x, float y)
{
	m_b2body->SetTransform(b2Vec2(x, y), m_b2body->GetAngle());
}

void ObjectBase::SetRotation(float radians)
{
	m_b2body->SetTransform(m_b2body->GetTransform().p, radians);
}

void ObjectBase::Move()
{
	float force = 100;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_b2body->ApplyForceToCenter(b2Vec2(0, -force), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_b2body->ApplyForceToCenter(b2Vec2(0, force), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_b2body->ApplyForceToCenter(b2Vec2(-force, 0), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_b2body->ApplyForceToCenter(b2Vec2(force, 0), true);
	}
}