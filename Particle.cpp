#include "Particle.h"

Particle::Particle(sf::Vector2f direction)
{
	m_Velocity = direction;
}

void Particle::update(float delta)
{
	m_Position += m_Velocity * delta;
}

void Particle::setPosition(sf::Vector2f toPosition)
{
	m_Position = toPosition;
}

sf::Vector2f Particle::getPosition()
{
	return m_Position;
}
