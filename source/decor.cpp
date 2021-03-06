#include "decor.h"

using namespace std;

Decor::Decor(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_menu=new Menu(*m_fenetre);
    m_info=new Info(*m_fenetre);
    m_son=new Son(*m_fenetre);
    m_joueur=new Joueur(*m_fenetre);

    m_tFondEc.loadFromFile("donnees/fondEcG.png");
    m_sFondEc.setTexture(m_tFondEc);


}

Menu& Decor::getMenu()
{
    return *m_menu;
}

Info& Decor::getInfo()
{

}

Son& Decor::getSon()
{
    return *m_son;
}

Joueur& Decor::getJoueur()
{
    return *m_joueur;
}

void Decor::afficheFondEc()
{
    m_fenetre->draw(m_sFondEc);
}

Decor::~Decor()
{
    delete m_menu;
    delete m_info;
    delete m_son;
    delete m_joueur;
}
