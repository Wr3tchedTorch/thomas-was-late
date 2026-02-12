#pragma once
#include <SFML/Graphics.hpp>

class LevelManager
{
private:
	sf::Vector2i m_LevelSize;
	sf::Vector2f m_StartPosition;

	float m_TimeModifier  = 1;
	float m_BaseTimeLimit = 0;

	int m_CurrentLevel = 0;	
	const int LEVEL_COUNT = 4;

public:
	const int TILE_SIZE			= 50;
	const int VERTICES_PER_TILE = 50;

	float getTimeLimit();
	sf::Vector2f getStartPosition();

	sf::Vector2i getLevelSize();
	int getCurrentLevel();

	int** nextLevel(sf::VertexArray& levelVertexArray);
};
