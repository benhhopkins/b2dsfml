#pragma once

#include <string>
#include <memory>
#include "SFML\Graphics.hpp"

class TextureData
{
public:
	static std::shared_ptr<TextureData> LoadTexture(std::string name);
	TextureData(std::string name);

	std::string GetName() {
		return m_name;
	}



private:

	std::string m_name;
	sf::Texture m_texture;
};

