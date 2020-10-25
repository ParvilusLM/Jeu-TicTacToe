#ifndef DEF_JOUEUR
#define DEF_JOUEUR


#include "enums.h"
#include "varG.h"
#include "constantes.h"
#include <SFML/Graphics.hpp>

class Joueur
{
public:
    Joueur(sf::RenderWindow& fenetre);
    void initGrille();
    bool selectionCase(int joueur);
    void marquageCase(int joueur);
    GrilleJeu& getGrille();
    void gestBoutons();
    void gestMaj();
    void afficheGrille();
    void afficheBouton();

    ~Joueur();

private:
    sf::RenderWindow* m_fenetre;
    GrilleJeu m_grille;

    sf::Texture m_tMarqueur;
    sf::Texture m_tGrille1;
    sf::Texture m_tGrille2;
    sf::Texture m_tGrille3;

    //bouton pause
    sf::Texture m_tbPause;
    sf::Sprite m_sbPause;

    //texte pour le gagnant
    sf::Font m_fText;
    sf::Text m_text;


};

#endif // DEF_JOUEUR
