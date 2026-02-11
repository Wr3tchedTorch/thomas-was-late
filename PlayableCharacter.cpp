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
}