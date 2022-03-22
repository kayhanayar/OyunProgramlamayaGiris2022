#pragma once
#include "Cizilebilir.hpp"
#include "TemelTurler.hpp"
class Animasyon :public Cizilebilir
{
public:
	Animasyon();
	void olustur(TexturePtr kaplama,
		const sf::Vector2i& konum,
		const sf::Vector2i& boyut,
		int cerceveSayisi);
	void guncelle();

	std::vector<sf::Sprite> m_spriteListesi;
	int		m_aktifSprite;
	int		m_degisimSuresi;
	int		m_sayac;
	// Inherited via Cizilebilir
	virtual void ciz(Pencere& pencere) override;
};
typedef std::shared_ptr<Animasyon> AnimasyonPtr;
typedef std::map<std::string, AnimasyonPtr> AnimasyonHaritasi;
typedef std::map<std::string, AnimasyonHaritasi> YonluAnimasyonHaritasi;