#include "LevelManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
#include "TextureHolder.h"

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
	case 2:
		m_StartPosition = { 100, 3600 };
		m_BaseTimeLimit = 100.0f;
	case 3:
		m_StartPosition = { 1250, 0 };
		m_BaseTimeLimit = 30.0f;
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

	size_t currentVertex = 0;
	for (int y = 0; y < m_LevelSize.y; ++y)
	{
		for (int x = 0; x < m_LevelSize.x; ++x)
		{
			sf::Vector2f topLeftPosition({ x * TILE_SIZE, y * TILE_SIZE });			
			
			sf::Vector2f topRightPosition(topLeftPosition);
			topRightPosition.x += TILE_SIZE;
			
			sf::Vector2f bottomLeftPosition(topLeftPosition);
			topRightPosition.y += TILE_SIZE;

			sf::Vector2f bottomRightPosition(topLeftPosition);
			topRightPosition.x += TILE_SIZE;
			topRightPosition.y += TILE_SIZE;

			levelVertexArray[currentVertex    ].position = topLeftPosition;
			levelVertexArray[currentVertex + 1].position = topRightPosition;
			levelVertexArray[currentVertex + 2].position = bottomLeftPosition;
			
			levelVertexArray[currentVertex + 3].position = topRightPosition;
			levelVertexArray[currentVertex + 4].position = bottomRightPosition;
			levelVertexArray[currentVertex + 5].position = bottomLeftPosition;

			int verticalTextureOffset = arrayLevel[y][x] * TILE_SIZE;

			levelVertexArray[currentVertex].texCoords	  = { 0,	     verticalTextureOffset };
			levelVertexArray[currentVertex + 1].texCoords = { TILE_SIZE, verticalTextureOffset};
			levelVertexArray[currentVertex + 2].texCoords = { 0,		 verticalTextureOffset + TILE_SIZE };

			levelVertexArray[currentVertex + 3].texCoords = { TILE_SIZE, verticalTextureOffset };
			levelVertexArray[currentVertex + 4].texCoords = { TILE_SIZE, verticalTextureOffset + TILE_SIZE};
			levelVertexArray[currentVertex + 5].texCoords = { 0,		 verticalTextureOffset + TILE_SIZE };

			currentVertex += VERTICES_PER_TILE;
		}
	}

	return arrayLevel;
}
