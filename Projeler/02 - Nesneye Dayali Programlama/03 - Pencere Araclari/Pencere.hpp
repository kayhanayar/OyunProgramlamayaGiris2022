#pragma once
#include<sfml/Graphics.hpp>
#include "TemelTurler.hpp"
class Pencere
{
public:
	Pencere();
	void olustur(	unsigned int genislik,
					unsigned int yukseklik,
					sf::String baslik);
	void cizimeBasla();
	void cizimiBitir();
	bool acikmi();
	void olayKontrol();
	void ciz(sf::Drawable& sekil);
	void hareketFonksiyonuEkle(FareHareketFonksiyonu yeniFonksiyon);
	void fareBasilmaFonksiyonuEkle(FareButonFonksiyonu yeniFonksiyon);
	void fareBirakilmaFonksiyonuEkle(FareButonFonksiyonu yeniFonksiyon);
private:
	FareHareketFonkListesi	m_fareHareketFonkListesi;
	FareButonFonkListesi	m_fareBasilmaFonkListesi;
	FareButonFonkListesi	m_fareBirakmaFonkListesi;
	sf::RenderWindow m_pencere;
};

