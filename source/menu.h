#ifndef DEF_MENU
#define DEF_MENU

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"

class Menu
{
public:
    Menu(sf::RenderWindow& fenetre);

    void initMenuP();
    void initMenuSelectP();
    void initMenuI();
    void initMenuPause();
    void initMenuFinPart();

    void setTypeMenu(int menuActuel);
    TypeMenu getTypeMenu();

    void retourMenuP();
    void elementActif();
    void selectionElActif();
    bool collisionTS(sf::FloatRect elem);
    int getBoutonPress();
    void resetBoutonPress();
    void quitterJeu();

    void gestTexture(int bouton, int type);

    void afficheMenuP();
    void afficheMenuSelectP();
    void afficheMenuI();
    void afficheMenuPause();
    void afficheMenuFinPart();
    void afficheMenu();

    ~Menu();

private:
    sf::RenderWindow* m_fenetre;

    TypeMenu m_typeMenu;
    sf::Font m_font;
    sf::Font m_font2;
    sf::Font m_font3;

    int m_elementActif;

    int m_boutonPress;

    //textures pour les boutons
    sf::Texture m_tSelectInstr,m_tSelectMP,m_tSelectTypeJ,m_tSelectMPause,m_tSelectMGO;

    //sprites pour les boutons
    sf::Sprite m_sbInfo,m_sbSon,m_sbJoueur1,m_sbJoueur2;//menuPrincipal
    sf::Sprite m_sbMenu,m_sbGrille1,m_sbGrille2,m_sbGrille3;//menuSelectTypeJ
    sf::Sprite m_sbOk;//menuInstructions
    sf::Sprite m_sbResume,m_sbRejouer,m_sbInstructions,m_sbQuitter;//menuPause
    sf::Sprite m_sbMenuFP,m_sbRejouerFP;//menu finPartie


    //pour menu principal
    sf::Texture m_tMenuP;
    sf::Sprite m_sMenuP;

    //pour menu TypeJeu
    sf::Texture m_tTypeJeu;
    sf::Sprite m_sTypeJeu;

    //pour menu instructions
    sf::Texture m_tMenuI;
    sf::Sprite m_sMenuI;

    //pour menu pause
    sf::Texture m_tMenuPause;
    sf::Sprite m_sMenuPause;

    //pour menu fin partie
    sf::Texture m_tMenuFinP;
    sf::Sprite m_sMenuFinP;

    /*
    //boites engl des boutons
    sf::FloatRect boiteEBJ1,boiteEBJ2,boiteEBI,boiteEBS;
    sf::FloatRect boiteEBM,boiteEBC1,boiteEBC2,boiteEBC3;
    sf::FloatRect boiteEBPaus;
    sf::FloatRect boiteEBOk;
    sf::FloatRect boiteEBPR,boiteEBRej,boiteEBPI,boiteEBPQ;
    sf::FloatRect boiteEBFQ,boiteEBFR;
    */

};

#endif // DEF_MENU
