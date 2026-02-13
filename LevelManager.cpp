#include "LevelManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
#include <iostream>
#include "TextureHolder.h"

float LevelManager::getTimeLimit()
{
	return m_BaseTimeLimit * m_TimeModifier;
}

sf::Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}

sf::Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_CurrentLevel;
}

int** LevelManager::nextLevel(sf::VertexArray& levelVertexArray)
{
	m_LevelSize = { 0, 0 };
	
	m_CurrentLevel++;
	if (m_CurrentLevel > LEVEL_COUNT)
	{
		m_CurrentLevel  = 1;
		m_TimeModifier -= 0.1f;
	}

	std::string levelToLoad = std::format("levels/level{}.dat", m_CurrentLevel);
	switch (m_CurrentLevel)
	{
	case 1:
		m_StartPosition = { 100, 100 };
		m_BaseTimeLimit = 30.0f;
		break;
	case 2:
		m_StartPosition = { 100, 3600 };
		m_BaseTimeLimit = 100.0f;
		break;
	case 3:
		m_StartPosition = { 1250, 0 };
		m_BaseTimeLimit = 30.0f;
		break;
	case 4:
		m_StartPosition = { 50, 200 };
		m_BaseTimeLimit = 50.0f;
	}

	std::ifstream inputFile(levelToLoad);
	std::string s;
	while (std::getline(inputFile, s))
	{
		++m_LevelSize.y;
	}
	m_LevelSize.x = s.length();

	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);

	int** arrayLevel = new int* [m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	std::string line;
	int y = 0;
	while (inputFile >> line)
	{
		for (int x = 0; x < line.length(); ++x)
		{
			const char tileIndex = line[x];
			assert(std::isdigit(tileIndex));

			arrayLevel[y][x]  = tileIndex - '0';
		}
		++y;
	}
	inputFile.close();

	levelVertexArray.setPrimitiveType(sf::PrimitiveType::Triangles);
	levelVertexArray.resize(static_cast<size_t>(m_LevelSize.x) * m_LevelSize.y * VERTICES_PER_TILE);

	const float tileSizeFloat = static_cast<float>(TILE_SIZE);

	size_t currentVertex = 0;
	for (int y = 0; y < m_LevelSize.y; ++y)
	{
		for (int x = 0; x < m_LevelSize.x; ++x)
		{
			float left   = x    * tileSizeFloat;
			float right  = left + tileSizeFloat;
			float top    = y    * tileSizeFloat;
			float bottom = top  + tileSizeFloat;

			levelVertexArray[currentVertex + 0].position = { left,  top };
			levelVertexArray[currentVertex + 1].position = { left,  bottom };
			levelVertexArray[currentVertex + 2].position = { right, top };

			levelVertexArray[currentVertex + 3].position = { right, top };
			levelVertexArray[currentVertex + 4].position = { right, bottom };
			levelVertexArray[currentVertex + 5].position = { left,  bottom };

			float verticalTextureOffset = static_cast<float>(arrayLevel[y][x]) * tileSizeFloat;

			left   = 0;
			right  = left + tileSizeFloat;
			top    = verticalTextureOffset;
			bottom = top  + tileSizeFloat;

			levelVertexArray[currentVertex + 0].texCoords = { left,  top };
			levelVertexArray[currentVertex + 1].texCoords = { left,  bottom };
			levelVertexArray[currentVertex + 2].texCoords = { right, top };

			levelVertexArray[currentVertex + 3].texCoords = { right, top };
			levelVertexArray[currentVertex + 4].texCoords = { right, bottom };
			levelVertexArray[currentVertex + 5].texCoords = { left,  bottom };

			currentVertex += VERTICES_PER_TILE;
		}
	}

	return arrayLevel;
}

