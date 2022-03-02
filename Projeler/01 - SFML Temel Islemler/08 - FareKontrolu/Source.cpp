#include <SFML/Graphics.hpp>
#include<iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), " SFML !");
	sf::CircleShape shape(30.f);
	sf::Clock saat;
	sf::Vector2f pos(10,300);


	float artis = 1.0f;
	float cerceveSuresi = 1.0f / 60.0f;
	shape.setFillColor(sf::Color::Green);
	sf::Time gecenSure;
	while (window.isOpen())
	{
		sf::Event event;
		auto position = sf::Mouse::getPosition();
		auto yerelPosition = sf::Mouse::getPosition(window);

		std::cout << "mouse (x,y):" << yerelPosition.x << "," << yerelPosition.y << std::endl;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			pos = (sf::Vector2f(yerelPosition.x, yerelPosition.y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			artis = 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			artis = -1.0f;
		}
		if (gecenSure.asSeconds() >= cerceveSuresi)
		{
			pos.x += artis;
			shape.setPosition(sf::Vector2f(pos));
			gecenSure -= sf::seconds(cerceveSuresi);
		}
		window.clear();
		window.draw(shape);
		window.display();
		gecenSure += saat.restart();
	}
	return 0;
}
