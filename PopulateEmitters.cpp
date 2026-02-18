#include "Engine.h"

void Engine::populateEmitters(std::vector<sf::Vector2f>& soundEmitters, int** arrayLevel)
{
	soundEmitters.clear();

	sf::FloatRect forbiddenArea;
	for (int y = 0; y < m_LevelManager.getLevelSize().y; ++y)
	{
		for (int x = 0; x < m_LevelManager.getLevelSize().x; ++x)
		{
			int currentBlockIndex = arrayLevel[y][x];
			if (currentBlockIndex != 2)
			{				
				continue;
			}

			sf::FloatRect globalBlockBounds(
			{
				{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
				{ static_cast<float>(TILE_SIZE), static_cast<float>(TILE_SIZE) }
			});

			if (forbiddenArea.findIntersection(globalBlockBounds))
			{
				continue;
			}

			soundEmitters.push_back(globalBlockBounds.position);
			forbiddenArea = globalBlockBounds;
			forbiddenArea.size.x *= 6;
			forbiddenArea.size.y *= 6;
		}
	}	
}