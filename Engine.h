#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include "TextureHolder.h"
#include "Bob.h"
#include "Thomas.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"

class Engine
{
private:
	TextureHolder m_TextureHolderSingleton;

	HUD m_Hud;
	int m_FramesSinceLastHudUpdate;
	int m_FramesDelayPerHudUpdate;

	ParticleSystem	   m_ParticleSystem;
	SoundManager	   m_SoundManager;
	LevelManager	   m_LevelManager;
	sf::VertexArray	   m_VertexArrayLevel;
	const sf::Texture& m_TextureTiles;
	int** m_ArrayLevel = NULL;

	sf::Shader m_RippleShader;

	const int TILE_SIZE			= 50;
	const int VERTICES_PER_TILE = 6;
	
	const int GRAVITY = 300;

	sf::RenderWindow m_Window;

	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;

	sf::View m_BackgroundMainView;
	sf::View m_BackgroundLeftView;
	sf::View m_BackgroundRightView;

	sf::View m_HudView;

	Bob	   m_Bob;
	Thomas m_Thomas;

	const sf::Texture& m_BackgroundTexture;
	sf::Sprite m_BackgroundSprite;

	bool m_IsPlaying		   = false;
	bool m_IsSplitScreenMode   = false;
	bool m_IsPlayerOneTheFocus = true;

	float m_TimeRemainingInSeconds = 10;
	sf::Time m_GameTimeTotal;

	bool m_NewLevelRequired = true;

	std::vector<sf::Vector2f> m_FireEmitters;

	void update(float delta);
	void draw();
	void input();

	void loadLevel();
	bool detectCollisions(PlayableCharacter& character);

	void populateEmitters(std::vector<sf::Vector2f>& soundEmitters, int** arrayLevel);
public:
	Engine();
	void run();
};

