#include "SoundManager.h"

SoundManager::SoundManager() :
	m_FireBuffer("sound/fire1.wav"),
	m_FallInFireBuffer("sound/fallinfire.wav"),
	m_FallInWaterBuffer("sound/fallinwater.wav"),
	m_JumpBuffer("sound/jump.wav"),
	m_ReachGoalBuffer("sound/reachgoal.wav"),

	m_FallInFireSound(m_FallInFireBuffer),
	m_FallInWaterSound(m_FallInWaterBuffer),
	m_JumpSound(m_JumpBuffer),
	m_ReachGoalSound(m_ReachGoalBuffer)
{
	int distance	= 150;
	int attenuation = 15;

	for (int i = 0; i < 3; i++)
	{
		sf::Sound fireSound(m_FireBuffer);
		fireSound.setMinDistance(distance);
		fireSound.setAttenuation(attenuation);
		fireSound.setLooping(true);

		m_FireSounds.push_back(fireSound);
	}
}

void SoundManager::playFire(sf::Vector2f emitterLocation, sf::Vector2f listenerLocation)
{
	sf::Listener::setPosition({ listenerLocation.x, listenerLocation.y, 0.0f });

	sf::Sound& fireSound = m_FireSounds.at(m_NextFireSound);
	
	fireSound.setPosition({ emitterLocation.x, emitterLocation.y, 0.0f });

	if (fireSound.getStatus() != sf::Sound::Status::Playing)
	{
		fireSound.play();
	}

	m_NextFireSound++;
	if (m_NextFireSound >= m_FireSounds.size())
	{
		m_NextFireSound = 0;
	}
}

void SoundManager::playFallInFire()
{
	m_FallInFireSound.setRelativeToListener(true);
	m_FallInFireSound.play();
}

void SoundManager::playFallInWater()
{
	m_FallInWaterSound.setRelativeToListener(true);
	m_FallInWaterSound.play();
}

void SoundManager::playJump()
{
	m_JumpSound.setRelativeToListener(true);
	m_JumpSound.play();
}

void SoundManager::playReachGoal()
{
	m_ReachGoalSound.setRelativeToListener(true);
	m_ReachGoalSound.play();
}
