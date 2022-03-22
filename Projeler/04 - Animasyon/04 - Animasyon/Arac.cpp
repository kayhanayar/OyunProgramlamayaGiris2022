#include "Arac.hpp"

void Arac::fareHareket(int x, int y)
{
	for (auto siradaki : m_aracListesi)
	{
		if (siradaki->icerdemi(x, y))
		{
			siradaki->fareUzerindemi(true);
			siradaki->fareHareket(x, y);
		}
		else
		{
			siradaki->fareUzerindemi(false);
		}
	}
}

bool Arac::icerdemi(int x, int y)
{
	if (m_konum.x <= x &&
		m_konum.x + m_boyut.x >= x &&
		m_konum.y <= y &&
		m_konum.y + m_boyut.y >= y)
	{
		return true;
	}
	return false;
}



void Arac::konumAta(const sf::Vector2f& yenikonum)
{
	for (auto siradaki : m_aracListesi)
	{
		auto yerelKonum = siradaki->konumGetir() - m_konum;
		siradaki->konumAta(yerelKonum + yenikonum);
	}
	m_konum = yenikonum;
}



sf::Vector2f Arac::konumGetir()
{
	return m_konum;
}

sf::Vector2f Arac::boyutGetir()
{
	return m_boyut;
}

void Arac::gorunurluk(bool gorunurmu)
{
	m_gorunurmu = gorunurmu;
}

void Arac::fontAta(FontPtr font)
{
	for (auto siradaki : m_aracListesi)
	{
		siradaki->fontAta(font);
	}
	m_font = font;
}

void Arac::tiklaFonksiyonuEkle(TiklaFonksiyonu yeniFonk)
{
	m_tiklaFonksiyonlari.push_back(yeniFonk);
}

void Arac::fareButonBasildi(sf::Event::MouseButtonEvent btnOlay)
{
	int x = btnOlay.x;
	int y = btnOlay.y;

	for (auto siradaki : m_aracListesi)
	{
		if (siradaki->icerdemi(x, y))
		{
			
			siradaki->fareButonBasildi(btnOlay);
		}
	}
	for (auto siradaki : m_tiklaFonksiyonlari)
		siradaki();
}

void Arac::fareButonBirakildi(sf::Event::MouseButtonEvent btnOlay)
{
	int x = btnOlay.x;
	int y = btnOlay.y;
	for (auto siradaki : m_aracListesi)
	{
		//if (siradaki->icerdemi(x, y))
		{

			siradaki->fareButonBirakildi(btnOlay);
		}
	}
}

void Arac::boyutAta(const sf::Vector2f& boyut)
{

	m_boyut = boyut;
}
