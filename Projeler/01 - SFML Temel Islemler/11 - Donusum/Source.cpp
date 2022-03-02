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

	yuruyen.setOrigin(sf::Vector2f(25,25));

	sf::Time cerceveSuresi = sf::seconds(1.0f / 60.0f);

	sf::Time gecenSure;
	float aci = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					yuruyen.move(sf::Vector2f(-2.0f, 0.0f));
				}
				if(event.key.code == sf::Keyboard::Right)
				{
					yuruyen.move(sf::Vector2f(2.0f, 0.0f));
				}
				if (event.key.code == sf::Keyboard::Up)
					aci++;
				if (event.key.code == sf::Keyboard::Down)
					aci--;
			}
		}
		
		gecenSure += saat.getElapsedTime();
		if (gecenSure >= cerceveSuresi)
		{
			window.clear();

			yuruyen.setRotation(sf::degrees(aci));
			window.draw(yuruyen);

			window.display();

			gecenSure -= cerceveSuresi;
		}
		else
		{
			sf::sleep(cerceveSuresi - gecenSure);
		}
		
	}
	return 0;
}
