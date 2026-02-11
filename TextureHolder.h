#pragma once

#include <unordered_map>
#include <string>

namespace sf {
	class Texture;
}

using std::string, std::unordered_map, sf::Texture;

class TextureHolder
{
private:
	unordered_map<string, Texture> m_Textures;

	static TextureHolder* m_Instance;

public:
	TextureHolder();
	static const Texture& GetTexture(const string& filepath);
};
