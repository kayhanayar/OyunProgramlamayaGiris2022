#include "Pencere.hpp"

Pencere::Pencere()
{
	
}
void Pencere::olustur(unsigned int genislik, unsigned int yukseklik, sf::String baslik)
{
	m_pencere.create(sf::VideoMode(genislik, yukseklik), baslik);
}
void Pencere::cizimeBasla()
{
	m_pencere.clear();
}
void Pencere::cizimiBitir()
{
	m_pencere.display();
}
bool Pencere::acikmi()
{
	return m_pencere.isOpen();
}
void Pencere::olayKontrol()
{
	sf::Event olay;

	while (m_pencere.pollEvent(olay))
	{
		if (olay.type == sf::Event::Closed)
			m_pencere.close();
	}
}
void Pencere::ciz(sf::Drawable& sekil)
{
	m_pencere.draw(sekil);
}