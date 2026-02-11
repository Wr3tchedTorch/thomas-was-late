#include "Engine.h"

void Engine::input()
{
	while (const std::optional event = m_Window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			m_Window.close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
			{
				m_IsPlaying = true;
			}
			else if (keyPressed->scancode == sf::Keyboard::Scancode::Q)
			{
				m_IsPlayerOneTheFocus = !m_IsPlayerOneTheFocus;
			}
			else if (keyPressed->scancode == sf::Keyboard::Scancode::E)
			{
				m_IsSplitScreenMode = !m_IsSplitScreenMode;
			}
		}
	}
}