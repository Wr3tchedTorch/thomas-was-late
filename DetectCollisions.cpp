#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;

	sf::FloatRect detectionArea = character.getGlobalBounds();

	const float TILE_SIZE_FLOAT = static_cast<float>(TILE_SIZE);

	sf::FloatRect block;
	block.size.x = TILE_SIZE;
	block.size.y = TILE_SIZE;

	int startX = (detectionArea.position.x / TILE_SIZE) - 1;
	int startY = (detectionArea.position.y / TILE_SIZE) - 1;
	int endX   = (detectionArea.position.x / TILE_SIZE) + 2;
	int endY   = (detectionArea.position.y / TILE_SIZE) + 3;

	sf::FloatRect level({
		{0.0f, 0.0f},
		{
			m_LevelManager.getLevelSize().x * TILE_SIZE_FLOAT,
			m_LevelManager.getLevelSize().x * TILE_SIZE_FLOAT
		}
	});

	if (!character.getGlobalBounds().findIntersection(level))
	{
		character.spawn(m_LevelManager.getStartPosition(), GRAVITY);
	}

	startX = std::max(startX, 0);
	startY = std::max(startY, 0);
	endX   = std::min(endX, m_LevelManager.getLevelSize().x);
	endY   = std::min(endY, m_LevelManager.getLevelSize().y);

	for (int x = startX; x < endX; ++x)
	{
		for (int y = startY; y < endY; ++y)
		{
			const int BLOCK_INDEX = m_ArrayLevel[y][x];

			if (BLOCK_INDEX == 0)
			{
				continue;
			}

			block.position = { 
				x * TILE_SIZE_FLOAT, 
				y * TILE_SIZE_FLOAT 
			};

			bool isWaterOrLava = BLOCK_INDEX == 2 || BLOCK_INDEX == 3;
			if (isWaterOrLava && character.getHeadBounds().findIntersection(block))
			{		
				character.spawn(m_LevelManager.getStartPosition(), GRAVITY);
				if (BLOCK_INDEX == 2)
				{
					// lava sound
				}
				else
				{
					// water sound
				}

				continue;
			}

			bool isSolid = BLOCK_INDEX == 1;
			if (isSolid)
			{
				if (character.getFeetBounds().findIntersection(block))
				{
					character.stopFalling(block.position.y);
				}
				if (character.getHeadBounds().findIntersection(block))
				{
					character.stopJumping();
				}
				if (character.getRightBounds().findIntersection(block))
				{
					character.stopRight(block.position.x);
				}
				if (character.getLeftBounds().findIntersection(block))
				{
					character.stopLeft(block.position.x);
				}
			}

			reachedGoal = BLOCK_INDEX == 4;
		}
	}

	return reachedGoal;
}