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

    //pour le masque selecteur
    sf::Texture m_tSelectInstr,m_tSelectMP,m_tSelectMPause,m_tSelectMGO,m_tSelectEScore;
    sf::Sprite m_sIndicSelect;

    //pour menu principal
    sf::Texture m_tMenuP;
    sf::Sprite m_sMenuP;


    //pour menu instructions
    sf::Texture m_tMenuI;
    sf::Sprite m_sMenuI;

    //pour menu pause
    sf::Texture m_tMenuPause;
    sf::Sprite m_sMenuPause;

    //pour menu fin partie
    sf::Texture m_tMenuFinP;
    sf::Sprite m_sMenuFinP;


    //boites engl des boutons
    sf::FloatRect boiteEBJ,boiteEBI,boiteEBQ,boiteEBPr,boiteEBSuiv,boiteEBOk,boiteEBPR,boiteEBPI,boiteEBPQ,boiteEBFQ,boiteEBFR,boiteEBESOk;



};

#endif // DEF_MENU
