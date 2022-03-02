#include "Oyun.hpp"

Oyun::Oyun()
{
	m_fps = 60;
	m_cerceveSuresi = sf::seconds(1.0f / m_fps);
}

Oyun::~Oyun()
{
}

void Oyun::setFps(int fps)
{
}

void Oyun::oyunuBaslat(unsigned int genislik, unsigned int yukseklik)
{
	m_pencere.olustur(genislik, yukseklik, "SFML");

	sf::CircleShape daire(150);

	m_saat.restart();
	while (m_pencere.acikmi())
	{
		m_pencere.olayKontrol();
		
		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{
			m_pencere.cizimeBasla();
			m_pencere.ciz(daire);
			m_pencere.cizimiBitir();
			m_saat.restart();
		}
		else
		{
			sf::sleep(m_cerceveSuresi - m_saat.getElapsedTime());
		}

	}
}

void Oyun::kaplamaEkle(sf::String dosyaIsmi)
{
	if (m_aracKaplamaListesi.count(dosyaIsmi) == 0)
	{
		TexturePtr yeniKaplama = std::make_shared<sf::Texture>();
		sf::String yol = "./resimler/"+dosyaIsmi;
		std::filesystem::path tamyol(yol);
		yeniKaplama->loadFromFile(tamyol);
	}

}



void Oyun::saatiYenidenBaslat()
{
}
