#include "stdafx.h"
#include "DebugDraw.h"

#include "SFML\Graphics.hpp"

#include "WindowManager.h"

sf::Color DebugDraw::b2toSfColor(b2Color color)
{
	return sf::Color((sf::Uint8)(color.r * 255), (sf::Uint8)(color.g * 255), (sf::Uint8)(color.b * 255), 150);
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::VertexArray poly(sf::LinesStrip);
	for (int i = 0; i < vertexCount; i++)
	{
		sf::Vertex vertex(sf::Vector2f(vertices[i].x, vertices[i].y));
		vertex.color = b2toSfColor(color);
		poly.append(vertex);
	}
	sf::Vertex endpoint(sf::Vector2f(vertices[0].x, vertices[0].y));
	endpoint.color = b2toSfColor(color);
	poly.append(endpoint);

	WindowManager::I().draw(poly);
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::ConvexShape poly;
	poly.setPointCount(vertexCount);

	for (int i = 0; i < vertexCount; i++)
	{
		poly.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
	}
	poly.setFillColor(b2toSfColor(color));

	WindowManager::I().draw(poly);
}

void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	sf::CircleShape circle(radius);
	
	circle.setOrigin(radius, radius);
	circle.setFillColor(b2toSfColor(color));
	circle.setPosition(sf::Vector2f(center.x, center.y));

	WindowManager::I().draw(circle);
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	sf::CircleShape circle(radius);

	circle.setOrigin(radius, radius);
	circle.setFillColor(b2toSfColor(color));
	circle.setPosition(sf::Vector2f(center.x, center.y));

	WindowManager::I().draw(circle);
}


void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	sf::VertexArray poly;

	sf::Vertex vertex1(sf::Vector2f(p1.x, p2.y));
	vertex1.color = b2toSfColor(color);
	poly.append(vertex1);

	sf::Vertex vertex2(sf::Vector2f(p1.x, p2.y));
	vertex2.color = b2toSfColor(color);
	poly.append(vertex2);

	WindowManager::I().draw(poly);
}

void DebugDraw::DrawTransform(const b2Transform& xf)
{
	sf::Vertex rotation[] =
	{
		sf::Vertex(sf::Vector2f(xf.p.x, xf.p.y)),
		sf::Vertex(sf::Vector2f(xf.p.x + 1.0f * xf.q.GetXAxis().x, xf.p.y + 1.0f * xf.q.GetXAxis().y))
	};
	rotation[0].color = sf::Color::Red;
	rotation[1].color = sf::Color::Red;
	WindowManager::I().draw(rotation, 2, sf::Lines);

	sf::Vertex scale[] =
	{
		sf::Vertex(sf::Vector2f(xf.p.x, xf.p.y)),
		sf::Vertex(sf::Vector2f(xf.p.x + 1.0f * xf.q.GetYAxis().x, xf.p.y + 1.0f * xf.q.GetYAxis().y))
	};
	scale[0].color = sf::Color::Green;
	scale[1].color = sf::Color::Green;
	WindowManager::I().draw(rotation, 2, sf::Lines);
}

/*
void DebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(p.x, p.y);
	glEnd();
	glPointSize(1.0f);
}

void DebugDraw::DrawString(int x, int y, const char *string, ...)
{
	char buffer[128];

	va_list arg;
	va_start(arg, string);
	vsprintf(buffer, string, arg);
	va_end(arg);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.9f, 0.6f, 0.6f);
	glRasterPos2i(x, y);
	int32 length = (int32)strlen(buffer);
	for (int32 i = 0; i < length; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
		//glutBitmapCharacter(GLUT_BITMAP_9_BY_15, buffer[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void DebugDraw::DrawString(const b2Vec2& p, const char *string, ...)
{
	char buffer[128];

	va_list arg;
	va_start(arg, string);
	vsprintf(buffer, string, arg);
	va_end(arg);

	glColor3f(0.5f, 0.9f, 0.5f);
	glRasterPos2f(p.x, p.y);

	int32 length = (int32)strlen(buffer);
	for (int32 i = 0; i < length; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, buffer[i]);
	}

	glPopMatrix();
}

void DebugDraw::DrawAABB(b2AABB* aabb, const b2Color& c)
{
	glColor3f(c.r, c.g, c.b);
	glBegin(GL_LINE_LOOP);
	glVertex2f(aabb->lowerBound.x, aabb->lowerBound.y);
	glVertex2f(aabb->upperBound.x, aabb->lowerBound.y);
	glVertex2f(aabb->upperBound.x, aabb->upperBound.y);
	glVertex2f(aabb->lowerBound.x, aabb->upperBound.y);
	glEnd();
}
*/