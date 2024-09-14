#include <settings.hpp>
#include <char.hpp>
#include <animation.hpp>

Character::Character(float _x, float _y, float _w, float _h) noexcept
	: x{ _x }, y{ _y }, width{ _w }, height{ _h }, sprite{ Settings::textures["Der1"] }
{
	sprite.setPosition(x,y);
}

Character::Character(float _x, float _y, float _w, float _h, sf::Sprite spr) noexcept
	: x{ _x }, y{ _y }, width{ _w }, height{ _h }, sprite{ spr }
{
	sprite.setPosition(x, y);
}

void Character::render(sf::RenderTarget& targer) const noexcept
{
	targer.draw(sprite);
}

void Character::setTexture(sf::Texture& tex) noexcept
{
    sprite.setTexture(tex);
}

sf::Sprite Character::get_sprite() noexcept
{
	return sprite;
}

void Character::move(float& mov_x,float& mov_y) noexcept
{
	sprite.move(mov_x, mov_y);
	Settings::limit_principal_map(sprite);
}

