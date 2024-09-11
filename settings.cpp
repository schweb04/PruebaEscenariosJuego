#include <stdexcept> 
#include <settings.hpp>
#include <animation.hpp>
#include <iostream>

const std::string Settings::ASSETS_PATH{"C:\\pruebaspr3\\assets"};
const std::string Settings::TEXTURES_PATH{"C:\\pruebaspr3\\assets\\textures"};

std::unordered_map<std::string,sf::Texture> Settings::textures{};

void Settings::init()
{
	Settings::load_textures();
	
}

void Settings::load_textures()
{
	sf::Texture texture{};
	//derecha
	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\der1.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Der1"] = texture;
	//Settings::AnimationRight.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\der2.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Der2"] = texture;
	//Settings::AnimationRight.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\der3.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Der3"] = texture;
	//Animation::AnimationRight.push_back(texture);

	//frente
	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\fre1.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Front1"] = texture;
	//Animation::AnimationFront.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\fre2.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Front2"] = texture;
	//Animation::AnimationFront.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\fre3.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Front3"] = texture;
	//Animation::AnimationFront.push_back(texture);

	//izquierda
	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\iz1.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Iz1"] = texture;
	//Animation::AnimationLeft.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\iz2.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Iz2"] = texture;
	//Animation::AnimationLeft.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\iz3.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Iz3"] = texture;
	//Animation::AnimationLeft.push_back(texture);

	//espalda
	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\back1.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Back1"] = texture;
	//Animation::AnimationBack.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\back2.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Back2"] = texture;
	//Animation::AnimationBack.push_back(texture);

	if (!texture.loadFromFile("C:\\pruebaspr3\\assets\\textures\\back3.png"))
	{
		std::cerr << "Error loading image" << std::endl;
		return;
	}
	Settings::textures["Back3"] = texture;
	//Animation::AnimationBack.push_back(texture);
}

void Settings::load_frames(std::vector<sf::Texture>& _AnimationRight, std::vector<sf::Texture>& _AnimationLeft, std::vector<sf::Texture>& _AnimationFront, std::vector<sf::Texture>& _AnimationBack)
{
	_AnimationRight.push_back(Settings::textures["Der1"]);
	_AnimationRight.push_back(Settings::textures["Der2"]);
	_AnimationRight.push_back(Settings::textures["Der3"]);
	_AnimationRight.push_back(Settings::textures["Der2"]);
	_AnimationLeft.push_back(Settings::textures["Iz1"]);
	_AnimationLeft.push_back(Settings::textures["Iz2"]);
	_AnimationLeft.push_back(Settings::textures["Iz3"]);
	_AnimationLeft.push_back(Settings::textures["Iz2"]);
	_AnimationFront.push_back(Settings::textures["Front1"]);
	_AnimationFront.push_back(Settings::textures["Front2"]);
	_AnimationFront.push_back(Settings::textures["Front3"]);
	_AnimationFront.push_back(Settings::textures["Front2"]);
	_AnimationBack.push_back(Settings::textures["Back1"]);
	_AnimationBack.push_back(Settings::textures["Back2"]);
	_AnimationBack.push_back(Settings::textures["Back3"]);
	_AnimationBack.push_back(Settings::textures["Back2"]);

}