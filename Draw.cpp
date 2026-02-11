#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(sf::Color::White);

	if (m_IsSplitScreenMode)
	{
		m_Window.setView(m_BackgroundLeftView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_LeftView);

		m_Window.setView(m_BackgroundRightView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);
	}
	else
	{
		m_Window.setView(m_BackgroundMainView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MainView);
	}
	m_Window.setView(m_HudView);

	m_Window.display();
}