#include "Kare.hpp"
#include "Pencere.hpp"
Kare::Kare(float boyut)
{
	this->m_boyut = boyut;
	m_sekil.setSize(sf::Vector2f(boyut, boyut));
	m_yon = YON::YON_SAG;
	m_hiz = boyut/10;
	m_sekil.setOutlineThickness(2);
	m_sekil.setOutlineColor(sf::Color::Red);
	m_sekil.setFillColor(sf::Color::Green);
}

KarePtr Kare::kareUret(float boyut)
{
	return std::make_shared<Kare>(boyut);

}

void Kare::hareket()
{
	switch (m_yon)
	{
	case YON::YON_SOL:
		m_konum.x -= m_hiz;
		break;
	case YON::YON_SAG:
		m_konum.x += m_hiz;
		break;
	case YON::YON_YUKARI:
		m_konum.y -= m_hiz;
		break;
	case YON::YON_ASAGI:
		m_konum.y += m_hiz;
		break;
	}
}

void Kare::ciz(Pencere& pencere)
{
	m_sekil.setPosition(m_konum);

	pencere.ciz(m_sekil);
}
