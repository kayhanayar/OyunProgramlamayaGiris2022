#pragma once
#include "Kare.hpp"
class Yilan :public Cizilebilir
{
public:
	Yilan(float hucreBoyutu);
	// Inherited via Cizilebilir
	virtual void ciz(Pencere& pencere) override;
	void yonDegistir(YON yeniYon);
	void hareket();
	void kuyrugaEkle();
	bool kendiniYedinmi();
	bool yemiYiyormusun(const sf::Vector2f& yemKonum);

	KareListesi	m_kareler;
	float		m_hucreBoyutu;
	float		m_hiz;
	float		m_turSayaci;
	YON			m_siradakiYon;
};

typedef std::shared_ptr<Yilan> YilanPtr;
