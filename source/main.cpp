#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;

bool jeuEnCours=false;
bool jeuPause=false;
bool jeuFinPartie=false;
bool jeuDebut=false;
bool jeuRejouer=false;
int sourisX=0,sourisY=0;

int main()
{
    srand(time(0));


    RenderWindow fenetre(VideoMode(900,700),"Tetris");


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
                    //controleurJ.gestionDplSouris();

                }
                else if(jeuEnCours && jeuPause)
                {
                    //controleurJ.gestionDplSouris();
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
                            //controleurJ.gestionSelecSouris();
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
                            //controleurJ.teleporTetro();
                        }

                        if (button == Mouse::Right) // Bouton droite
                        {
                            //controleurJ.stockerTetroActif();
                        }
                    }
                }
                else
                {
                    Mouse::Button button = evenement.mouseButton.button;
                    if (button == Mouse::Left) // Bouton gauche
                    {
                        //controleurJ.gestionSelecSouris();
                        if(jeuDebut)
                        {
                            //controleurJ.debutJeu();
                        }
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
                            /*
                            if(timer>delai)
                            {
                                controleurJ.mouvementTetro(mouv_g);
                                timer=0;
                            }
                            */
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Right))
                        {
                            /*
                            if(timer>delai)
                            {
                                controleurJ.mouvementTetro(mouv_d);
                                timer=0;
                            }
                            */
                        }
                        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        {
                            //controleurJ.rotationTertro(ROTATION_D);
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Down))
                        {
                            //controleurJ.descenteRapide();
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Z))
                        {
                            //controleurJ.rotationTertro(ROTATION_G);
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::C))
                        {
                            //controleurJ.stockerTetroActif();
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                            //controleurJ.pauseJeu();
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Space))
                        {
                            //controleurJ.teleporTetro();
                        }
                        else
                        {

                        }

                    }
                    else
                    {
                        if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                            //controleurJ.pauseJeu();
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
                        //controleurJ.saisieL(characTape);
                    }

                }
                break;

            default:;
            }


        }

        if(jeuEnCours)
        {
            if(!jeuPause)
            {
                //controleurJ.gestMajDonnees();
            }

        }
        else
        {
            if(jeuSauvegarde)
            {
                //controleurJ.sauvegardeScore();
                //controleurJ.reinitTablScore();
            }
        }

        fenetre.clear(Color(82,82,82));

        //controleurJ.afficheFondEc();

        if(jeuEnCours)
        {
            //controleurJ.afficheJeu();
        }
        else
        {
            //controleurJ.afficheMenu();
        }

        fenetre.display();
    }

    return 0;
}
