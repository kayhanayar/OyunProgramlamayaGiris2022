#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), " SFML !");
	sf::CircleShape shape(30.f);
	sf::Clock saat;

	float x = 10;

	float artis = 1.0f;
	float cerceveSuresi = 1.0f / 60.0f;
	shape.setFillColor(sf::Color::Green);
	sf::Time gecenSure;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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
			x += artis;
			shape.setPosition(sf::Vector2f(x, 300));
			gecenSure -= sf::seconds(cerceveSuresi);
		}
		window.clear();
		window.draw(shape);
		window.display();
		gecenSure += saat.restart();
	}
	return 0;
}
