#include "Buton.hpp"
#include "Pencere.hpp"
#include <iostream>
Buton::Buton()
{
    m_aktifDurum = &m_Normal;
    m_konum = sf::Vector2f(0, 0);
    m_yazi = std::make_shared<Yazi>();
    m_yazi->yaziBoyutuAta(20);
    m_aracListesi.push_back(m_yazi);
    
}

void Buton::yazi(const sf::String& yeniYazi)
{
    m_yazi->fontAta(m_font);
    m_yazi->yaziAta(yeniYazi);

}

void Buton::fareButonBasildi(sf::Event::MouseButtonEvent btnOlay)
{
    m_aktifDurum = &m_FareBasili;
    Arac::fareButonBasildi(btnOlay);
}

void Buton::fareButonBirakildi(sf::Event::MouseButtonEvent btnOlay)
{
    if (this->icerdemi(btnOlay.x, btnOlay.y))
        m_aktifDurum = &m_FareUzerinde;
    else
        m_aktifDurum = &m_Normal;
}

void Buton::ciz(Pencere& pencere)
{
    m_aktifDurum->setPosition(m_konum);
    pencere.ciz(*m_aktifDurum);
    for (auto siradaki : m_aracListesi)
    {
        siradaki->ciz(pencere);
    }

}

void Buton::fareUzerindemi(bool uzerindemi)
{
    if (m_aktifDurum == (&m_FareBasili))
        return;
    if (uzerindemi)
    {
        m_aktifDurum = &m_FareUzerinde;
    }
    else
    {
        m_aktifDurum = &m_Normal;
    }
}

void Buton::boyutAta(const sf::Vector2f& boyut)
{
    m_boyut = boyut;
    float texHeight = m_FareBasili.getTextureRect().height;
    float texWidth =  m_FareBasili.getTextureRect().width;

    float olcekX = boyut.x / texWidth;
    float olcekY = boyut.y / texHeight;

    m_FareBasili.scale(sf::Vector2f(olcekX, olcekY));
    m_FareUzerinde.scale(sf::Vector2f(olcekX, olcekY));
    m_Normal.scale(sf::Vector2f(olcekX, olcekY));

    auto yaziBoyut = m_yazi->boyutGetir();
    float x = (m_boyut.x - yaziBoyut.x) / 2;
    float y = (m_boyut.y - yaziBoyut.y) / 2;
    m_yazi->konumAta(sf::Vector2f(x, y));
}
