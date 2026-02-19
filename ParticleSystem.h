#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"

class ParticleSystem : public sf::Drawable
{
private:
	std::vector<Particle> m_Particles;
	sf::VertexArray m_Vertices;
	float m_Duration;
	bool  m_IsRunning = false;

public:
	void init(int count);
	void update(float elapsed);
	void emitParticles(sf::Vector2f position);

	bool isRunning() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};