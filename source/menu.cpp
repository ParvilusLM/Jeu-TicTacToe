#include "menu.h"


Menu::Menu(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    //textures pour les boutons
    m_tSelectMP.loadFromFile("donnees/bMenuP.png");
    m_tSelectInstr.loadFromFile("donnees/bInstructions.png");
    m_tSelectTypeJ.loadFromFile("donnees/bSelectTypeJ.png");
    m_tSelectMPause.loadFromFile("donnees/bMenuPause.png");
    m_tSelectMGO.loadFromFile("donnees/bFinPartie.png");

    //sprites pour les boutons
    m_sbInfo.setTexture(m_tSelectMP);
    m_sbInfo.setPosition();

    m_sbSon.setTexture(m_tSelectMP);
    m_sbSon.setPostion();

    m_sbJoueur1.setTexture(m_tSelectMP);
    m_sbJoueur1.setPosition();

    m_sbJoueur2.setTexture(m_tSelectMP);
    m_sbJoueur2.setPosition();


    m_sbMenu.setTexture(m_tSelectTypeJ);
    m_sbMenu.setPosition();

    m_sbGrille1.setTexture(m_tSelectTypeJ);
    m_sbGrille1.setPosition();

    m_sbGrille2.setTexture(m_tSelectTypeJ);
    m_sbGrille2.setPosition();

    m_sbGrille3.setTexture(m_tSelectTypeJ);
    m_sbGrille3.setPosition();

    m_sbOk.setTexture(m_tSelectInstr);
    m_sbOk.setPosition();

    m_sbResume.setTexture(m_tSelectMPause);
    m_sbResume.setPosition();

    m_sbRejouer.setTexture(m_tSelectMPause);
    m_sbRejouer.setPosition();

    m_sbInstructions.setTexture(m_tSelectMPause);
    m_sbInstructions.setPosition();

    m_sbQuitter.setTexture(m_tSelectMPause);
    m_sbQuitter.setPosition();

    m_sbMenuFP.setTexture(m_tSelectMGO);
    m_sbMenuFP.setPosition();

    m_sbRejouerFP.setTexture(m_tSelectMGO);
    m_sbRejouerFP.setPosition();



    //textures pour les differents menus
    m_tMenuP.loadFromFile("donnees/menuP.png");
    m_tMenuI.loadFromFile("donnees/instructions.png");
    m_tMenuPause.loadFromFile("donnees/MenuPause.png");
    m_tMenuFinP.loadFromFile("donnees/FinPartie.png");
    m_tTypeJeu.loadFromFile("donnees/selectTypeJ.png");




}

void Menu::initMenuP()
{
    m_sMenuP.setTexture(m_tMenuP);
}

void Menu::initMenuSelectP()
{
    m_sTypeJeu.setTexture(m_tTypeJeu);
}

void Menu::initMenuI()
{
    m_sMenuI.setTexture(m_tMenuI);
}

void Menu::initMenuPause()
{
    m_sMenuPause.setTexture(m_tMenuPause);
}

void Menu::initMenuFinPart()
{
    m_sMenuFinP.setTexture(m_tMenuFinP);
}

void Menu::setTypeMenu(int menuActuel)
{
    if(menuActuel==MenuPrincipal)
    {
        m_typeMenu=MenuPrincipal;
    }
    else if(menuActuel==MenuInstructions)
    {
        m_typeMenu=MenuInstructions;
    }
    else if(menuActuel==MenuSelectTypeJ)
    {
        m_typeMenu=MenuSelectTypeJ;
    }
    else if(menuActuel==MenuPause)
    {
        m_typeMenu=MenuPause;
    }
    else if(menuActuel==MenuFinPartie)
    {
        m_typeMenu=MenuFinPartie;
    }
    else
    {

    }
}

TypeMenu Menu::getTypeMenu()
{
    return m_typeMenu;
}

void Menu::retourMenuP()
{
    m_typeMenu=MenuPrincipal;
    m_elementActif=AUCUN_EL_ACT;
}

void Menu::elementActif()
{
    if(m_typeMenu==MenuPrincipal)
    {
        if(collisionTS(m_sbJoueur1.getGlobalBounds()))
        {
            m_elementActif=JOUEUR1_ACTIF;
        }
        else if(collisionTS(m_sbJoueur1.getGlobalBounds()))
        {
            m_elementActif=JOUEUR2_ACTIF;
        }
        else if(collisionTS(m_sbInstructions.getGlobalBounds()))
        {
            m_elementActif=INSTRUCTIONS_ACTIF;
        }
        else if(collisionTS(m_sbSon.getGlobalBounds()))
        {
            m_elementActif=SON_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuSelectTypeJ)
    {
        if(collisionTS(m_sbMenu.getGlobalBounds()))
        {

        }
        else if()
        {

        }
        else if()
        {

        }
        else if()
        {

        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuInstructions)
    {
        if(collisionTS(m_sbOk.getGlobalBounds()))
        {
            m_elementActif=OK_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }
    }
    else if(m_typeMenu==MenuPause)
    {
        if(collisionTS(m_sbResume.getGlobalBounds()))
        {
            m_elementActif=PAUSER_ACTIF;
        }
        else if(collisionTS(m_sbRejouer.getGlobalBounds()))
        {
            m_elementActif=PAUSEREJ_ACTIF;
        }
        else if(collisionTS(m_sbInstructions.getGlobalBounds()))
        {
            m_elementActif=PAUSEI_ACTIF;
        }
        else if(collisionTS(m_sbQuitter.getGlobalBounds()))
        {
            m_elementActif=PAUSEQ_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuFinPartie)
    {
        if(collisionTS(m_sbMenuFP.getGlobalBounds()))
        {
            m_elementActif=FINPQ_ACTIF;
        }
        else if(collisionTS(m_sbRejouerFP.getGlobalBounds()))
        {
            m_elementActif=FINPR_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else
    {

    }

}

void Menu::selectionElActif()
{

}

bool Menu::collisionTS(sf::FloatRect elem)
{

}

int Menu::getBoutonPress()
{
    return m_boutonPress;
}

void Menu::resetBoutonPress()
{
    m_boutonPress=AUCUN_EL_ACT;
}

void Menu::quitterJeu()
{

}

void Menu::afficheMenuP()
{

}

void Menu::afficheMenuSelectP()
{

}

void Menu::afficheMenuI()
{

}

void Menu::afficheMenuPause()
{

}
void Menu::afficheMenuFinPart()
{

}

void Menu::afficheMenu()
{

}

Menu::~Menu()
{

}
