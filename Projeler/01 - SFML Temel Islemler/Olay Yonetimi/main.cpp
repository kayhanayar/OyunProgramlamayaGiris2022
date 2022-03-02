#include <SFML/Graphics.hpp>
#include<iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "ilk Program");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			
			{
				sf::FloatRect visibleArea(sf::FloatRect(sf::Vector2f(0, 0),sf::Vector2f(event.size.width, event.size.height)));
				window.setView(sf::View(visibleArea));
				std::cout << "yeni boyut:" << event.size.width << "," << event.size.height << std::endl;
			}

		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
