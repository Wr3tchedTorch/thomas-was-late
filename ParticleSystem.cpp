#include "ParticleSystem.h"
#include <numbers>

void ParticleSystem::init(int count)
{
	m_Vertices.setPrimitiveType(sf::PrimitiveType::Points);
	m_Vertices.resize(count);

	for (int i = 0; i < count; ++i)
	{
		srand(time(0) * i);
		float angle = (rand() % 360) * std::numbers::pi / 180.0f;
		float speed = (rand() % 600) + 600;

		sf::Vector2f direction({cos(angle) * speed, sin(angle) * speed});
		m_Particles.push_back(Particle(direction));
	}
}

void ParticleSystem::update(float delta)
{
	m_Duration -= delta;

	int currentVertex = 0;
	for (auto& particle : m_Particles)
	{
		particle.update(delta);

		m_Vertices[currentVertex++].position = particle.getPosition();
	}

	if (m_Duration < 0)
	{
		m_IsRunning = false;
	}
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
