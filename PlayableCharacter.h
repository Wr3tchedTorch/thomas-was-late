#pragma once
#include <SFML/Graphics.hpp>

class PlayableCharacter
{
protected:
	sf::Sprite m_Sprite;
	
	bool m_IsJumping;
	bool m_IsFalling;

	bool m_IsLeftPressed;
	bool m_IsRightPressed;

	float m_JumpDurationInSeconds;
	float m_TimeSinceJumpStartedInSeconds;

	bool  m_JustJumped = false;

private:
	float m_Gravity;
	float m_Speed = 400;

	const sf::Texture& m_Texture;
	sf::Vector2f m_Position;

	sf::FloatRect m_FeetBounds;
	sf::FloatRect m_HeadBounds;
	sf::FloatRect m_LeftBounds;
	sf::FloatRect m_RightBounds;

public:
	void spawn(sf::Vector2f startPosition, float gravity);

	virtual bool handleInput() = 0;

	sf::FloatRect getGlobalBounds();

	sf::FloatRect getFeetBounds();
	sf::FloatRect getHeadBounds();
	sf::FloatRect getLeftBounds();
	sf::FloatRect getRightBounds();

	sf::Vector2f getCenter();

	const sf::Sprite& getSprite();

	void stopLeft(float position);
	void stopRight(float position);

	void stopFalling(float position);
	void stopJumping();

	void update(float delta);
};
