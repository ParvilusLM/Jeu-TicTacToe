#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include "controleur.h"

using namespace sf;

bool jeuEnCours=false;
bool jeuPause=false;
bool jeuFinPartie=false;
bool jeuDebut=false;
bool jeuRejouer=false;
bool boutonPresse=false;//pour savoir s'il y a clic
bool laMain=true;
int sourisX=0,sourisY=0;

int main()
{
    srand(time(0));


    RenderWindow fenetre(VideoMode(900,700),"Tic Tac Toe");

    Controleur controleurJ(fenetre);

    while(fenetre.isOpen())
    {
        Event evenement;
        while(fenetre.pollEvent(evenement))
        {
            if(evenement.type==Event::Closed)
            {
                fenetre.close();
            }

            if(evenement.type==Event::MouseMoved)
            {
                sourisX=evenement.mouseMove.x;
                sourisY=evenement.mouseMove.y;
                if(!jeuEnCours)
                {
                    controleurJ.gestionDplSouris();

                }
                else if(jeuEnCours && jeuPause)
                {
                    controleurJ.gestionDplSouris();
                }
                else
                {

                }
            }


            switch(evenement.type)
            {
            case Event::MouseButtonPressed:
                if(jeuEnCours)
                {

                    if(jeuPause)
                    {
                        Mouse::Button button = evenement.mouseButton.button;

                        if (button == Mouse::Left) // Bouton gauche
                        {
                            controleurJ.gestionSelecSouris();
                            boutonPresse=true;


                        }

                        if (button == Mouse::Right) // Bouton droite
                        {

                        }

                    }
                    else
                    {
                        Mouse::Button button = evenement.mouseButton.button;

                        if (button == Mouse::Left) // Bouton gauche
                        {
                            controleurJ.gestBoutonsJeu();
                            controleurJ.tourJoueur();
                        }

                        if (button == Mouse::Right) // Bouton droite
                        {

                        }
                    }
                }
                else
                {
                    Mouse::Button button = evenement.mouseButton.button;
                    if (button == Mouse::Left) // Bouton gauche
                    {
                        controleurJ.gestionSelecSouris();
                    }
                }
                break;

            case Event::KeyPressed:
                if(jeuEnCours)
                {

                    if(!jeuPause)
                    {
                        if(sf::Keyboard::isKeyPressed(Keyboard::Left))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Right))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Down))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Z))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::C))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Space))
                        {

                        }
                        else
                        {

                        }

                    }
                    else
                    {
                        if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
                        {

                        }
                    }
                }
                else
                {

                }
                break;

            case Event::TextEntered:
                if(jeuEnCours && jeuPause)
                {
                    if(evenement.text.unicode>96 && evenement.text.unicode<123)
                    {
                        char characTape;
                        characTape=static_cast<char>(evenement.text.unicode);
                        std::cout<<"ASCII character : "<<evenement.text.unicode<<std::endl;
                    }

                }
                break;

            default:;
            }


        }

        controleurJ.gestMaJ();

        if(jeuEnCours)
        {



        }
        else
        {

        }

        fenetre.clear(Color(82,82,82));

        controleurJ.afficheFondEc();

        if(jeuEnCours)
        {
            controleurJ.afficheJeu();
        }
        else
        {
            controleurJ.afficheMenu();
        }

        fenetre.display();

    }

    return 0;
}
