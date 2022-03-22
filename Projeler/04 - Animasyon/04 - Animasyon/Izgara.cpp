#include "Izgara.hpp"
#include "Pencere.hpp"
Izgara::Izgara()
{
	
}

void Izgara::ayarla(float izgaraBoyut, float aralikMesafe)
{
	this->m_mesafe = aralikMesafe;

	m_cizgiSayisi = (int)izgaraBoyut / aralikMesafe;
	
	m_yatayDorgen.setSize(sf::Vector2f(izgaraBoyut, 1));
	m_dikeyDortgen.setSize(sf::Vector2f(1, izgaraBoyut));
}
void Izgara::ciz(Pencere& pencere)
{
	sf::Vector2f siradakiKonum;
	for (int i = 0; i < m_cizgiSayisi; i++)
	{

		siradakiKonum.x = m_konum.x;
		siradakiKonum.y = m_konum.y+i*m_mesafe;
		


		m_yatayDorgen.setPosition(siradakiKonum);
		pencere.ciz(m_yatayDorgen);

		siradakiKonum.x = m_konum.x+ i * m_mesafe;
		siradakiKonum.y = m_konum.y;
		m_dikeyDortgen.setPosition(siradakiKonum);
		pencere.ciz(m_dikeyDortgen);
	}

}
