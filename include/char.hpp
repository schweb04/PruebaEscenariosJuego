#pragma once 

#include <SFML/Graphics.hpp>

enum class Current_stage
{
	Principal_stage,
	casa_1,
	casa_2
};

class Character
{
public:
	Character(float _x, float _y, float _w, float _h) noexcept;

	Character(float _x, float _y, float _w, float _h, sf::Sprite spr) noexcept;

	Character(const Character&) = delete;

	Character& operator = (Character&) = delete;

	void render(sf::RenderTarget& targer) const noexcept;

	sf::Sprite get_sprite() noexcept;

	void move(float& mov_x, float& mov_y, Current_stage& _stage) noexcept;

	void setTexture(sf::Texture& tex) noexcept;

	void setPosition(float _x, float _y) noexcept;
	
private:

	float x;
	float y;
	float width;
	float height;
	sf::Sprite sprite;
};