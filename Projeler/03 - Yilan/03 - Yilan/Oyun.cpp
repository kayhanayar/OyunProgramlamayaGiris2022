#include "Oyun.hpp"
#include <iostream>
#include "Izgara.hpp"
#include "Animasyon.hpp"
Izgara izgara;
Animasyon anim;
Oyun::Oyun()
{
	m_fps = 60;
	m_cerceveSuresi = sf::seconds(1.0f / m_fps);
	m_devamEdiyormu = false;
	
}

Oyun::~Oyun()
{
}

void Oyun::setFps(int fps)
{
}
void Oyun::kaplamaEkle(sf::String dosyaIsmi, bool arkaPlanOlsunmu)
{
	if (m_aracKaplamaListesi.count(dosyaIsmi) == 0)
	{
		TexturePtr yeniKaplama = std::make_shared<sf::Texture>();
		sf::String yol = "./resimler/" + dosyaIsmi;
		std::filesystem::path tamyol(yol);
		
		if (arkaPlanOlsunmu)
		{
			if (yeniKaplama->loadFromFile(tamyol))
			{
				m_aracKaplamaListesi[dosyaIsmi] = yeniKaplama;
			}
		}
		else
		{
			sf::Image image;
			if (image.loadFromFile(tamyol))
			{
				auto maskeRengi = image.getPixel(0, 0);
				image.createMaskFromColor(maskeRengi);
				yeniKaplama->loadFromImage(image);
				m_aracKaplamaListesi[dosyaIsmi] = yeniKaplama;
			}
		}

	}

}
void Oyun::oyunuAyarla()
{
	izgara.ayarla(m_genislik, 20.0f);
	m_yilan = std::make_shared < Yilan>(20.0f);
	m_yem = Kare::kareUret(20.0f);
	m_yem->m_sekil.setFillColor(sf::Color::Blue);
	

	kaplamaEkle("hero.png",false);
	
	anim.olustur(m_aracKaplamaListesi["hero.png"],
		sf::Vector2i(24,315),sf::Vector2i(50,50),8);


	yemUret();
	arayuzleriYukle();

	olaylariBagla();

}
void Oyun::arayuzleriYukle()
{
	m_font = std::make_shared<sf::Font>();
	if (!m_font->loadFromFile("./fontlar/alev.ttf"))
	{
		std::cout << "font bulunamadi" << std::endl;
	}
	kaplamaEkle("Button.png");
	kaplamaEkle("Windows.png");
	AracPaneliPtr yeniPanel = std::make_shared<AracPaneli>();
	yeniPanel->fontAta(m_font);
	yeniPanel->aracKaplamasi(m_aracKaplamaListesi["Button.png"]);
	yeniPanel->arkaPlanAta(m_aracKaplamaListesi["Windows.png"], sf::IntRect(sf::Vector2i(799, 933), sf::Vector2i(550, 742)));
	

	auto btnYeniOyun = yeniPanel->butonEkle("Yeni Oyun");
	auto btnListe = yeniPanel->butonEkle("Liste");
	auto btnCikis = yeniPanel->butonEkle("Cikis");

	btnCikis->tiklaFonksiyonuEkle([&] {
		this->oyunuKapat();
		});

	btnYeniOyun->tiklaFonksiyonuEkle([&] {
		m_panelListesi[0]->gorunurluk(false);
		m_devamEdiyormu = true;
		});

	float x = (m_genislik - yeniPanel->boyutGetir().x) / 2;
	float y = (m_yukseklik - yeniPanel->boyutGetir().y) / 2;
	yeniPanel->konumAta(sf::Vector2f(x, y));
	
	m_panelListesi.push_back(yeniPanel);
}
void Oyun::olaylariBagla()
{
	m_pencere.hareketFonksiyonuEkle(
		std::bind(&Oyun::fareHareket, this, std::placeholders::_1, std::placeholders::_2));

	m_pencere.fareBasilmaFonksiyonuEkle(
		std::bind(&Oyun::fareBasildi, this,std::placeholders::_1));
	
	m_pencere.fareBirakilmaFonksiyonuEkle(
		std::bind(&Oyun::fareBirakma, this, std::placeholders::_1));
	m_pencere.tusBasilmaFonksiyonuEkle(
		std::bind(&Oyun::klavyeBasildi, this, std::placeholders::_1));

}
void Oyun::fareHareket(int x, int y)
{
	for (auto siradaki : m_panelListesi)
	{
		if(siradaki->icerdemi(x,y))
			siradaki->fareHareket(x, y);

	}
		
	
}
void Oyun::fareBasildi(sf::Event::MouseButtonEvent olay)
{
	int x = olay.x;
	int y = olay.y;
	for (auto siradaki : m_panelListesi)
	{
		if (siradaki->icerdemi(x, y))
			siradaki->fareButonBasildi(olay);

	}
}
void Oyun::fareBirakma(sf::Event::MouseButtonEvent olay)
{
	int x = olay.x;
	int y = olay.y;
	for (auto siradaki : m_panelListesi)
	{

		siradaki->fareButonBirakildi(olay);

	}
}
void Oyun::klavyeBasildi(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::Left)
	{
		m_yilan->yonDegistir(YON::YON_SOL);
	}
	if (tus == sf::Keyboard::Right)
	{
		m_yilan->yonDegistir(YON::YON_SAG);
	}
	if (tus == sf::Keyboard::Down)
	{
		m_yilan->yonDegistir(YON::YON_ASAGI);
	}
	if (tus == sf::Keyboard::Up)
	{
		m_yilan->yonDegistir(YON::YON_YUKARI);
	}if (tus == sf::Keyboard::Space)
		m_yilan->kuyrugaEkle();
}
void Oyun::oyunuKapat()
{
	m_pencere.kapat();
}
void Oyun::yemUret()
{
	auto cizgiSayisi = izgara.m_cizgiSayisi;
	m_yem->m_konum.x = (rand() % cizgiSayisi)*m_yem->m_boyut;
	m_yem->m_konum.y = (rand() % cizgiSayisi)*m_yem->m_boyut;

}
bool Oyun::yemYendimi()
{
	return m_yilan->yemiYiyormusun(m_yem->m_konum);
}
void Oyun::oyunuBaslat(unsigned int genislik, unsigned int yukseklik)
{
	m_genislik = genislik;
	m_yukseklik = yukseklik;
	m_pencere.olustur(genislik, yukseklik, "SFML");

	oyunuAyarla();

	saatiYenidenBaslat();
	while (m_pencere.acikmi())
	{
		m_pencere.olayKontrol();
		
		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{
			cizimFonksiyonu();
			saatiYenidenBaslat();
		}
		else
		{
			sf::sleep(m_cerceveSuresi - m_saat.getElapsedTime());
		}

	}
}

void Oyun::cizimFonksiyonu()
{
	m_pencere.cizimeBasla();
	

	for (auto siradaki : m_panelListesi)
	{
		siradaki->ciz(m_pencere);
	}

	if (m_devamEdiyormu)
	{

		if (m_yilan->kendiniYedinmi())
			m_devamEdiyormu = false;
		if (yemYendimi())
		{
			m_yilan->kuyrugaEkle();
			yemUret();
		}

		m_yilan->hareket();
		izgara.ciz(m_pencere);
		m_yem->ciz(m_pencere);
		m_yilan->ciz(m_pencere);
		anim.guncelle();
		anim.ciz(m_pencere);
	}

	m_pencere.cizimiBitir();
}



void Oyun::saatiYenidenBaslat()
{
	m_saat.restart();
}
