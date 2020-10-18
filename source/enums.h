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



#endif // DEF_ENUMS
