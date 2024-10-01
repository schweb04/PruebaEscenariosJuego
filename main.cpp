
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include <vector>

#include <settings.hpp>
#include <char.hpp>
#include <animation.hpp>
#include <stateStack.hpp>
#include <stage.hpp>






void fun_animation(float& timeSinceLastUpdate, float& timeBetweenUpdates, std::vector<sf::Texture>& Myvector, int& currentFrame, Character& chara)
{
	if (timeSinceLastUpdate >= timeBetweenUpdates) {
		timeSinceLastUpdate = 0.0f;
		currentFrame = (currentFrame + 1) % Myvector.size();
		chara.setTexture(Myvector[currentFrame]);
	}
}
//prueba

void load_monster1(std::vector<sf::Texture>& _A)
{
	_A.push_back(Settings::textures["Monster1_at1"]);
	_A.push_back(Settings::textures["Monster1_at2"]);
	_A.push_back(Settings::textures["Monster1_at3"]);
	_A.push_back(Settings::textures["Monster1_at4"]);
}



int main()
{
	Settings::init();//Inicializacion de texturas
	sf::Clock clock;//timer
	Animation MyAnimation;//Structura que guarda los frames
	Attack_animation animation_monster1;// estructura que guarda los frames del monstruo 1
	Settings::load_frames(MyAnimation.AnimationRight, MyAnimation.AnimationLeft, MyAnimation.AnimationFront, MyAnimation.AnimationBack);//Cargado de frames
	load_monster1(animation_monster1.Animiation_Attack);

	int currentFrame = 0;
	float timeSinceLastUpdate = 0.0f;
	float timeBetweenUpdates = 0.01f; // Ajustar la velocidad de la animación

	int m_currentFrame = 0;
	float m_timeSinceLastUpdate = 0.0f;
	float m_timeBetweenUpdates = 0.1f;


	bool mirar_der = false;
	bool mirar_arriba = false;
	bool mirar_iz = false;
	bool mirar_abajo = false;
	bool show_npc = true;


	sf::RenderWindow window{ sf::VideoMode{Settings::WINDOW_WIDTH,Settings::WINDOW_HEIGHT} , "Demo", sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar };//Ventana

	sf::Texture fondo;
	sf::Texture fondo2;
	sf::Texture fondo3;
	sf::Texture fondo4;

	fondo.loadFromFile("assets/textures/fondo.png");//Cargado de imagen de fondo
	std::shared_ptr<Stage> mainStage = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ fondo });
	
	fondo2.loadFromFile("assets/textures/casa1.png");//Cargado de imagen de fondo
	std::shared_ptr<Stage> casa1 = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ fondo2 });

	fondo3.loadFromFile("assets/textures/outside.png");//Cargado de imagen de fondo
	std::shared_ptr<Stage> outside = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ fondo3 });

	fondo4.loadFromFile("assets/textures/escena_combate.png");//Cargado de imagen de fondo
	std::shared_ptr<Stage> fight = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ fondo4 });

	
	StateStack allStages;// StateStack
	allStages.pushStage(mainStage);


	sf::RenderTexture render_texture{};//Textura
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
	tex2.loadFromFile("assets/textures/iz3.png");
	sf::Sprite ps2{tex2};

	Character npc
	{
		580, 280, 30, 50, ps2
	};


	sf::Sprite monster1_spr{ Settings::textures["Monster1_stand"] };//Monster 1
	Character monster1
	{
		400, 230, 53, 48, monster1_spr
	};

	sf::Texture tex3;
	tex3.loadFromFile("assets/textures/back2.png");
	sf::Sprite ps3{ tex3 };
	Character npc2
	{
		185, 325, 30, 50, ps3
	};



	sf::Sprite render_sprite{render_texture.getTexture()};//Asignacion de la textura a un sprite
	render_sprite.setScale(scale_factors);
	//Fuente para ver la posicion del sprite

	sf::Font font;
	if (!font.loadFromFile("assets/mifuente.ttf")) 
	{
		std::cerr<<"Fallo al cargar \n";
	}


	//Texto a mostrar
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);

	//Textura y sprite para mensaje de presione e
	sf::Texture press_e_action;
	press_e_action.loadFromFile("assets/textures/entrar.jpg");
	sf::Sprite press_e{press_e_action};

	//Identificador del stage
	Current_stage My_current_stage{ Current_stage::Principal_stage };

	float speed = 120.5f;



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Obtener el tiempo transcurrido desde el último frame
		float deltaTime = clock.restart().asSeconds();
		timeSinceLastUpdate += deltaTime;
		if (My_current_stage == Current_stage::combat)
		{
			m_timeSinceLastUpdate += deltaTime;
		}

		// Movimiento del sprite basado en las teclas presionadas
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && My_current_stage != Current_stage::combat)
		{

			float x = float((-1.0) * (speed) * (deltaTime));
			float y = 0.0;
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationLeft, currentFrame, character);

			mirar_iz = true;
			mirar_abajo = false;
			mirar_der = false;
			mirar_arriba = false;

		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && My_current_stage != Current_stage::combat)
		{

			float x = float((1.0) * (speed) * (deltaTime));
			float y = 0.0;
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationRight, currentFrame, character);

			mirar_iz = false;
			mirar_abajo = false;
			mirar_der = true;
			mirar_arriba = false;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && My_current_stage != Current_stage::combat)
		{

			float x = 0.0;
			float y = float((-1.0) * (speed) * (deltaTime));
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationBack, currentFrame, character);

			mirar_iz = false;
			mirar_abajo = false;
			mirar_der = false;
			mirar_arriba = true;


		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && My_current_stage != Current_stage::combat)
		{

			float x = 0.0;
			float y = float((1.0) * (speed) * (deltaTime));
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.AnimationFront, currentFrame, character);

			mirar_iz = false;
			mirar_abajo = true;
			mirar_der = false;
			mirar_arriba = false;
		}

		
		sf::FloatRect spriteBounds = character.get_sprite().getGlobalBounds();
		float posX = spriteBounds.left;
		float posY = spriteBounds.top;

		// Formatear el texto
		std::string textString = "Posición: X = " + std::to_string(posX) + ", Y = " + std::to_string(posY);
		text.setString(textString);

		// Posicionar el texto donde quieras
		text.setPosition(10, 10); // Esquina superior izquierda de la ventana

		if (posX >= 540.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && mirar_der && My_current_stage == Current_stage::Principal_stage)//Cambio de escenario con key 
		{
			character.setPosition(18.f, 324.f);
			
			allStages.pushStage(casa1);
			My_current_stage = Current_stage::casa_1;

			show_npc = false;
		}

		if (posX <= 18.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && mirar_iz && My_current_stage == Current_stage::casa_1) //Volver a escenario principal
		{
			character.setPosition(540.f, 276.f);

			allStages.popStage();
			My_current_stage = Current_stage::Principal_stage;

			show_npc = true;
		}

		if (posX <= 220.f && posY >= 285.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && mirar_abajo && My_current_stage == Current_stage::Principal_stage)//Cambio de escenario con key 
		{
			character.setPosition(405.f, 5.f);
			
			allStages.pushStage(outside);
			My_current_stage = Current_stage::outside;

			show_npc = false;
		}

		if (posY <= 10.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && mirar_arriba && My_current_stage == Current_stage::outside)
		{
			character.setPosition(185.f, 300.f);

			allStages.popStage();
			My_current_stage = Current_stage::Principal_stage;

			show_npc = true;
		}

		if (posY >= 190.f && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && mirar_abajo && My_current_stage == Current_stage::outside)
		{
			character.setPosition(198.f, 235.f);
			character.setTexture(Settings::textures["Der2"]);
			monster1.setPosition(489.f, 250.f);
			monster1.setTexture(Settings::textures["Monster1_at1"]);

			allStages.pushStage(fight);
			My_current_stage = Current_stage::combat;

			show_npc = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && My_current_stage == Current_stage::combat)
		{
			character.setPosition(400.f, 190.f);
			allStages.popStage();
			My_current_stage = Current_stage::outside;
			monster1.setPosition(400.f, 230.f);
			monster1.setTexture(Settings::textures["Monster1_diying"]);

			show_npc = false;

		}

		if (My_current_stage == Current_stage::combat && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			fun_animation(m_timeSinceLastUpdate, m_timeBetweenUpdates, animation_monster1.Animiation_Attack, m_currentFrame, monster1);
		}


		render_texture.clear(sf::Color::Black);//Fondo negro
		render_texture.draw(allStages.getCurrentStage()->get_sprite());//Pintar fondo
		character.render(render_texture);
		
		if (show_npc)
		{
			npc.render(render_texture);
			npc2.render(render_texture);
		}

		if (My_current_stage == Current_stage::outside || My_current_stage == Current_stage::combat)
		{
			monster1.render(render_texture);
		}

		//Mostrar mensaje para cambiar de escenario
		if (posX >= 540.f && mirar_der && My_current_stage == Current_stage::Principal_stage)
		{
			press_e.setPosition(522.f, 200.f);
			press_e_action.loadFromFile("assets/textures/entrar.jpg");

			render_texture.draw(press_e);
		}
		else if (posX <= 18.f && mirar_iz && My_current_stage == Current_stage::casa_1)
		{
			press_e.setPosition(posX + 10.f, posY - 40.f);
			press_e_action.loadFromFile("assets/textures/salir.jpg");

			render_texture.draw(press_e);
		}
		else if (posX <= 220.f && posY >= 285.f && mirar_abajo && My_current_stage == Current_stage::Principal_stage) 
		{
			press_e.setPosition(115.f, 380.f);
			press_e_action.loadFromFile("assets/textures/salir.jpg");

			render_texture.draw(press_e);

		}
		else if (posY <= 10.f && mirar_arriba && My_current_stage == Current_stage::outside)
		{
			press_e.setPosition(posX - 85.f, posY + 50.f);
			press_e_action.loadFromFile("assets/textures/entrar.jpg");
			
			render_texture.draw(press_e);
		}
		else if (posY >= 190.f && mirar_abajo && My_current_stage == Current_stage::outside)
		{
			press_e.setPosition(185, 200);
			press_e_action.loadFromFile("assets/textures/entrar.jpg");

			render_texture.draw(press_e);
		}
		else if (My_current_stage == Current_stage::combat)
		{
			press_e.setPosition(115.f, 380.f);
			press_e_action.loadFromFile("assets/textures/salir.jpg");

			render_texture.draw(press_e);

		}
		
		render_texture.display();


		window.draw(render_sprite);//pintar el sprite con el personaje en la ventana
		window.draw(text);
		window.display();
	}
	return EXIT_SUCCESS;
}
