#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Pencere.hpp"

typedef std::shared_ptr<sf::Texture> TexturePtr;
class Oyun
{
public:
	Oyun();
	~Oyun();
	void setFps(int fps);
	void oyunuBaslat(unsigned int genislik=640,unsigned int yukseklik=480);
	void kaplamaEkle(sf::String dosyaIsmi);
private:

	void saatiYenidenBaslat();
	sf::Time	m_gecenSure;
	sf::Time	m_cerceveSuresi;
	sf::Clock	m_saat;

	std::map<sf::String, TexturePtr>	m_aracKaplamaListesi;

	Pencere		m_pencere;
	
	int			m_fps;
};