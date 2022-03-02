#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include<functional>
typedef std::shared_ptr<sf::Texture> TexturePtr;
typedef std::map<sf::String, TexturePtr> KaplamaHaritasi;
typedef std::shared_ptr<sf::Font>	FontPtr;
typedef std::function<void(int, int)> FareHareketFonksiyonu;
typedef std::function<void(sf::Event::MouseButtonEvent)>	FareButonFonksiyonu;



typedef std::vector<FareHareketFonksiyonu> FareHareketFonkListesi;
typedef std::vector<FareButonFonksiyonu> FareButonFonkListesi;