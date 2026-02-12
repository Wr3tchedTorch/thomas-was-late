#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
private:

public:
	Thomas();

	bool handleInput() override;
};

