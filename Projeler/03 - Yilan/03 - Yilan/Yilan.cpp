#include "Yilan.hpp"
#include "Pencere.hpp"

Yilan::Yilan(float hucreBoyutu)
{
	this->m_hucreBoyutu = hucreBoyutu;
	m_hiz = hucreBoyutu / 10;
	m_turSayaci = 0.0f;
	KarePtr yeniKare = Kare::kareUret(hucreBoyutu);
	yeniKare->m_hiz = m_hiz;
	m_kareler.push_back(yeniKare);
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
	m_siradakiYon = YON::YON_SAG;
}

void Yilan::ciz(Pencere& pencere)
{
	for (auto siradaki : m_kareler)
		siradaki->ciz(pencere);
}

void Yilan::yonDegistir(YON yeniYon)
{
	auto basYon = m_kareler.front()->m_yon;

	if (yeniYon == YON::YON_SAG && basYon == YON::YON_SOL)
		return;
	if (yeniYon == YON::YON_SOL && basYon == YON::YON_SAG)
		return;
	if (yeniYon == YON::YON_YUKARI && basYon == YON::YON_ASAGI)
		return;
	if (yeniYon == YON::YON_ASAGI && basYon == YON::YON_YUKARI)
		return;
	m_siradakiYon = yeniYon;
		
}

void Yilan::hareket()
{
	if (m_turSayaci == m_hucreBoyutu)
	{
		for (int i = m_kareler.size() - 1; i > 0; i--)
		{
			m_kareler[i]->m_yon = m_kareler[i - 1]->m_yon;
		}
		m_kareler.front()->m_yon = m_siradakiYon;
		m_turSayaci = 0.0f;
	}

	m_turSayaci += m_hiz;
	for (auto siradaki : m_kareler)
		siradaki->hareket();
	
}

void Yilan::kuyrugaEkle()
{
	if (m_kareler.empty())
		return;
	auto yon = m_kareler.back()->m_yon;
	auto konum = m_kareler.back()->m_konum;
	switch (yon)
	{
	case YON::YON_SOL:
		konum.x += m_hucreBoyutu;
		break;
	case YON::YON_SAG:
		konum.x -= m_hucreBoyutu;
		break;
	case YON::YON_YUKARI:
		konum.y += m_hucreBoyutu;
		break;
	case YON::YON_ASAGI:
		konum.y -= m_hucreBoyutu;
		break;
	}
	auto yeniKare = Kare::kareUret(m_hucreBoyutu);
	yeniKare->m_yon = yon;
	yeniKare->m_konum = konum;
	yeniKare->m_hiz = m_hiz;
	m_kareler.push_back(yeniKare);
}

bool Yilan::kendiniYedinmi()
{
	auto basKonum = m_kareler.front()->m_konum;

	for (int i = 1; i < m_kareler.size(); i++)
	{
		if (basKonum == m_kareler[i]->m_konum)
			return true;
	}
	return false;
}

bool Yilan::yemiYiyormusun(const sf::Vector2f& yemKonum)
{
	auto basKonum = m_kareler.front()->m_konum;

	return basKonum==yemKonum;
}
