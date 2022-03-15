#include "AracPaneli.hpp"
#include "Pencere.hpp"
#include<iostream>
AracPaneli::AracPaneli()
{
	
	m_konum = sf::Vector2f(0, 0);
	m_boyut = sf::Vector2f(40, 40);
}



void AracPaneli::aracKaplamasi(TexturePtr kaplama)
{
	m_aracKaplama = kaplama;

}

void AracPaneli::arkaPlanAta(TexturePtr kaplama, sf::IntRect rect)
{
	m_arkaPlan.setTexture(*kaplama);
	m_arkaPlan.setTextureRect(rect);
	m_arkaPlan.scale(sf::Vector2f(0.5, 0.5));
	m_boyut.x = m_arkaPlan.getGlobalBounds().width;
	m_boyut.y = m_arkaPlan.getGlobalBounds().height;
}

ButonPtr AracPaneli::butonEkle(sf::String yazi, float genislik , float yukseklik )
{
	ButonPtr yeniButon = std::make_shared<Buton>();
	yeniButon->fontAta(m_font);
	yeniButon->yazi(yazi);
	yeniButon->m_Normal.setTexture(*m_aracKaplama);
	yeniButon->m_FareUzerinde.setTexture(*m_aracKaplama);
	yeniButon->m_FareBasili.setTexture(*m_aracKaplama);
	yeniButon->m_kilitli.setTexture(*m_aracKaplama);

	yeniButon->m_Normal.setTextureRect(sf::IntRect(sf::Vector2i(177, 201), sf::Vector2i(362, 177)));
	
	yeniButon->m_FareUzerinde.setTextureRect(sf::IntRect(sf::Vector2i(561, 201), sf::Vector2i(362, 177)));
	
	yeniButon->m_FareBasili.setTextureRect(sf::IntRect(sf::Vector2i(945, 201), sf::Vector2i(362, 177)));

	yeniButon->m_kilitli.setTextureRect(sf::IntRect(sf::Vector2i(1332, 201), sf::Vector2i(362, 177)));
	

	yeniButon->boyutAta(sf::Vector2f(genislik, yukseklik));
	
	float butonX = (m_boyut.x - genislik) / 2;

	m_aracListesi.push_back(yeniButon);

	int toplamAracSayisi = m_aracListesi.size();
	
	float baslangicY = (m_boyut.y - yukseklik *toplamAracSayisi-20*(toplamAracSayisi-1)) / 2;
	
	
	
	for (int i=0;i<toplamAracSayisi;i++)
	{
		float butonY = baslangicY + yukseklik*i  + 20*i;
		m_aracListesi[i]->konumAta(sf::Vector2f(butonX, butonY));
	}
	

	return yeniButon;
}




void AracPaneli::fareUzerindemi(bool uzerindemi)
{

}


void AracPaneli::ciz(Pencere& pencere)
{
	if (!m_gorunurmu)
		return;
	m_arkaPlan.setPosition(m_konum );
	pencere.ciz(m_arkaPlan);
	for (auto siradaki : m_aracListesi)
	{
		
		siradaki->ciz(pencere);
	}
}
