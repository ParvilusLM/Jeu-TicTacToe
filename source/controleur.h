#ifndef DEF_CONTROLEUR
#define DEF_CONTROLEUR

#include <SFML/Graphics.hpp>
#include <iostream>
#include "decor.h"

class Controleur
{
public:
    Controleur(sf::RenderWindow& fenetre);

    void debutJeu();
    void pauseJeu();


    void gestionDplSouris();
    void gestionSelecSouris();

    void gestMaJ();

    void finPartie();

    void afficheFondEc();
    void afficheJeu();
    void afficheMenu();
    void afficheInfo();

    ~Controleur();

private:
    sf::RenderWindow* m_fenetre;
    Decor* m_decor;

};


#endif // DEF_CONTROLEUR
