#include "Animasyon.hpp"
#include "Pencere.hpp"
Animasyon::Animasyon()
{
	m_aktifSprite = 0;
	m_sayac = 0;
}

void Animasyon::olustur(TexturePtr kaplama, const sf::Vector2i& konum, const sf::Vector2i& boyut, int cerceveSayisi)
{
	sf::Vector2i sonKonum = konum;
	for (int i = 0; i < cerceveSayisi; i++)
	{
		sf::Sprite sprite;

		sprite.setTexture(*kaplama);
		sprite.setTextureRect(sf::IntRect(sonKonum, boyut));
		m_spriteListesi.push_back(sprite);
		sonKonum.x += boyut.x + 1;
	}


}

void Animasyon::guncelle()
{
	if (m_sayac == 5)
	{
		m_aktifSprite = (m_aktifSprite + 1) % m_spriteListesi.size();
		m_sayac = 0;
	}
	m_sayac++;
	
}

void Animasyon::ciz(Pencere& pencere)
{
	m_spriteListesi[m_aktifSprite].setPosition(m_konum);
	pencere.ciz(m_spriteListesi[m_aktifSprite]);
}
