#include "Engine.h"

void Engine::loadLevel()
{
	m_IsPlaying = false;

	for (int y = 0; y < m_LevelManager.getLevelSize().y; ++y)
	{
		delete[] m_ArrayLevel[y];
	}
	delete[] m_ArrayLevel;

	m_ArrayLevel = m_LevelManager.nextLevel(m_VertexArrayLevel);

	m_TimeRemainingInSeconds = m_LevelManager.getTimeLimit();

	m_Thomas.spawn(m_LevelManager.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LevelManager.getStartPosition(), GRAVITY);

	m_NewLevelRequired = false;
}