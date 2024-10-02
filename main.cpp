
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

int main()
{
	sf::Clock clock; //Timer
	Animation MyAnimation; //Estructura que guarda los frames
	Attack_animation animation_monster1; //Estructura que guarda los frames del monstruo 1

	Settings::init(animation_monster1.AttackAnimation);//Inicializacion de texturas
	Settings::load_frames(MyAnimation.RightAnimation, MyAnimation.LeftAnimation, MyAnimation.FrontAnimation, MyAnimation.BackAnimation);//Cargado de frames

	int currentFrame = 0;
	float timeSinceLastUpdate = 0.0f;
	float timeBetweenUpdates = 0.01f; //Ajustar la velocidad de la animaci�n

	int mCurrentFrame = 0;
	float mTimeSinceLastUpdate = 0.0f;
	float mTimeBetweenUpdates = 0.1f;


	bool lookRight = false;
	bool lookUp = false;
	bool lookLeft = false;
	bool lookDown = false;
	bool show_npc = true;
	bool monsterIsAlive = true;


	sf::RenderWindow window{ sf::VideoMode{Settings::WINDOW_WIDTH,Settings::WINDOW_HEIGHT} , "Demo", sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar };//Ventana

	sf::Texture background;
	sf::Texture background2;
	sf::Texture background3;
	sf::Texture background4;

	background.loadFromFile("assets/textures/mainStage.png"); 
	std::shared_ptr<Stage> mainStage = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ background });
	
	background2.loadFromFile("assets/textures/house.png");
	std::shared_ptr<Stage> casa1 = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ background2 });

	background3.loadFromFile("assets/textures/outside.png");
	std::shared_ptr<Stage> outside = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ background3 });

	background4.loadFromFile("assets/textures/outsideCombat.png");
	std::shared_ptr<Stage> fight = std::make_shared<Stage>(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT, sf::Sprite{ background4 });

	
	StateStack allStages; //Donde se manejar�n los escenarios
	allStages.pushStage(mainStage);


	sf::RenderTexture render_texture{};
	render_texture.create(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT);

	//Escala de sprite
	sf::Vector2f scale_factors
	{
		float(Settings::WINDOW_WIDTH) / float(Settings::VIRTUAL_WIDTH),
		float(Settings::WINDOW_HEIGHT) / float(Settings::VIRTUAL_HEIGHT)
	};
	
	Character character
	{
		321.0f, 270.0f, Settings::CHARACTER_WIDTH, Settings::CHARACTER_HEIGHT
	};
	
	sf::Texture tex2;
	tex2.loadFromFile("assets/textures/left3.png");
	sf::Sprite ps2{tex2};

	Character npc
	{
		580, 280, 30, 50, ps2
	};


	sf::Sprite monster1_spr{ Settings::textures["Monster1_stand"] };
	Character monster1
	{
		400, 230, 53, 48, monster1_spr
	};

	sf::Texture tex3;
	tex3.loadFromFile("assets/textures/back2.png");
	sf::Sprite ps3{ tex3 };
	Character npc2
	{
		185, 325, 70, 65, ps3
	};



	sf::Sprite render_sprite{render_texture.getTexture()};//Asignacion de la textura a un sprite
	render_sprite.setScale(scale_factors);

	sf::Font font;
	if (!font.loadFromFile("assets/mifuente.ttf")) 
	{
		std::cerr<<"Fallo al cargar \n";
	}


	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);


	sf::Texture press_e_action;
	press_e_action.loadFromFile("assets/textures/enter.png");
	sf::Sprite press_e{press_e_action};

	//Identificador del stage
	Current_stage My_current_stage{ Current_stage::MainStage };

	float speed = 120.5f;



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
		if (My_current_stage == Current_stage::Combat)
		{
			mTimeSinceLastUpdate += deltaTime;
		}

		// Movimiento del sprite basado en las teclas presionadas
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && My_current_stage != Current_stage::Combat)
		{

			float x = float((-1.0) * (speed) * (deltaTime));
			float y = 0.0;
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.LeftAnimation, currentFrame, character);

			lookLeft = true;
			lookDown = false;
			lookRight = false;
			lookUp = false;

		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && My_current_stage != Current_stage::Combat)
		{

			float x = float((1.0) * (speed) * (deltaTime));
			float y = 0.0;
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.RightAnimation, currentFrame, character);

			lookLeft = false;
			lookDown = false;
			lookRight = true;
			lookUp = false;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && My_current_stage != Current_stage::Combat)
		{

			float x = 0.0;
			float y = float((-1.0) * (speed) * (deltaTime));
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.BackAnimation, currentFrame, character);

			lookLeft = false;
			lookDown = false;
			lookRight = false;
			lookUp = true;


		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && My_current_stage != Current_stage::Combat)
		{

			float x = 0.0;
			float y = float((1.0) * (speed) * (deltaTime));
			character.move(x, y, My_current_stage);
			fun_animation(timeSinceLastUpdate, timeBetweenUpdates, MyAnimation.FrontAnimation, currentFrame, character);

			lookLeft = false;
			lookDown = true;
			lookRight = false;
			lookUp = false;
		}

		
		sf::FloatRect spriteBounds = character.get_sprite().getGlobalBounds();
		float posX = spriteBounds.left;
		float posY = spriteBounds.top;

		// Formatear el texto
		std::string textString = "Posici�n: X = " + std::to_string(posX) + ", Y = " + std::to_string(posY);
		text.setString(textString);

		// Posicionar el texto donde quieras
		text.setPosition(10, 10); 

		if (posX >= 540.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && lookRight && My_current_stage == Current_stage::MainStage) //Cambio de escenario con una tecla 
		{
			character.setPosition(18.f, 324.f);
			
			allStages.pushStage(casa1);
			My_current_stage = Current_stage::House;

			show_npc = false;
		}

		if (posX <= 18.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && lookLeft && My_current_stage == Current_stage::House) //Volver a escenario principal
		{
			character.setPosition(540.f, 276.f);

			allStages.popStage();
			My_current_stage = Current_stage::MainStage;

			show_npc = true;
		}

		if (posX <= 220.f && posY >= 285.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && lookDown && My_current_stage == Current_stage::MainStage)
		{
			character.setPosition(405.f, 5.f);
			
			allStages.pushStage(outside);
			My_current_stage = Current_stage::Outside;

			show_npc = false;
		}

		if (posY <= 10.f && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && lookUp && My_current_stage == Current_stage::Outside)
		{
			character.setPosition(185.f, 300.f);

			allStages.popStage();
			My_current_stage = Current_stage::MainStage;

			show_npc = true;
		}

		if (posY >= 190.f && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && lookDown && My_current_stage == Current_stage::Outside && monsterIsAlive)
		{
			monsterIsAlive = false;
			
			character.setPosition(198.f, 235.f);
			character.setTexture(Settings::textures["Right2"]);
			monster1.setPosition(489.f, 250.f);
			monster1.setTexture(Settings::textures["Monster1_at1"]);

			allStages.pushStage(fight);
			My_current_stage = Current_stage::Combat;

			show_npc = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && My_current_stage == Current_stage::Combat)
		{
			character.setPosition(400.f, 190.f);
			allStages.popStage();
			My_current_stage = Current_stage::Outside;
			monster1.setPosition(400.f, 230.f);
			monster1.setTexture(Settings::textures["Monster1_dead"]);

			show_npc = false;
			monsterIsAlive = false;

		}

		if (My_current_stage == Current_stage::Combat)
		{
			fun_animation(mTimeSinceLastUpdate, mTimeBetweenUpdates, animation_monster1.AttackAnimation, mCurrentFrame, monster1);
		}


		render_texture.clear(sf::Color::Black);
		render_texture.draw(allStages.getCurrentStage()->get_sprite());
		character.render(render_texture);
		
		if (show_npc)
		{
			npc.render(render_texture);
			npc2.render(render_texture);
		}

		if (My_current_stage == Current_stage::Outside || My_current_stage == Current_stage::Combat)
		{
			monster1.render(render_texture);
		}

		//Mostrar mensaje para cambiar de escenario
		if (posX >= 540.f && lookRight && My_current_stage == Current_stage::MainStage)
		{
			press_e.setPosition(522.f, 200.f);
			press_e_action.loadFromFile("assets/textures/enter.png");

			render_texture.draw(press_e);
		}
		else if (posX <= 18.f && lookLeft && My_current_stage == Current_stage::House)
		{
			press_e.setPosition(posX + 10.f, posY - 40.f);
			press_e_action.loadFromFile("assets/textures/exit.png");

			render_texture.draw(press_e);
		}
		else if (posX <= 220.f && posY >= 285.f && lookDown && My_current_stage == Current_stage::MainStage) 
		{
			press_e.setPosition(115.f, 380.f);
			press_e_action.loadFromFile("assets/textures/exit.png");

			render_texture.draw(press_e);

		}
		else if (posY <= 10.f && lookUp && My_current_stage == Current_stage::Outside)
		{
			press_e.setPosition(posX - 85.f, posY + 50.f);
			press_e_action.loadFromFile("assets/textures/enter.png");
			
			render_texture.draw(press_e);
		}
		else if (posY >= 190.f && lookDown && My_current_stage == Current_stage::Outside && monsterIsAlive)
		{
			press_e.setPosition(175, 200);
			press_e_action.loadFromFile("assets/textures/fight.png");

			render_texture.draw(press_e);
		}
		else if (My_current_stage == Current_stage::Combat)
		{
			press_e.setPosition(115.f, 380.f);
			press_e_action.loadFromFile("assets/textures/exit.png");

			render_texture.draw(press_e);

		}
		
		render_texture.display();


		window.draw(render_sprite); //Pintar el sprite con el personaje en la ventana
		window.draw(text);
		window.display();
	}
	return EXIT_SUCCESS;
}
