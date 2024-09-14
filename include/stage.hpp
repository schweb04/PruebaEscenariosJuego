#pragma once

#include<SFML/Graphics.hpp>

class Stage
{
public:
	Stage(float _x, float _y, float _w, float _h) noexcept;

	Stage(float _x, float _y, float _w, float _h, sf::Sprite spr) noexcept;

	Stage(const Stage&) = delete;

	Stage& operator = (Stage&) = delete;

	void render(sf::RenderTarget& targer) const noexcept;

	sf::Sprite get_sprite() noexcept;

	float pos_x(sf::Sprite& spr)noexcept;

	float pos_y(sf::Sprite& spr)noexcept;

	void set_x(float _x)noexcept;

	void set_y(float _y)noexcept;

	void limit_map() noexcept;

	void move(float& mov_x, float& mov_y) noexcept;

	void setTexture(sf::Texture& tex)noexcept;



private:

	float x;
	float y;
	float width;
	float height;
	sf::Sprite sprite;
};

