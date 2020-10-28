#ifndef DEF_SON
#define DEF_SON

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"


class Son
{
public:
    Son(sf::RenderWindow& fenetre);
    void jouerSon(int type);

    ~Son();

private:
    sf::Sound m_sonBClic, m_sonAutorise,m_sonInterdit;

    sf::SoundBuffer m_bufBClic,m_bufAutorise,m_bufInterdit;



};

#endif // DEF_SON
