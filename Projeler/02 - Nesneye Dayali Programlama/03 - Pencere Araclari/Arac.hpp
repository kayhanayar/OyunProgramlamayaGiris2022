#pragma once

#pragma once
#include<SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "TemelTurler.hpp"
class Pencere;
class Arac
{
public:

	typedef std::shared_ptr<Arac> AracPtr;
	typedef std::vector<AracPtr> AracListesi;

	virtual void fareHareket(int x, int y);

	virtual bool icerdemi(int x, int y);

	virtual void boyutAta(const sf::Vector2f& boyut);
	virtual void konumAta(const sf::Vector2f& konum);
	
	sf::Vector2f konumGetir();
	sf::Vector2f boyutGetir();
	
	void		fontAta(FontPtr font);

	virtual void fareButonBasildi(sf::Event::MouseButtonEvent btnOlay) ;
	virtual void fareButonBirakildi(sf::Event::MouseButtonEvent btnOlay) ;
	virtual void fareUzerindemi(bool uzerindemi) = 0;
	virtual void ciz(Pencere& pencere) = 0;
protected:
	sf::Vector2f	m_konum;
	
	FontPtr			m_font;
	sf::Vector2f	m_boyut;
	AracListesi		m_aracListesi;
	Tikla
};
