#include <SFML/Graphics.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), " SFML!");
	sf::CircleShape shape(30.f);

	sf::Clock saat;

	float x = 10;
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

		shape.setPosition(sf::Vector2f(x, 300));
		window.clear();
		window.draw(shape);
		window.display();

		gecenSure = saat.restart();
		x += 100 * gecenSure.asSeconds();
	}
	return 0;
}
