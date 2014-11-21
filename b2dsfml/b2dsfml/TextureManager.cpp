#include "stdafx.h"
#include "TextureManager.h"


TextureManager::TextureManager() :
m_textures()
{
}


TextureManager::~TextureManager()
{
}

std::shared_ptr<TextureData> TextureManager::LoadTexture(std::string textureName)
{
	auto textureData = TextureData::LoadTexture(textureName);
	m_textures.push_back(textureData);
	return textureData;
}

std::shared_ptr<TextureData> TextureManager::GetTexture(std::string textureName)
{
	for (auto texData : m_textures)
	{
		if (texData->GetName() == textureName)
		{
			return texData;
		}
	}

	return LoadTexture(textureName);
}