#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob() : PlayableCharacter(TextureHolder::GetTexture("graphics/bob.png"))
{
    m_JumpDurationInSeconds = .25f;
}

bool Bob::handleInput()
{
    m_JustJumped = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
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

    m_IsLeftPressed  = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left);

    m_IsRightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right);

    return m_JustJumped;
}
