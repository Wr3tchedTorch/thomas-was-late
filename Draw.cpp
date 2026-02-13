#include "Engine.h"

void Engine::draw()
{
	m_Window.clear(sf::Color::White);

	if (m_IsSplitScreenMode)
	{
		m_Window.setView(m_BackgroundLeftView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_LeftView);

		m_Window.draw(m_VertexArrayLevel, &m_TextureTiles);

		m_Window.draw(m_Bob.getSprite());
		m_Window.draw(m_Thomas.getSprite());

		m_Window.setView(m_BackgroundRightView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_RightView);

		m_Window.draw(m_VertexArrayLevel, &m_TextureTiles);

		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		m_Window.setView(m_BackgroundMainView);
		m_Window.draw(m_BackgroundSprite);
		m_Window.setView(m_MainView);

		m_Window.draw(m_VertexArrayLevel, &m_TextureTiles);

		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}
	m_Window.setView(m_HudView);

	m_Window.display();
}