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

		if (olay.type == sf::Event::MouseMoved)
		{
			for (auto siradaki : m_fareHareketFonkListesi)
				siradaki(olay.mouseMove.x, olay.mouseMove.y);
		}
		if (olay.type == sf::Event::MouseButtonPressed)
		{
			for (auto siradaki : m_fareBasilmaFonkListesi)
				siradaki(olay.mouseButton);
		}
		if (olay.type == sf::Event::MouseButtonReleased)
		{
			for (auto siradaki : m_fareBirakmaFonkListesi)
				siradaki(olay.mouseButton);
		}
	}
}
void Pencere::ciz(sf::Drawable& sekil)
{
	m_pencere.draw(sekil);
}

void Pencere::hareketFonksiyonuEkle(FareHareketFonksiyonu yeniFonksiyon)
{
	m_fareHareketFonkListesi.push_back(yeniFonksiyon);
}

void Pencere::fareBasilmaFonksiyonuEkle(FareButonFonksiyonu yeniFonksiyon)
{
	m_fareBasilmaFonkListesi.push_back(yeniFonksiyon);
}

void Pencere::fareBirakilmaFonksiyonuEkle(FareButonFonksiyonu yeniFonksiyon)
{
	m_fareBirakmaFonkListesi.push_back(yeniFonksiyon);
}
