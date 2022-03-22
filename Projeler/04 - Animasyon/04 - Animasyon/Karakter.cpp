#include "Karakter.hpp"
#include<fstream>
#include "Oyun.hpp"
#include "Animasyon.hpp"
#include <iostream>
sf::RectangleShape cizgi(sf::Vector2f(1000.0f, 2.0f));
Karakter::Karakter(const std::string& fileName,
	Oyun* oyun)
{
	cizgi.setFillColor(sf::Color::Red);
	m_zipliyormu = false;
	m_yerdemi = true;
	m_surtunme = sf::Vector2f(5, 5);
	m_konum = sf::Vector2f(150, 150);
	m_yataySurtunme = sf::Vector2f(0.99f, 0.0f);
	m_maxHiz = sf::Vector2f(15.0f, 0.0f);
	m_minHiz = sf::Vector2f(0.0f, 0.0f);
	m_maxIvme = sf::Vector2f(10.0f, 0.0f);
	m_ziplamaHizi = sf::Vector2f(0.0f,-20.0f);
	m_yerCekimi = sf::Vector2f(0.0f, 5.0f);
	m_ziplamaYuksekligi = 100.0f;
	std::ifstream dosya("./modeller/" + fileName+".txt");

	if (dosya.is_open())
	{
		std::string kaplamaIsmi;
		dosya >> kaplamaIsmi;
		m_kaplama =  oyun->kaplamaEkle(kaplamaIsmi, false);

		std::string gecici;
		dosya >> gecici >> m_aktifAnimasyon;
		dosya >> gecici >> m_aktifYon;
		dosya >> gecici;

		while (!dosya.eof())
		{
			AnimasyonPtr anim = std::make_shared<Animasyon>();
			std::string isim;
			std::string yon;
			sf::Vector2i konum;
			sf::Vector2i boyut;
			int cerceveSayisi;
			dosya >> isim>>isim;
			dosya >> yon >> yon;
			dosya >> gecici >> konum.x >> konum.y;
			dosya >> gecici >> boyut.x >> boyut.y;
			dosya >> gecici >> cerceveSayisi;
			dosya >> gecici;
			anim->olustur(m_kaplama, konum, boyut,cerceveSayisi);
			m_animasyonlar[yon][isim] = anim;

		}
	}
}

void Karakter::guncelle(float gecenSure)
{
	m_hiz += m_ivme * gecenSure;	
	
	m_hiz = m_hiz / (1.0f + 0.6f * gecenSure);
	
	if (m_aktifYon == "Sag")
	{
		if (m_hiz.x > m_hedeflenenHiz.x&&m_hedeflenenHiz.x!=0)
			m_hiz.x = m_hedeflenenHiz.x;
		if (m_hiz.x < 0.0f)
			m_hiz.x = 0;
	}
	else if (m_aktifYon == "Sol")
	{
		
		if (m_hiz.x < m_hedeflenenHiz.x && m_hedeflenenHiz.x != 0)
			m_hiz.x = m_hedeflenenHiz.x;
		if (m_hiz.x > 0.0f)
			m_hiz.x = 0;
	}

	if (m_zipliyormu)
	{
		if (m_konum.y > (m_ziplamaBaslamaYuksekligi - m_ziplamaYuksekligi))
		{
			
			m_hiz.y = m_ziplamaHizi.y;
		}
		else
		{
			m_zipliyormu = false;
		}
		
	}
	m_konum += m_hiz * gecenSure;

	if (!zemindemi())
	{
		m_hiz += m_yerCekimi * gecenSure;
	}
	
	m_animasyonlar[m_aktifYon][m_aktifAnimasyon]->guncelle();
}

void Karakter::tusBasildi(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::Left)
	{
		m_hedeflenenHiz = -m_maxHiz;
		m_ivme = -m_maxIvme;
		animasyonDegistir("Yurume");
		yonDegistir("Sol");
	}
	if (tus == sf::Keyboard::Right)
	{
		m_hedeflenenHiz = m_maxHiz;
		m_ivme = m_maxIvme;
		animasyonDegistir("Yurume");
		yonDegistir("Sag");
	}
	if (tus == sf::Keyboard::Down)
	{
		m_ivme = sf::Vector2f(0.0f, 0.0f);
		m_hedeflenenHiz = m_minHiz;
		animasyonDegistir("DizCokmusSabit");
	}
	if (tus == sf::Keyboard::Up)
	{

	}if (tus == sf::Keyboard::Space)
	{
		if (zemindemi())
		{
			m_zipliyormu = true;
			m_ziplamaBaslamaYuksekligi = m_konum.y;
		}

	}
}

void Karakter::tusBirakma(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::Left)
	{
		if (m_aktifYon == "Sol" && m_aktifAnimasyon == "Yurume")
		{
			m_hedeflenenHiz = m_minHiz;
			m_ivme.x = 0;
			m_aktifAnimasyon = "AyaktaSabit";
		}
	}
	if (tus == sf::Keyboard::Right)
	{
		if (m_aktifYon == "Sag" && m_aktifAnimasyon == "Yurume")
		{
			m_ivme.x = 0;
			m_hedeflenenHiz = m_minHiz;
			m_aktifAnimasyon = "AyaktaSabit";
		}
		
	}
	if (tus == sf::Keyboard::Down)
	{
		if (m_aktifAnimasyon == "DizCokmusSabit")
			m_aktifAnimasyon = "AyaktaSabit";
	}
	if (tus == sf::Keyboard::Up)
	{

	}if (tus == sf::Keyboard::Space)
	{
		if (m_zipliyormu)
		{
			//m_ziplamaHizi.y = 0.0f;
		}
			
	}
}

void Karakter::animasyonDegistir(const std::string& yeniAnimasyon)
{
	m_aktifAnimasyon = yeniAnimasyon;
	
}

void Karakter::yonDegistir(const std::string& yeniYon)
{
	m_aktifYon = yeniYon;
}

void Karakter::ciz(Pencere& pencere)
{
	cizgi.setPosition(sf::Vector2f(0, 300));
	pencere.ciz(cizgi);
	m_animasyonlar[m_aktifYon][m_aktifAnimasyon]->m_konum = m_konum;
	m_animasyonlar[m_aktifYon][m_aktifAnimasyon]->ciz(pencere);
}

float Karakter::hedefHareket(float hedef, float anlik, float dt)
{
	float fark = hedef - anlik;

	if (fark > dt)
	{
		return anlik + dt;
	}
	if(fark<-dt)
	{ 
		return anlik - dt;
	}
	return hedef;
}

bool Karakter::zemindemi()
{
	if (m_konum.y >= 300)
	{
		m_konum.y = 300;
		
		return true;;
	}
	
	return false;
}
