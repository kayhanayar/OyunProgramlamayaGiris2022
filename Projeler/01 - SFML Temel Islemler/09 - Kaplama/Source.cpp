#include <SFML/Graphics.hpp>
#include <Windows.h>
#include<vector>
int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), " SFML !");

	sf::Texture kaplama;
	if (!kaplama.loadFromFile("./resimler/hero.png"))
	{
		// error...
	}
	sf::Sprite yuruyen;
	yuruyen.setTexture(kaplama);
	yuruyen.setTextureRect(sf::IntRect(sf::Vector2i(24, 315), sf::Vector2i(50, 50)));
	sf::Clock saat;
	
	

	
	float x = 10;
	
	sf::Time cerceveSuresi = sf::seconds(1.0f / 60.0f);

	sf::Time gecenSure;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (gecenSure >= cerceveSuresi)
		{
			x += 1;
			
			gecenSure -= cerceveSuresi;
		}
		else
		{
			sf::sleep(cerceveSuresi - gecenSure);
		}

		window.clear();
		for (int i = 0; i < 10; i++)
		{
			
			yuruyen.setPosition(sf::Vector2f(x, 300));
			window.draw(yuruyen);
		}
		window.display();

		gecenSure += saat.restart();
	}
	return 0;
}
