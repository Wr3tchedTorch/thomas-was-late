#include "TextureHolder.h"
#include <assert.h>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

TextureHolder* TextureHolder::m_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_Instance == nullptr);
	m_Instance = this;
}

const sf::Texture& TextureHolder::GetTexture(const std::string& filepath)
{
	unordered_map<string, Texture>& textures = m_Instance->m_Textures;
	
	unordered_map<string, Texture>::iterator searchResult = textures.find(filepath);
	if (searchResult == textures.end())
	{
		bool success = textures[filepath].loadFromFile(filepath);
		
		if (!success) std::cout << "\nError in loading the texture in: `" << filepath << "`";
	}

	return textures[filepath];
}
