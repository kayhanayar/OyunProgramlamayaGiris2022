#pragma once
#include<SFML/Graphics.hpp>
class Pencere;

class Cizilebilir
{
public:
	virtual void ciz(Pencere& pencere) = 0;

	sf::Vector2f m_konum;
};
