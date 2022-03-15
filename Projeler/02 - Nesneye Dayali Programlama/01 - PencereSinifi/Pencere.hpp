#pragma once
#include<sfml/Graphics.hpp>
#include<functional>
class Pencere
{
public:
	Pencere();
	void olustur(	unsigned int genislik,
					unsigned int yukseklik,
					sf::String baslik);
	void cizimeBasla();
	void cizimiBitir();
	bool acikmi();
	void olayKontrol();
	void ciz(sf::Drawable& sekil);
	void klavyeFonksiyonu(std::function<void(sf::Keyboard::Key)> yeniFonk);
private:
	std::function<void(sf::Keyboard::Key)> m_KlavyeBasma;
	sf::RenderWindow m_pencere;
};
