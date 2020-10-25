#include "controleur.h"

using namespace std;

Controleur::Controleur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_decor=new Decor(*m_fenetre);
}

void Controleur::debutJeu()
{
    m_decor->getJoueur().initGrille();
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
    //gestions boutons presses pour les menus
    if(boutonPresse)
    {
        if(m_decor->getMenu().getBoutonPress()==B_INFO)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_SON)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_JOUEUR1)
        {
            m_decor->getJoueur().getGrille().nombreJ=1;
        }
        else if(m_decor->getMenu().getBoutonPress()==B_JOUEUR2)
        {
            m_decor->getJoueur().getGrille().nombreJ=2;
        }
        else if(m_decor->getMenu().getBoutonPress()==B_OK)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_MENU)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_GRILLE1)
        {
            m_decor->getJoueur().getGrille().taille=3;
            jeuDebut=true;
            std::cout<<"ahh";
        }
        else if(m_decor->getMenu().getBoutonPress()==B_GRILLE2)
        {
            m_decor->getJoueur().getGrille().taille=5;
            jeuDebut=true;
            std::cout<<"ahh2";
        }
        else if(m_decor->getMenu().getBoutonPress()==B_GRILLE3)
        {
            m_decor->getJoueur().getGrille().taille=7;
            jeuDebut=true;
            std::cout<<"ahh3";
        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSER)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSEREJ)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSEI)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSEQ)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_FINPQ)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_FINPR)
        {

        }
        else
        {

        }

        boutonPresse=false;
    }

    if(jeuDebut)
    {
        debutJeu();
        jeuDebut=false;
    }

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
    m_decor->getJoueur().afficheGrille();
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
