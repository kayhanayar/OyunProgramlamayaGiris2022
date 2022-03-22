#pragma once
#include "Cizilebilir.hpp"
#include "Animasyon.hpp"
#include "TemelTurler.hpp"
#include <string>
class Oyun;
class Karakter :public Cizilebilir
{
public:
	Karakter(const std::string& fileName,
		Oyun* oyun);
	void guncelle(float gecenSure);
	void tusBasildi(sf::Keyboard::Key tus);
	void tusBirakma(sf::Keyboard::Key tus);
	void animasyonDegistir(const std::string& yeniAnimasyon);
	void yonDegistir(const std::string& yeniYon);
	virtual void ciz(Pencere& pencere) override;
	float hedefHareket(float hedef, float anlik, float dt);

	bool zemindemi();
private:
	bool					m_zipliyormu;
	bool					m_yerdemi;
	sf::Vector2f			m_yataySurtunme;
	sf::Vector2f			m_hiz;

	sf::Vector2f			m_hedeflenenHiz;
	sf::Vector2f			m_maxHiz;
	sf::Vector2f			m_minHiz;
	sf::Vector2f			m_maxIvme;
	sf::Vector2f			m_ziplamaHizi;
	sf::Vector2f			m_yerCekimi;
	sf::Vector2f			m_ivme;
	sf::Vector2f			m_surtunme;
	float					m_ziplamaYuksekligi;
	float					m_ziplamaBaslamaYuksekligi;
	std::string				m_aktifAnimasyon;
	std::string				m_aktifYon;
	TexturePtr				m_kaplama;
	YonluAnimasyonHaritasi	m_animasyonlar;

	// Inherited via Cizilebilir
	
};
typedef std::shared_ptr<Karakter>	KarakterPtr;