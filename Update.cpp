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