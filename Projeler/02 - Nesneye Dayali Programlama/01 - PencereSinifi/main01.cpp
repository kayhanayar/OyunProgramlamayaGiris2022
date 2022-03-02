#include "Pencere.hpp"

int main()
{
	Pencere pencere;

	pencere.olustur(600, 600, "Pencere Sinifi");
	sf::CircleShape daire(150);

	while (pencere.acikmi())
	{
		pencere.olayKontrol();
		pencere.cizimeBasla();
		pencere.ciz(daire);
		pencere.cizimiBitir();
	}
}