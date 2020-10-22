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
    MenuInstructions1,
    MenuInstructions2,
    MenuInstructions3,
    MenuPause,
    MenuFinPartie,
    MenuEnregScore

};

enum
{
    AUCUN_EL_ACT,
    JOUER_ACTIF,
    INSTRUCTIONS_ACTIF,
    QUITTER_ACTIF,
    OK_ACTIF,
    PRECEDENT_ACTIF,
    SUIVANT_ACTIF,
    RETOUR_ACTIF,
    PAUSER_ACTIF,
    PAUSEI_ACTIF,
    PAUSEQ_ACTIF,
    FINPQ_ACTIF,
    FINPR_ACTIF,
    ESOk_ACTIF

};



#endif // DEF_ENUMS
