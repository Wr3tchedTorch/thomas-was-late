#include "Engine.h"

Engine::Engine() : 
	m_BackgroundTexture(TextureHolder::GetTexture("graphics/background.png")),
	m_TextureTiles(TextureHolder::GetTexture("graphics/tiles_sheet.png")),
	m_BackgroundSprite(m_BackgroundTexture)
{
	 sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	 
	 m_Window.create(videoMode, "Thomas was late by Eric", sf::State::Fullscreen);

	 sf::Vector2f screenResolution(videoMode.size);
	 sf::Vector2f screenCenter(screenResolution);
	 screenCenter.x /= 2;
	 screenCenter.y /= 2;

	 m_MainView.setSize(screenResolution);
	 m_MainView.zoom(3.0f);

	 m_BackgroundMainView.setSize(screenResolution);	 
	 m_BackgroundMainView.setCenter(screenCenter);

	 m_LeftView.setViewport( { {0.001f, 0.001f}, {0.498f, 0.998f} });
	 m_RightView.setViewport({ {0.5f  , 0.001f}, {0.499f, 0.998f} });

	 m_BackgroundLeftView.setViewport( { {0.001f, 0.001f}, {0.498f, 0.998f} });
	 m_BackgroundRightView.setViewport({ {0.5f  , 0.001f}, {0.499f, 0.998f} });

}

void Engine::run()
{
	sf::Clock clock;
	while (m_Window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		m_GameTimeTotal += deltaTime;

		float delta = deltaTime.asSeconds();

		input();
		update(delta);
		draw();
	}
}
