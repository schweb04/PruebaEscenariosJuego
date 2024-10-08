
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>

#include<C:\Users\eldry\source\repos\PruebaEscenariosJuego\settings.hpp>
#include<C:\Users\eldry\source\repos\PruebaEscenariosJuego\char.hpp>
#include<C:\Users\eldry\source\repos\PruebaEscenariosJuego\animation.hpp>

void fun_animation(float& timeSinceLastUpdate, float& timeBetweenUpdates, std::vector<sf::Texture>& Myvector, int& currentFrame, Character& chara)
{
	if (timeSinceLastUpdate >= timeBetweenUpdates) {
		timeSinceLastUpdate = 0.0f;
		currentFrame = (currentFrame + 1) % Myvector.size();
		chara.setTexture(Myvector[currentFrame]);
	}
}




int main()
{
	Settings::init();//Inicializacion de texturas
	sf::Clock clock;//timer
	Animation MyAnimation;//Structura que guarda los frames
	Settings::load_frames(MyAnimation.AnimationRight, MyAnimation.AnimationLeft, MyAnimation.AnimationFront, MyAnimation.AnimationBack);//Cargado de frames


	int currentFrame = 0;
	float timeSinceLastUpdate = 0.0f;
	float timeBetweenUpdates = 0.01f; // Ajustar la velocidad de la animaci�n


	sf::RenderWindow window{ sf::VideoMode{Settings::WINDOW_WIDTH,Settings::WINDOW_HEIGHT} , "Demo", sf::Style::Close};//Ventana
	sf::RenderTexture render_texture{};//Tectura
	render_texture.create(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT);//Crear textura

	//Escala de sprite
	sf::Vector2f scale_factors{
		float(Settings::WINDOW_WIDTH) / float(Settings::VIRTUAL_WIDTH),
		float(Settings::WINDOW_HEIGHT) / float(Settings::VIRTUAL_HEIGHT)
	};
	Character character//Inicializacion de personaje
	{
		321.0f, 270.0f, Settings::CHARACTER_WIDTH, Settings::CHARACTER_HEIGHT
	};
	sf::Texture tex2;
	tex2.loadFromFile("C:\\pruebaspr3\\assets\\textures\\iz3.png");
	sf::Sprite ps2{tex2};
	Character npc
	{
		600,270, 30, 50, ps2
	};



	sf::Sprite render_sprite{render_texture.getTexture()};//Asignacion de la textura a un sprite
	render_sprite.setScale(scale_factors);
	//Fuente para ver la posicion del sprite

	sf::Font font;
	if (!font.loadFromFile("C:\\pruebaspr3\\mifuente.ttf")) {
		std::cerr<<"Fallo al cargar \n";
	}
	//Texto a mostrar
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);

	float speed = 10.0f;



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Obtener el tiempo transcurrido desde el �ltimo frame
		float deltaTime = clock.restart().asSeconds();
		timeSinceLastUpdate += deltaTime;

		// Movimiento del sprite basado en las teclas presionadas
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

			float x = float((-1.0) * (speed));
			float y = 0.0;
			character.move(x, y);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationLeft, currentFrame, character);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

			float x = float((1.0) * (speed) /** (deltaTime)*/);
			float y = 0.0;
			character.move(x, y);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationRight, currentFrame, character);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{

			float x = 0.0;
			float y = float((-1.0) * (speed)   /** (deltaTime)*/);
			character.move(x, y);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationBack, currentFrame, character);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{

			float x = 0.0;
			float y = float((1.0) * (speed) );
			character.move(x, y);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationFront, currentFrame, character);
		}

		
		sf::FloatRect spriteBounds = character.get_sprite().getGlobalBounds();
		float posX = spriteBounds.left;
		float posY = spriteBounds.top;

		// Formatear el texto
		std::string textString = "Posici�n: X = " + std::to_string(posX) + ", Y = " + std::to_string(posY);
		text.setString(textString);

		// Posicionar el texto donde quieras
		text.setPosition(10, 10); // Esquina superior izquierda de la ventana



		render_texture.clear(sf::Color::Black);//Fondo negro
		sf::Texture fondo;
		fondo.loadFromFile("C:\\pruebaspr3\\assets\\textures\\fondo.png");//Cargado de imagen de fondo
		render_texture.draw(sf::Sprite{ fondo });//Pintar fondo
		character.render(render_texture);
		npc.render(render_texture);
		render_texture.display();


		window.draw(render_sprite);//pintar el sprite con el personaje en la ventana
		window.draw(text);
		window.display();
	}
	return EXIT_SUCCESS;
}
