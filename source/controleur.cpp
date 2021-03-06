#include "controleur.h"

using namespace std;

Controleur::Controleur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_decor=new Decor(*m_fenetre);
}

void Controleur::debutJeu()
{
    laMain=true;
    m_decor->getJoueur().initGrille();
}

void Controleur::pauseJeu()
{
    jeuPause=true;
    m_decor->getMenu().setTypeMenu(MenuPause);
}

void Controleur::gestionDplSouris()
{
    m_decor->getMenu().elementActif();
}

void Controleur::gestionSelecSouris()
{
    m_decor->getMenu().selectionElActif();
}

void Controleur::gestBoutonsJeu()
{
    if(m_decor->getJoueur().boutonSelect())
    {
        pauseJeu();
    }
}

void Controleur::tourJoueur()
{
    if(laMain)
    {
        if(m_decor->getJoueur().selectionCase(HUMAIN1))
        {
            m_decor->getSon().jouerSon(SON_AUTORISE);
        }
        else
        {
            m_decor->getSon().jouerSon(SON_INTERDIT);

        }

        finPartie(HUMAIN1);
    }
    else
    {
        if(m_decor->getJoueur().getGrille().nombreJ==1)
        {
            if(m_decor->getJoueur().selectionCaseIa())
            {
                m_decor->getSon().jouerSon(SON_AUTORISE);
            }

        }
        else
        {
            if(m_decor->getJoueur().selectionCase(HUMAIN2))
            {
                m_decor->getSon().jouerSon(SON_AUTORISE);
            }
            else
            {
                m_decor->getSon().jouerSon(SON_INTERDIT);
            }

        }

        finPartie(HUMAIN2);
    }



}

void Controleur::gestMaJ()
{
    //gestions boutons presses pour les menus
    if(boutonPresse)
    {
        //pour le son quand on clic sur un bouton
        if(m_decor->getMenu().getBoutonPress()!= AUCUN_EL_ACT)
        {
            m_decor->getSon().jouerSon(SON_BCLIK);
        }

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

        }
        else if(m_decor->getMenu().getBoutonPress()==B_GRILLE2)
        {
            m_decor->getJoueur().getGrille().taille=5;
            jeuDebut=true;

        }
        else if(m_decor->getMenu().getBoutonPress()==B_GRILLE3)
        {
            m_decor->getJoueur().getGrille().taille=7;
            jeuDebut=true;

        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSER)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSEREJ)
        {
            debutJeu();
        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSEI)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_PAUSEQ)
        {

        }
        else if(m_decor->getMenu().getBoutonPress()==B_FINPQ)
        {
            jeuPause=false;
            jeuEnCours=false;
            jeuDebut=false;
            jeuFinPartie=false;
            m_decor->getMenu().setTypeMenu(MenuPrincipal);
        }
        else if(m_decor->getMenu().getBoutonPress()==B_FINPR)
        {
            debutJeu();
        }
        else
        {

        }

        m_decor->getMenu().resetBoutonPress();
        boutonPresse=false;
    }

    if(jeuDebut)
    {
        std::cout<<"Boom"<<std::endl;
        debutJeu();
        jeuDebut=false;
    }

    //tour de l'IA
    if(jeuEnCours && !jeuFinPartie && !jeuPause && !laMain && m_decor->getJoueur().getGrille().nombreJ==1)
    {
        tourJoueur();
    }

    m_decor->getJoueur().gestMaj();

    if(jeuFinPartie)
    {
        jeuPause=true;
        m_decor->getMenu().setTypeMenu(MenuFinPartie);
        jeuFinPartie=false;
    }

}

void Controleur::finPartie(int joueur)
{
    //on teste si le joueur a aligner le nombre de pieces voulues
    if(joueur==HUMAIN1)
    {
        if(m_decor->getJoueur().getGrille().taille==3)
        {
            if(m_decor->getJoueur().partieGagne(joueur,3))
            {
               jeuFinPartie=true;
            }
        }
        else
        {
            if(m_decor->getJoueur().partieGagne(joueur,4))
            {
                jeuFinPartie=true;
            }
        }
    }
    else
    {
        if(m_decor->getJoueur().getGrille().taille==3)
        {
            if(m_decor->getJoueur().partieGagne(joueur,3))
            {
               jeuFinPartie=true;
            }
        }
        else
        {
            if(m_decor->getJoueur().partieGagne(joueur,4))
            {
                jeuFinPartie=true;
            }
        }
    }


    //on teste si toutes les cases sont remplies
    if(!jeuFinPartie)
    {
        bool rempli=true;

        int compt=0;
        while(compt<m_decor->getJoueur().getGrille().grille.size())
        {
            if(m_decor->getJoueur().getGrille().grille.at(compt)==VIDE)
            {
                rempli=false;
            }
            compt++;
        }

        if(rempli)
        {
            jeuFinPartie=true;
        }
    }
}

void Controleur::afficheFondEc()
{
    m_decor->afficheFondEc();
}

void Controleur::afficheJeu()
{
    m_decor->getJoueur().afficheGrille();
    m_decor->getJoueur().afficheBouton();

    if(jeuPause)
    {
        m_decor->getMenu().afficheMenu();

        if(m_decor->getMenu().getTypeMenu()!= MenuPause)
        {
            m_decor->getJoueur().afficheText();
        }

    }
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
