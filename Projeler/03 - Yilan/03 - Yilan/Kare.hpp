#pragma once
#include "Cizilebilir.hpp"
#include "TemelTurler.hpp"
class Kare :public Cizilebilir
{
public:
	Kare(float boyut);
	static std::shared_ptr<Kare> kareUret(float boyut);
	void hareket();
	virtual void ciz(Pencere& pencere) override;


	float m_boyut;
	float m_hiz;
	YON	m_yon;
	sf::RectangleShape m_sekil;




};
typedef std::shared_ptr<Kare>	KarePtr;
typedef std::vector<KarePtr>	KareListesi;