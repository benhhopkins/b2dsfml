#pragma once

#include <vector>
#include <string>
#include <memory>
#include "SFML\Graphics.hpp"

#include "TextureData.h"

// singleton class
class TextureManager
{
public:
	static TextureManager& I()
	{
		static TextureManager instance;
		return instance;
	}

	std::shared_ptr<TextureData> LoadTexture(std::string textureName);
	std::shared_ptr<TextureData> GetTexture(std::string textureName);

private:
	TextureManager();
	~TextureManager();
	TextureManager(TextureManager const&);
	void operator=(TextureManager const&);

	std::vector<std::shared_ptr<TextureData>> m_textures;
};

