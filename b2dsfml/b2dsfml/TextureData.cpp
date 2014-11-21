#include "stdafx.h"
#include "TextureData.h"


std::shared_ptr<TextureData> TextureData::LoadTexture(std::string name)
{
	auto texture = std::make_shared<TextureData>(name);

	if (!texture->m_texture.loadFromFile(name))
	{
		// if loading fails, create a green square for the texture
		texture->m_texture.create(10, 10);
		sf::Uint8 *pixels = new sf::Uint8[10 * 10 * 4];
		sf::Uint8 *pixel = pixels;
		while (pixel < pixels + 10 * 10 * 4)
		{
			*pixel = 0;			// r
			*(pixel + 1) = 255;	// g
			*(pixel + 2) = 0;	// b
			*(pixel + 3) = 255;	// a
			pixel += 4;
		}
		texture->m_texture.update(pixels);
		delete pixels;
	}

	return texture;
}

TextureData::TextureData(std::string name) :
m_name(name),
m_texture()
{
}
