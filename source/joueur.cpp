#include "joueur.h"


Joueur::Joueur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_tMarqueur.loadFromFile("donnees/piece.png");
    m_tGrille1.loadFromFile("donnees/grille1.png");
    m_tGrille2.loadFromFile("donnees/grille2.png");
    m_tGrille3.loadFromFile("donnees/grille3.png");

    m_tbPause.loadFromFile("donnees/bJeuEnCours.png");

    m_sbPause.setTexture(m_tbPause);
    m_sbPause.setPosition(1*20.f,1*20.f);
    m_sbPause.setTextureRect(sf::IntRect(1*20,1*20,4*20,4*20));

}

void Joueur::initGrille()
{
    //selection grille
    if(m_grille.taille==3)
    {
        m_grille.sGrille.setTexture(m_tGrille1);
    }
    else if(m_grille.taille==5)
    {
        m_grille.sGrille.setTexture(m_tGrille2);
    }
    else if(m_grille.taille==7)
    {
        m_grille.sGrille.setTexture(m_tGrille3);
    }
    else
    {

    }
}


bool Joueur::selectionCase(int joueur)
{

}

void Joueur::marquageCase(int joueur)
{

}

GrilleJeu& Joueur::getGrille()
{
    return m_grille;
}

void Joueur::gestBoutons()
{

}

void Joueur::gestMaj()
{

}

void Joueur::afficheGrille()
{
    //grille
    m_fenetre->draw(m_grille.sGrille);

    //les pieces
    int compt=0;
    while(compt<m_grille.joueurs.size())
    {
        int compt2=0;
        while(compt2<m_grille.joueurs.at(compt).pieces.size())
        {
            m_fenetre->draw( m_grille.joueurs.at(compt).pieces.at(compt2));
            compt2++;
        }
        compt++;
    }
}

void Joueur::afficheBouton()
{
    m_fenetre->draw(m_sbPause);
}

Joueur::~Joueur()
{

}
