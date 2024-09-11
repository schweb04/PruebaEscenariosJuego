#include<C:\Users\eldry\source\repos\PruebaEscenariosJuego\settings.hpp>
#include<C:\Users\eldry\source\repos\PruebaEscenariosJuego\char.hpp>
#include<C:\Users\eldry\source\repos\PruebaEscenariosJuego\animation.hpp>

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




float Character::pos_x(sf::Sprite& spr)noexcept
{
	return spr.getPosition().x;
}

float Character::pos_y(sf::Sprite& spr)noexcept
{
	return spr.getPosition().y;
}

void Character::set_x(float _x )noexcept
{
	float _y = sprite.getPosition().y;
	sprite.setPosition(_x, _y);
}
void Character::set_y(float _y) noexcept
{
	float _x = sprite.getPosition().x;
	sprite.setPosition(_x, _y);
}

void Character::limit_map() noexcept
{
	float ancho = Settings::CHARACTER_WIDTH;
	float alto = Settings::CHARACTER_HEIGHT;

	if (pos_x(sprite) < 160)
	{
		set_x(160);
	}
	if (pos_x(sprite) >= 160 && pos_x(sprite) < 230)
	{
		if (pos_y(sprite) < 280)
		{
			set_y(280);
		}

		else if (pos_y(sprite) > 325)
		{
			set_y(325);
		}
	}

	if (pos_x(sprite) >= 230 && pos_x(sprite) <= 275)
	{
		int marca = 230;
		int marca_y = 335;
		if (pos_y(sprite) < 270)
		{
			set_y(270);
		}
		//Parte de abajo con movilidad escalera
		if (pos_x(sprite) >= marca + 0 && pos_x(sprite) < marca + 5)
		{
			if (pos_y(sprite) > marca_y - 5)
			{
				set_y(marca_y - 5);
			}
		}

		else if (pos_x(sprite) >= marca + 5 && pos_x(sprite) < marca + 10)
		{
			if (pos_y(sprite) > marca_y - 10)
			{
				set_y(marca_y - 10);
			}
		}

		else if (pos_x(sprite) >= marca + 10 && pos_x(sprite) < marca + 15)
		{
			if (pos_y(sprite) > marca_y - 15)
			{
				set_y(marca_y - 15);
			}
		}

		else if (pos_x(sprite) >= marca + 15 && pos_x(sprite) < marca + 20)
		{
			if (pos_y(sprite) > marca_y - 20)
			{
				set_y(marca_y - 20);
			}
		}

		else if (pos_x(sprite) >= marca + 20 && pos_x(sprite) < marca + 25)
		{
			if (pos_y(sprite) > marca_y - 25)
			{
				set_y(marca_y - 25);
			}
		}

		else if (pos_x(sprite) >= marca + 25 && pos_x(sprite) < marca + 30)
		{
			if (pos_y(sprite) > marca_y - 30)
			{
				set_y(marca_y - 30);
			}
		}

		else if (pos_x(sprite) >= marca + 30 && pos_x(sprite) < marca + 35)
		{
			if (pos_y(sprite) > marca_y - 35)
			{
				set_y(marca_y - 35);
			}
		}

		else if (pos_x(sprite) >= marca + 35 && pos_x(sprite) < marca + 40)
		{
			if (pos_y(sprite) > marca_y - 40)
			{
				set_y(marca_y - 40);
			}
		}

		else if (pos_x(sprite) >= marca + 40 && pos_x(sprite) <= marca + 45)
		{
			if (pos_y(sprite) > marca_y - 45)
			{
				set_y(marca_y - 45);
			}
		}
	}

	if (pos_x(sprite) > 275 && pos_x(sprite)  < 505)
	{
		if (pos_y(sprite) > 290)
		{
			set_y(290);
		}
		//Parte de arriba del puente
		if (pos_x(sprite) >= 365 && pos_x(sprite) < 470)
		{
			{
				if (pos_x(sprite) >= 365 + 0 && pos_x(sprite) < 365 + 5)
				{
					if (pos_y(sprite) < 265 - 5)
					{
						set_y(265 - 5);
					}
				}

				else if (pos_x(sprite) >= 365 + 5 && pos_x(sprite) < 365 + 10)
				{
					if (pos_y(sprite) < 265 - 10)
					{
						set_y(265 - 10);
					}
				}
				else if (pos_x(sprite) >= 365 + 10 && pos_x(sprite) < 365 + 15)
				{
					if (pos_y(sprite) < 265 - 15)
					{
						set_y(265 - 15);
					}
				}
				else if (pos_x(sprite) >= 365 + 15 && pos_x(sprite) < 365 + 20)
				{
					if (pos_y(sprite) < 265 - 20)
					{
						set_y(265 - 20);
					}
				}
				else if (pos_x(sprite) >= 365 + 20 && pos_x(sprite) < 365 + 25)
				{
					if (pos_y(sprite) < 265 - 25)
					{
						set_y(265 - 25);
					}
				}
				else if (pos_x(sprite) >= 365 + 25 && pos_x(sprite) < 365 + 30)
				{
					if (pos_y(sprite) < 265 - 30)
					{
						set_y(265 - 30);
					}
				}
				else 
				{
					if (pos_y(sprite) < 265 - 35)
					{
						set_y(265 - 35);
					}
				}
			}
		}

		else if (pos_x(sprite) >= 470 && pos_x(sprite) < 505)
		{
			if(pos_x(sprite) >= 470 + 0 && pos_x(sprite) < 470 + 5)
			{
				if (pos_y(sprite) < 265 - 35 + 5)
				{
					set_y(265 - 35 + 5);
				}
			}

			else if (pos_x(sprite) >= 470 + 5 && pos_x(sprite) < 470 + 10)
			{
				if (pos_y(sprite) < 265 - 35 + 10)
				{
					set_y(265 - 35 + 10);
				}
			}

			else if (pos_x(sprite) >= 470 + 10 && pos_x(sprite) < 470 + 15)
			{
				if (pos_y(sprite) < 265 - 35 + 15)
				{
					set_y(265 - 35 + 15);
				}
			}

			else if (pos_x(sprite) >= 470 + 15 && pos_x(sprite) < 470 + 20)
			{
				if (pos_y(sprite) < 265 - 35 + 20)
				{
					set_y(265 - 35 + 20);
				}
			}

			else if (pos_x(sprite) >= 470 + 20 && pos_x(sprite) < 470 + 25)
			{
				if (pos_y(sprite) < 265 - 35 + 25)
				{
					set_y(265 - 35 + 25);
				}
			}

			else if (pos_x(sprite) >= 470 + 25 && pos_x(sprite) < 470 + 30)
			{
				if (pos_y(sprite) < 265 - 35 + 30)
				{
					set_y(265 - 35 + 30);
				}
			}

			else if (pos_x(sprite) >= 470 + 30 && pos_x(sprite) < 470 + 35)
			{
				if (pos_y(sprite) < 265 - 35 + 35)
				{
					set_y(265 - 35 + 35);
				}
			}
		}


		else
		{
			if (pos_y(sprite) < 265)
			{
				set_y(265);
			}
			else if (pos_y(sprite) > 290)
			{
				set_y(290);
			}
		}
	}
	
	
	if (pos_x(sprite) >= 505 && pos_x(sprite) <= 572)
	{
		if (pos_y(sprite) < 276)
		{
			set_y(276);
		}
		else if (pos_y(sprite) > 290)
		{
			set_y(290);
		}
	}
	if (pos_x(sprite) > 572)
	{
		set_x(572);
	}
}





void Character::move(float& mov_x,float& mov_y) noexcept
{
	sprite.move(mov_x, mov_y);
	limit_map();
}

