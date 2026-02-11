#include "PlayableCharacter.h"

void PlayableCharacter::spawn(sf::Vector2f startPosition, float gravity)
{
	m_Position = startPosition;
	m_Gravity  = gravity;

	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::update(float delta)
{
	if (m_IsLeftPressed)
	{
		m_Position.x -= m_Speed * delta;
	}
	if (m_IsRightPressed)
	{
		m_Position.x += m_Speed * delta;
	}

	if (m_IsJumping)
	{
		m_TimeSinceJumpStartedInSeconds += delta;

		if (m_TimeSinceJumpStartedInSeconds >= m_JumpDurationInSeconds)
		{
			m_IsJumping = false;
			m_IsFalling = true;

			m_TimeSinceJumpStartedInSeconds = 0;
		}
		else
		{
			m_Position.y -= m_Gravity * 2.0f * delta;
		}
	}

	if (m_IsFalling)
	{
		m_Position.y += m_Gravity * delta;
	}

	sf::FloatRect characterBounds = getGlobalBounds();

	m_FeetBounds.position.x = characterBounds.position.x + 3;
	m_FeetBounds.position.y = characterBounds.position.y + characterBounds.size.y - 1;
	m_FeetBounds.size.x = characterBounds.size.x - 6;
	m_FeetBounds.size.y = 1;

	m_HeadBounds.position.x = characterBounds.position.x;
	m_HeadBounds.position.y = characterBounds.position.y + (characterBounds.size.y * .3f);
	m_HeadBounds.size.x = characterBounds.size.x;
	m_HeadBounds.size.y = 1;

	m_RightBounds.position.x = characterBounds.position.x +  characterBounds.size.x - 2;
	m_RightBounds.position.y = characterBounds.position.y + (characterBounds.size.y * .35f);
	m_RightBounds.size.x = 1;
	m_RightBounds.size.y = characterBounds.size.y * .3f;

	m_RightBounds.position.x = characterBounds.position.x;
	m_RightBounds.position.y = characterBounds.position.y + (characterBounds.size.y * .5f);
	m_RightBounds.size.x = 1;
	m_RightBounds.size.y = characterBounds.size.y * .3f;

	m_Sprite.setPosition(m_Position);
}

sf::FloatRect PlayableCharacter::getFeetBounds()
{
	return sf::FloatRect();
}
