#include "Engine.h"

void Engine::update(float delta)
{
	if (m_IsPlaying)
	{
		m_TimeRemainingInSeconds -= delta;

		if (m_TimeRemainingInSeconds <= 0)
		{
			m_NewLevelRequired = true;
		}
	}
}