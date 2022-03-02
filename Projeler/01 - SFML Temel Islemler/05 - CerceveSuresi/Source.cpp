#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML!");

	sf::CircleShape shape(30.f);
	sf::Clock saat;
	float x = 10;

	shape.setFillColor(sf::Color::Green);

	sf::Time gecenSure;
	int fpsSayisi = 0;
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

		float turSuresi = saat.restart().asSeconds();
		int fps = (1 / turSuresi);
		window.setTitle(std::to_string(fps));

		gecenSure += sf::seconds(turSuresi);
		if (gecenSure.asSeconds() > 1.0f)
		{
			std::cout << "fps:" << fpsSayisi << std::endl;
			fpsSayisi = 0;
			gecenSure = gecenSure.Zero;
		}
		fpsSayisi++;
		x += 100 * turSuresi;
	}
	return 0;
}
