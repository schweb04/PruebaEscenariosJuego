#pragma once 

#include <SFML/Graphics.hpp>

class Character
{
public:
	Character(float _x, float _y, float _w, float _h) noexcept;

	Character(float _x, float _y, float _w, float _h, sf::Sprite spr) noexcept;

	Character(const Character&) = delete;

	Character& operator = (Character&) = delete;

	void render(sf::RenderTarget& targer) const noexcept;

	sf::Sprite get_sprite() noexcept;

	void move(float& mov_x, float& mov_y) noexcept;

	void setTexture(sf::Texture& tex)noexcept;
	
private:

	float x;
	float y;
	float width;
	float height;
	sf::Sprite sprite;
};