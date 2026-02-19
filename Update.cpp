#include "Engine.h"
#include <iostream>

void Engine::update(float delta)
{
	if (m_NewLevelRequired)
	{
		loadLevel();
	}

	if (m_IsPlaying)
	{
		m_Thomas.update(delta);
		m_Bob.update(delta);

		bool hasThomasReachedGoal = detectCollisions(m_Thomas);
		bool hasBobReachedGoal	  = detectCollisions(m_Bob);

		std::cout << std::format("\nhasThomasReachedGoal: {}, hasBobReachedGoal: {}", hasThomasReachedGoal, hasBobReachedGoal);
		if (hasThomasReachedGoal && hasBobReachedGoal)
		{
			m_SoundManager.playReachGoal();

			m_NewLevelRequired = true;
		}

		if (m_Thomas.getFeetBounds().findIntersection(m_Bob.getHeadBounds()))
		{
			m_Thomas.stopFalling(m_Bob.getHeadBounds().position.y);
		}
		else if (m_Bob.getFeetBounds().findIntersection(m_Thomas.getHeadBounds()))
		{
			m_Bob.stopFalling(m_Thomas.getHeadBounds().position.y);
		}

		m_TimeRemainingInSeconds -= delta;

		if (m_TimeRemainingInSeconds <= 0)
		{
			m_NewLevelRequired = true;
		}
	}

	if (m_FireEmitters.size() > 0)
	{
		for (auto& it : m_FireEmitters)
		{
			float x = it.x;
			float y = it.y;

			sf::FloatRect emitterRange(
				{
					{x - 250, y - 250},
					{500, 500}
				}
			);

			if (emitterRange.findIntersection(m_Thomas.getGlobalBounds()))
			{
				m_SoundManager.playFire({ x, y }, m_Thomas.getCenter());
			}
		}
	}

	m_FramesSinceLastHudUpdate++;
	if (m_FramesSinceLastHudUpdate > m_FramesDelayPerHudUpdate)
	{
		m_FramesSinceLastHudUpdate = 0;

		std::string levelString = std::format("Level: {}", m_LevelManager.getCurrentLevel());
		m_Hud.setLevel(levelString);

		m_Hud.setTime(std::format("{:.2}", m_TimeRemainingInSeconds));
	}

	if (m_IsSplitScreenMode)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
		return;
	}

	if (m_IsPlayerOneTheFocus)
	{
		m_MainView.setCenter(m_Thomas.getCenter());
	}
	else
	{
		m_MainView.setCenter(m_Bob.getCenter());
	}
}