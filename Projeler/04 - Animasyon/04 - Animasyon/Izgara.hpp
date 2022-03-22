#pragma once

#include "Cizilebilir.hpp"
#include<SFML/Graphics.hpp>
class Izgara :public Cizilebilir
{
public:
	Izgara();

	void ayarla(float izgaraBoyut, float aralikMesafe);


	// Inherited via Cizilebilir
	virtual void ciz(Pencere& pencere) override;



	sf::RectangleShape m_yatayDorgen;
	sf::RectangleShape m_dikeyDortgen;
	int		m_cizgiSayisi;
	float	m_mesafe;
};
