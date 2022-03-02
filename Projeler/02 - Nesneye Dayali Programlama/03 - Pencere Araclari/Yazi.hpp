#pragma once
#include "Arac.hpp"

class Yazi:public Arac
{
public:

	void yaziAta(const sf::String& strYazi);
	void yaziBoyutuAta(int boyut);
	// Inherited via Arac
	virtual void fareUzerindemi(bool uzerindemi) override;

	virtual void ciz(Pencere& pencere) override;

private:
	sf::Text m_yazi;
};

typedef std::shared_ptr<Yazi> YaziPtr;