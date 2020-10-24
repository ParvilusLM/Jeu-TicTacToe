#include "controleur.h"

using namespace std;

Controleur::Controleur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_decor=new Decor(*m_fenetre);
}

void Controleur::debutJeu()
{

}

void Controleur::pauseJeu()
{

}

void Controleur::gestionDplSouris()
{
    m_decor->getMenu().elementActif();
}

void Controleur::gestionSelecSouris()
{
    m_decor->getMenu().selectionElActif();
}

void Controleur::gestMaJ()
{

}

void Controleur::finPartie()
{

}

void Controleur::afficheFondEc()
{
    m_decor->afficheFondEc();
}

void Controleur::afficheJeu()
{

}

void Controleur::afficheMenu()
{
    m_decor->getMenu().afficheMenu();
}

void Controleur::afficheInfo()
{

}

Controleur::~Controleur()
{
    delete m_decor;
}
