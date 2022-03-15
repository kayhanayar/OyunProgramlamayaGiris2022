#pragma once
#include "TemelTurler.hpp"
#include "Pencere.hpp"
#include "AracPaneli.hpp"
#include "Yilan.hpp"
class Oyun
{
public:
	Oyun();
	~Oyun();
	void setFps(int fps);
	void oyunuBaslat(unsigned int genislik=600,unsigned int yukseklik= 600);
	void cizimFonksiyonu();
	void kaplamaEkle(sf::String dosyaIsmi, bool arkaPlanOlsunmu = true);
	void oyunuAyarla();
	void arayuzleriYukle();
	void olaylariBagla();
	void fareHareket(int x, int y);
	void fareBasildi(sf::Event::MouseButtonEvent olay);
	void fareBirakma(sf::Event::MouseButtonEvent olay);
	void klavyeBasildi(sf::Keyboard::Key tus);
	void oyunuKapat();
	void yemUret();
	bool yemYendimi();

private:

	void saatiYenidenBaslat();

	KarePtr				m_yem;
	YilanPtr			m_yilan;
	sf::Time			m_gecenSure;
	sf::Time			m_cerceveSuresi;
	
	sf::Clock			m_saat;
	Pencere				m_pencere;
	KaplamaHaritasi		m_aracKaplamaListesi;
	int					m_fps;
	AracPaneliListesi	m_panelListesi;
	FontPtr				m_font;
	int					m_genislik;
	int					m_yukseklik;
	bool				m_devamEdiyormu;
};