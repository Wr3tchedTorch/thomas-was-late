#include "HUD.h"

HUD::HUD() :
	m_Font("fonts/Roboto-Light.ttf"),
	m_StartText(m_Font),
	m_LevelText(m_Font),
	m_TimeText(m_Font)
{
	sf::Vector2u resolution = sf::VideoMode::getDesktopMode().size;

	m_StartText.setCharacterSize(100);
	sf::FloatRect startTextbounds = m_StartText.getLocalBounds();
	m_StartText.setOrigin(
		{
			startTextbounds.size.x / 2,
			startTextbounds.size.y / 2
		});
	m_StartText.setString("Press `Enter` to play!");

	m_LevelText.setCharacterSize(75);
	m_LevelText.setPosition({ 25, 0 });
	m_LevelText.setString("1");

	m_TimeText.setCharacterSize(75);
	m_TimeText.setPosition({ resolution.x - 150, 0 });
	m_TimeText.setString("------");
}

sf::Text HUD::getMessage()
{
	return m_StartText;
}

sf::Text HUD::getLevel()
{
	return m_LevelText
}

sf::Text HUD::getTime()
{
	return m_TimeText;
}

void HUD::setLevel(std::string text)
{
	m_LevelText.setString(text);
}

void HUD::setTime(std::string text)
{
	m_TimeText.setString(text);
}
