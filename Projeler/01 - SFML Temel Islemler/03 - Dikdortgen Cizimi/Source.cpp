#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), " SFML!");
	sf::CircleShape daire(30.f);

	sf::RectangleShape dortgen({ 50,30 });

	float x = 10;
	daire.setFillColor(sf::Color::Green);

	daire.setOutlineColor(sf::Color(250, 150, 100));
	daire.setOutlineThickness(8);
	dortgen.setFillColor(sf::Color::Red);
	dortgen.setOutlineThickness(10.0f);
	dortgen.setOutlineColor(sf::Color(250, 150, 100));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		daire.setPosition(sf::Vector2f(x, 300));

		dortgen.setPosition(sf::Vector2f(300, x));

		window.clear();
		window.draw(daire);

		window.draw(dortgen);

		window.display();

		x += 1;
	}
	return 0;
}

