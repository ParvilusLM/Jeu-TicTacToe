#include "controleur.h"

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

}

void Controleur::gestionSelecSouris()
{

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

}

void Controleur::afficheInfo()
{

}

Controleur::~Controleur()
{
    delete m_decor;
}
