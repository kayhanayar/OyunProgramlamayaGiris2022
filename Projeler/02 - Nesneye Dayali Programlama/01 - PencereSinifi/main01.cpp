#include "Pencere.hpp"
#include<iostream>

int main()
{
	Pencere pencere;

	pencere.olustur(600, 600, "Pencere Sinifi");
	sf::CircleShape daire(150);
	int maina = 5;
	pencere.klavyeFonksiyonu([=,&maina]  (sf::Keyboard::Key tus) noexcept {
		maina = 10;
		
		if (tus == sf::Keyboard::A)
		{
			std::cout << "A ya basildi" << std::endl;
			return 123;
		}
		return 123;
	});

	while (pencere.acikmi())
	{
		pencere.olayKontrol();
		pencere.cizimeBasla();
		pencere.ciz(daire);
		pencere.cizimiBitir();
		std::cout << maina << std::endl;
		
	}
}