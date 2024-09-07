#pragma once 

#include<filesystem>
#include<string>
#include<unordered_map>
#include<vector>


#include<SFML/Graphics.hpp>

struct Settings
{
	static const std::string ASSETS_PATH;
	static const std::string TEXTURES_PATH;

	static constexpr int WINDOW_WIDTH{1080};
	static constexpr int WINDOW_HEIGHT{608};
	static constexpr int VIRTUAL_WIDTH{1080 * 4 / 5};
	static constexpr int VIRTUAL_HEIGHT{608 * 4 / 5};
	static constexpr float CHARACTER_WIDTH{46.f};
	static constexpr float CHARACTER_HEIGHT{46.f};
	static constexpr float SPEED{40.f};


	static std::unordered_map<std::string,sf::Texture> textures;

	static void init();

	static void load_textures();

	static void load_frames(std::vector<sf::Texture>& _AnimationRight, std::vector<sf::Texture>& _AnimationLeft, std::vector<sf::Texture>& _AnimationFront, std::vector<sf::Texture>& _AnimationBack);
};