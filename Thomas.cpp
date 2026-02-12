#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas() : PlayableCharacter(TextureHolder::GetTexture("graphics/thomas.png"))
{
    m_JumpDurationInSeconds = .45f;
}

bool Thomas::handleInput()
{
    return false;
}
