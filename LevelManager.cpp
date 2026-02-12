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

	std::string levelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		levelToLoad = "levels/level1.dat";
		m_StartPosition = { 100, 100 };
		m_BaseTimeLimit = 30.0f;
	case 2:
		levelToLoad = "levels/level2.dat";
		m_StartPosition = { 100, 3600 };
		m_BaseTimeLimit = 100.0f;
	case 3:
		levelToLoad = "levels/level3.dat";
		m_StartPosition = { 1250, 0 };
		m_BaseTimeLimit = 30.0f;
	case 4:
		levelToLoad = "levels/level4.dat";
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

	return nullptr;
}
