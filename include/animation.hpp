#pragma once
#include <SFML/Graphics.hpp>
#include <settings.hpp>
#include <vector>

struct Animation
{
	 std::vector<sf::Texture> AnimationRight;
	 std::vector<sf::Texture> AnimationLeft;
	 std::vector<sf::Texture> AnimationFront;
	 std::vector<sf::Texture> AnimationBack;
};

struct Attack_animation
{
	std::vector<sf::Texture> Animation_Attack;
};
