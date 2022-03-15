#pragma once
#include "Arac.hpp"
#include "Yazi.hpp"
class AracPaneli;

class Buton : public Arac
{


public:
	Buton();
	void yazi(const sf::String& yeniYazi);
private:

	sf::Sprite* m_aktifDurum;

	sf::Sprite m_Normal;
	sf::Sprite m_FareUzerinde;
	sf::Sprite m_FareBasili;
	sf::Sprite m_kilitli;

	YaziPtr	m_yazi;

	

	virtual void fareButonBasildi(sf::Event::MouseButtonEvent btnOlay) override;

	virtual void fareButonBirakildi(sf::Event::MouseButtonEvent btnOlay) override;

	virtual void ciz(Pencere& pencere) override;

	virtual void fareUzerindemi(bool uzerindemi) override;

	virtual void boyutAta(const sf::Vector2f& boyut)override;
	friend class AracPaneli;

};

typedef std::shared_ptr<Buton> ButonPtr;