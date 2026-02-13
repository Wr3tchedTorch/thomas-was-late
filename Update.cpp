#include "Engine.h"

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

		if (hasThomasReachedGoal && hasBobReachedGoal)
		{
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