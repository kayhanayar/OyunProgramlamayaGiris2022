#pragma once
#include "TemelTurler.hpp"
#include "Arac.hpp"
#include "Buton.hpp"
#include<vector>
class AracPaneli:public Arac
{
public:
	AracPaneli();
	
	void aracKaplamasi(TexturePtr kaplama);
	void arkaPlanAta(TexturePtr kaplama, sf::IntRect rect);
	ButonPtr butonEkle(sf::String yazi,float genislik=150,float yukseklik=75);

	virtual void ciz(Pencere& pencere) override;
	

private:
	sf::Sprite	m_arkaPlan;
	TexturePtr	m_aracKaplama;
	int			m_yukseklik;
	int			m_genislik;

	// Inherited via Arac
	virtual void fareUzerindemi(bool uzerindemi) override;
};

typedef std::shared_ptr<AracPaneli> AracPaneliPtr;
typedef std::vector<AracPaneliPtr> AracPaneliListesi;