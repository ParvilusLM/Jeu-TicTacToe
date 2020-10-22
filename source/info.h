#ifndef DEF_INFO
#define DEF_INFO

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"


class Info
{
public:
    Info(sf::RenderWindow& fenetre);
    void initInfo();
    void reinitInfo();

    void gestInfoPartie();
    void majInfo();

    void afficheInfo();

    ~Info();

private:
    sf::RenderWindow* m_fenetre;


};

#endif // DEF_INFO
