#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include<functional>
typedef std::shared_ptr<sf::Texture> TexturePtr;
typedef std::map<sf::String, TexturePtr> KaplamaHaritasi;
typedef std::shared_ptr<sf::Font>	FontPtr;

typedef std::function<void(int, int)> FareHareketFonksiyonu;
typedef std::function<void(sf::Event::MouseButtonEvent)>	FareButonFonksiyonu;
typedef std::function<void()>	TiklaFonksiyonu;
typedef std::function<void(sf::Keyboard::Key)>	KlavyeFonksiyonu;

typedef std::vector<FareHareketFonksiyonu> FareHareketFonkListesi;
typedef std::vector<FareButonFonksiyonu> FareButonFonkListesi;
typedef std::vector<TiklaFonksiyonu>	TiklaFonksiyonuListesi;
typedef std::vector<KlavyeFonksiyonu>	KlavyeFonksiyonListesi;
enum class YON
{
	YON_SOL,
	YON_SAG,
	YON_YUKARI,
	YON_ASAGI
};

