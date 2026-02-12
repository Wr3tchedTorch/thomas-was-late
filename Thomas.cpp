#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas() : PlayableCharacter(TextureHolder::GetTexture("graphics/thomas.png"))
{
    m_JumpDurationInSeconds = .45f;
}

bool Thomas::handleInput()
{
    m_JustJumped = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    {
        if (!m_IsJumping && !m_IsFalling)
        {
            m_IsJumping  = true;
            m_JustJumped = true;
            m_TimeSinceJumpStartedInSeconds = 0;
        }
    }
    else
    {
        m_IsJumping = false;
        m_IsFalling = true;
    }

    m_IsLeftPressed  = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A);
    
    m_IsRightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D);

    return m_JustJumped;
}
