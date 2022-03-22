#include "Yazi.hpp"
#include "Pencere.hpp"
void Yazi::yaziAta(const sf::String& strYazi)
{
	m_yazi.setString(strYazi);
	m_yazi.setFont(*m_font);
	auto yaziBoyut = m_yazi.getLocalBounds();
	m_yazi.setFillColor(sf::Color::Red);
	m_boyut.x = yaziBoyut.width+yaziBoyut.left;
	m_boyut.y = yaziBoyut.height+yaziBoyut.top;
}

void Yazi::yaziBoyutuAta(int boyut)
{
	m_yazi.setCharacterSize(boyut);

}

void Yazi::fareUzerindemi(bool uzerindemi)
{
}

void Yazi::ciz(Pencere& pencere)
{
	m_yazi.setPosition(m_konum );
	pencere.ciz(m_yazi);
}
