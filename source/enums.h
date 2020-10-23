#ifndef DEF_ENUMS
#define DEF_ENUMS

#include<SFML/Graphics.hpp>

struct EntiteJoueur
{
    std::vector<sf::Vector2f > pieces;
    int type;
};

struct GrilleJeu
{
    std::vector<int > grille;
    EntiteJoueur joueurs;
    int taille;

};

enum TypeMenu
{
    MenuPrincipal,
    MenuSelectTypeJ,
    MenuInstructions,
    MenuPause,
    MenuFinPartie
};

enum
{
    AUCUN_EL_ACT,
    JOUEUR1_ACTIF,
    JOUEUR2_ACTIF,
    INSTRUCTIONS_ACTIF,
    SON_ACTIF,
    MENU_ACTIF,
    GRILLE1_ACTIF,
    GRILLE2_ACTIF,
    GRILLE3_ACTIF,
    OK_ACTIF,
    PAUSER_ACTIF,
    PAUSEREJ_ACTIF,
    PAUSEI_ACTIF,
    PAUSEQ_ACTIF,
    FINPQ_ACTIF,
    FINPR_ACTIF
};



#endif // DEF_ENUMS
