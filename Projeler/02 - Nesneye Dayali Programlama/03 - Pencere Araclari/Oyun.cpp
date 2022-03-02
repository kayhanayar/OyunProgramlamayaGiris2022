#include "Oyun.hpp"
#include <iostream>
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
void Oyun::kaplamaEkle(sf::String dosyaIsmi)
{
	if (m_aracKaplamaListesi.count(dosyaIsmi) == 0)
	{
		TexturePtr yeniKaplama = std::make_shared<sf::Texture>();
		sf::String yol = "./resimler/" + dosyaIsmi;
		std::filesystem::path tamyol(yol);
		if (yeniKaplama->loadFromFile(tamyol))
		{
			m_aracKaplamaListesi[dosyaIsmi] = yeniKaplama;
		}
	}

}
void Oyun::oyunuAyarla()
{
	arayuzleriYukle();

	olaylariBagla();

}
void Oyun::arayuzleriYukle()
{
	m_font = std::make_shared<sf::Font>();
	if (!m_font->loadFromFile("./fontlar/alev.ttf"))
	{
		std::cout << "font bulunamadi" << std::endl;
	}
	kaplamaEkle("Button.png");
	kaplamaEkle("Windows.png");

	AracPaneliPtr yeniPanel = std::make_shared<AracPaneli>();
	yeniPanel->fontAta(m_font);
	yeniPanel->aracKaplamasi(m_aracKaplamaListesi["Button.png"]);
	yeniPanel->arkaPlanAta(m_aracKaplamaListesi["Windows.png"], sf::IntRect(sf::Vector2i(799, 933), sf::Vector2i(550, 742)));
	

	yeniPanel->butonEkle("Merhaba");
	yeniPanel->butonEkle("hohoho");
	yeniPanel->butonEkle("hohoho");
	float x = (m_genislik - yeniPanel->boyutGetir().x) / 2;
	float y = (m_yukseklik - yeniPanel->boyutGetir().y) / 2;
	yeniPanel->konumAta(sf::Vector2f(x, y));
	
	m_panelListesi.push_back(yeniPanel);
}
void Oyun::olaylariBagla()
{
	m_pencere.hareketFonksiyonuEkle(
		std::bind(&Oyun::fareHareket, this, std::placeholders::_1, std::placeholders::_2));

	m_pencere.fareBasilmaFonksiyonuEkle(
		std::bind(&Oyun::fareBasildi, this,std::placeholders::_1));
	
	m_pencere.fareBirakilmaFonksiyonuEkle(
		std::bind(&Oyun::fareBirakma, this, std::placeholders::_1));
}
void Oyun::fareHareket(int x, int y)
{
	for (auto siradaki : m_panelListesi)
	{
		if(siradaki->icerdemi(x,y))
			siradaki->fareHareket(x, y);

	}
		
	
}
void Oyun::fareBasildi(sf::Event::MouseButtonEvent olay)
{
	int x = olay.x;
	int y = olay.y;
	for (auto siradaki : m_panelListesi)
	{
		if (siradaki->icerdemi(x, y))
			siradaki->fareButonBasildi(olay);

	}
}
void Oyun::fareBirakma(sf::Event::MouseButtonEvent olay)
{
	int x = olay.x;
	int y = olay.y;
	for (auto siradaki : m_panelListesi)
	{

		siradaki->fareButonBirakildi(olay);

	}
}
void Oyun::oyunuBaslat(unsigned int genislik, unsigned int yukseklik)
{
	m_genislik = genislik;
	m_yukseklik = yukseklik;
	m_pencere.olustur(genislik, yukseklik, "SFML");

	oyunuAyarla();

	saatiYenidenBaslat();
	while (m_pencere.acikmi())
	{
		m_pencere.olayKontrol();
		
		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{
			cizimFonksiyonu();
			saatiYenidenBaslat();
		}
		else
		{
			sf::sleep(m_cerceveSuresi - m_saat.getElapsedTime());
		}

	}
}

void Oyun::cizimFonksiyonu()
{
	m_pencere.cizimeBasla();


	for (auto siradaki : m_panelListesi)
	{
		siradaki->ciz(m_pencere);
	}
	m_pencere.cizimiBitir();
}



void Oyun::saatiYenidenBaslat()
{
	m_saat.restart();
}
