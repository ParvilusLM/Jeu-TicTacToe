#include "joueur.h"


Joueur::Joueur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_tMarqueur.loadFromFile("donnees/piece.png");
    m_tGrille1.loadFromFile("donnees/grille1.png");
    m_tGrille2.loadFromFile("donnees/grille2.png");
    m_tGrille3.loadFromFile("donnees/grille3.png");

    m_tbPause.loadFromFile("donnees/bJeuEnCours.png");

    m_fText.loadFromFile("donnees/charlbold.ttf");

    m_sbPause.setTexture(m_tbPause);
    m_sbPause.setPosition(1*20.f,1*20.f);
    m_sbPause.setTextureRect(sf::IntRect(1*20,1*20,4*20,4*20));

    m_text.setFont(m_fText);
    m_text.setCharacterSize(25);
    m_text.setColor(sf::Color::Red);
    m_text.setPosition(19.5*20,22.5*20);


}

void Joueur::initGrille()
{
    //mise a zero
    m_grille.grille.clear();
    m_grille.joueurs.clear();

    //selection grille
    if(m_grille.taille==3)
    {
        m_grille.sGrille.setTexture(m_tGrille1);
    }
    else if(m_grille.taille==5)
    {
        m_grille.sGrille.setTexture(m_tGrille2);
    }
    else if(m_grille.taille==7)
    {
        m_grille.sGrille.setTexture(m_tGrille3);
    }
    else
    {

    }

    //determiner la taille du tableau
    int compt=0;
    int taill=m_grille.taille*m_grille.taille;
    while(compt<taill)
    {
        m_grille.grille.insert(m_grille.grille.begin(),VIDE);
        compt++;
    }
    std::cout<<"Taille Grille: "<<m_grille.grille.size()<<std::endl;

    //joueurs
    EntiteJoueur nouvJ;
    m_grille.joueurs.insert(m_grille.joueurs.begin(),nouvJ);
    m_grille.joueurs.insert(m_grille.joueurs.begin(),nouvJ);

}


bool Joueur::selectionCase(int joueur)
{
    bool caseSelectionne=false;
    bool caseVide=false;

    //determiner la case sur lequel est le curseur
    int no_case=-1;

    if(sourisX > 7.5*20 && sourisX < 37.5*20 && sourisY > 4*20 && sourisY < 34*20)
    {
        if(m_grille.taille==3)
        {
            no_case= (((sourisY-(4*20) ) /(10*20) ) * m_grille.taille) + ((sourisX-(7.5*20)) / (10*20)) ;
        }
        else if(m_grille.taille==5)
        {
            no_case= (((sourisY-(4*20) ) /(6*20) ) * m_grille.taille) + ((sourisX-(7.5*20)) / (6*20)) ;
        }
        else
        {
            if(sourisX > 8.5*20 && sourisX < 36.5*20 && sourisY > 5*20 && sourisY < 33*20)
            {
                no_case= (((sourisY-(5*20) ) /(4 * 20) ) * m_grille.taille) + ((sourisX-(8.5*20)) / (4 * 20)) ;
            }

        }

    }

    if(no_case >= 0)
    {
        if(m_grille.grille.at(no_case)==VIDE )
        {
            caseVide=true;
        }
    }

    if(caseVide)
    {
        caseSelectionne =true;
        if(joueur==HUMAIN1)
        {
            laMain=false;

            sf::Sprite piece;
            piece.setTexture(m_tMarqueur);
            if(m_grille.taille==3)
            {
                m_grille.grille.at(no_case)=MARQUEUR1;

                int px=no_case%3;
                int py=no_case/3;
                piece.setTextureRect(sf::IntRect(0,0,7*20,7*20));
                piece.setOrigin(3.5*20,3.5*20);
                piece.setPosition((px *(10*20)) + (7.5*20) + (5*20) ,(py * (10*20))+ (4*20) + (5*20) );

                m_grille.joueurs.at(0).pieces.insert(m_grille.joueurs.at(0).pieces.begin(),piece);
            }
            else if(m_grille.taille==5)
            {
                m_grille.grille.at(no_case)=MARQUEUR1;
                int px=no_case%5;
                int py=no_case/5;
                piece.setTextureRect(sf::IntRect(0,8*20,4*20,4*20));
                piece.setOrigin(2*20,2*20);
                piece.setPosition((px *(6*20)) + (7.5*20) + (3*20) ,(py * (6*20))+ (4*20) + (3*20) );

                m_grille.joueurs.at(0).pieces.insert(m_grille.joueurs.at(0).pieces.begin(),piece);
            }
            else
            {
                m_grille.grille.at(no_case)=MARQUEUR1;
                int px=no_case%7;
                int py=no_case/7;
                piece.setTextureRect(sf::IntRect(0,13*20,3*20,3*20));
                piece.setOrigin(1.5*20,1.5*20);
                piece.setPosition((px *(4*20)) + (7.5*20) + (3*20) ,(py * (4*20))+ (4*20) + (3*20) );

                m_grille.joueurs.at(0).pieces.insert(m_grille.joueurs.at(0).pieces.begin(),piece);
            }

        }
        else
        {
            laMain=true;

            sf::Sprite piece;
            piece.setTexture(m_tMarqueur);
            if(m_grille.taille==3)
            {
                m_grille.grille.at(no_case)=MARQUEUR2;
                int px=no_case%3;
                int py=no_case/3;
                piece.setTextureRect(sf::IntRect(0,18*20,7*20,7*20));
                piece.setOrigin(3.5*20,3.5*20);
                piece.setPosition((px *(10*20)) + (7.5*20) + (5*20) ,(py * (10*20))+ (4*20) + (5*20) );

                m_grille.joueurs.at(1).pieces.insert(m_grille.joueurs.at(1).pieces.begin(),piece);
            }
            else if(m_grille.taille==5)
            {
                m_grille.grille.at(no_case)=MARQUEUR2;
                int px=no_case%5;
                int py=no_case/5;
                piece.setTextureRect(sf::IntRect(0,26*20,4*20,4*20));
                piece.setOrigin(2*20,2*20);
                piece.setPosition((px *(6*20)) + (7.5*20) + (3*20) ,(py * (6*20))+ (4*20) + (3*20) );

                m_grille.joueurs.at(1).pieces.insert(m_grille.joueurs.at(1).pieces.begin(),piece);
            }
            else
            {
                m_grille.grille.at(no_case)=MARQUEUR2;
                int px=no_case%7;
                int py=no_case/7;
                piece.setTextureRect(sf::IntRect(0,31*20,3*20,3*20));
                piece.setOrigin(1.5*20,1.5*20);
                piece.setPosition((px *(4*20)) + (7.5*20) + (3*20) ,(py * (4*20))+ (4*20) + (3*20) );

                m_grille.joueurs.at(1).pieces.insert(m_grille.joueurs.at(1).pieces.begin(),piece);
            }
        }
    }

    return caseSelectionne;

    std::cout<<"Case: "<<no_case<<std::endl;

}

bool Joueur::selectionCaseIa()
{
    bool caseSelectionne=false;
    bool caseVide=false;

    std::vector<int > ensembleCaseVide;

    //on parcours le tableau pour remplir le vecteur ensembleCaseVide;
    int compt=0;
    while(compt<m_grille.grille.size())
    {
        if(m_grille.grille.at(compt)==VIDE)
        {
            ensembleCaseVide.insert(ensembleCaseVide.end(),compt);
        }
        compt++;
    }

    if(ensembleCaseVide.size()!=0)
    {
        caseSelectionne=true;
        //on choisit une des cases au hasard
        int caseChoisie=ensembleCaseVide.at(rand()%ensembleCaseVide.size());
        std::cout<<"Case choisie par l'IA: "<<caseChoisie<<std::endl;


        laMain=true;

        sf::Sprite piece;
        piece.setTexture(m_tMarqueur);
        if(m_grille.taille==3)
        {
            m_grille.grille.at(caseChoisie)=MARQUEUR2;
            int px=caseChoisie%3;
            int py=caseChoisie/3;
            piece.setTextureRect(sf::IntRect(0,18*20,7*20,7*20));
            piece.setOrigin(3.5*20,3.5*20);
            piece.setPosition((px *(10*20)) + (7.5*20) + (5*20) ,(py * (10*20))+ (4*20) + (5*20) );
        }
        else if(m_grille.taille==5)
        {
            m_grille.grille.at(caseChoisie)=MARQUEUR2;
            int px=caseChoisie%5;
            int py=caseChoisie/5;
            piece.setTextureRect(sf::IntRect(0,26*20,4*20,4*20));
            piece.setOrigin(2*20,2*20);
            piece.setPosition((px *(6*20)) + (7.5*20) + (3*20) ,(py * (6*20))+ (4*20) + (3*20) );
        }
        else
        {
            m_grille.grille.at(caseChoisie)=MARQUEUR2;
            int px=caseChoisie%7;
            int py=caseChoisie/7;
            piece.setTextureRect(sf::IntRect(0,31*20,3*20,3*20));
            piece.setOrigin(1.5*20,1.5*20);
            piece.setPosition((px *(4*20)) + (7.5*20) + (3*20) ,(py * (4*20))+ (4*20) + (3*20) );
        }

        m_grille.joueurs.at(1).pieces.insert(m_grille.joueurs.at(1).pieces.begin(),piece);

    }
    return caseSelectionne;
}

GrilleJeu& Joueur::getGrille()
{
    return m_grille;
}

void Joueur::gestBoutons()
{
    if(!jeuPause)
    {
        if(collisionTS(m_sbPause.getGlobalBounds()))
        {
            m_sbPause.setTextureRect(sf::IntRect(1*20,6*20,4*20,4*20));
        }
        else
        {
            m_sbPause.setTextureRect(sf::IntRect(1*20,1*20,4*20,4*20));
        }
    }
}

bool Joueur::boutonSelect()
{
    bool select=false;
    if(collisionTS(m_sbPause.getGlobalBounds()))
    {
        select=true;

    }

    return select;
}

bool Joueur::partieGagne(int joueur, int nbPiecAlign)
{
    bool gagne=false;
    bool continueVerif=true;

    //on parcours toute la grille
    int compt=0;
    while(compt<m_grille.grille.size())
    {
        //on teste que les pieces du joueur voulu
        if(m_grille.grille.at(compt)==joueur+1)
        {

            //gauche
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posx>=0)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posx--;
                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }

            }


            //droite
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posx<m_grille.taille)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posx++;
                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }

            }


            //haut
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posy>=0)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posy--;
                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }
            }

            //bas
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posy<m_grille.taille)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posy++;
                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }
            }

            //diagonal HG
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posx>=0 && posy>=0)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posx--;
                            posy--;

                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }
            }

            //diagonal HD
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posx < m_grille.taille && posy>=0)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posx++;
                            posy--;

                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }
            }

            //diagonal BG
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posx>=0 && posy<m_grille.taille)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posx--;
                            posy++;

                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }
            }

            //diagonal BD
            if(continueVerif)
            {
                //utile pour representer la grille en 2 dimensions
                int posx=compt % m_grille.taille;
                int posy=compt / m_grille.taille;

                int pieceAlign=0;

                int comptt=0;
                while(comptt==0)
                {
                    int indicCase=(posy*m_grille.taille) + posx;

                    if(posx < m_grille.taille && posy< m_grille.taille)
                    {
                        if(m_grille.grille.at(indicCase)==joueur+1)
                        {
                            pieceAlign++;
                            posx++;
                            posy++;

                        }
                        else
                        {
                            comptt++;
                        }

                    }
                    else
                    {
                        comptt++;
                    }
                }

                if(pieceAlign>=nbPiecAlign)
                {
                    gagne=true;
                    continueVerif=false;
                }
            }
        }
        compt++;
    }

    if(gagne)
    {
        if(joueur==HUMAIN1)
        {
            m_text.setString("JOUEUR 1");
        }
        else
        {
            if(m_grille.nombreJ==1)
            {
                m_text.setString("   CPU");
            }
            else
            {
                m_text.setString("JOUEUR 2");
            }
        }
    }

    return gagne;
}

void Joueur::gestMaj()
{
    gestBoutons();
}

bool Joueur::collisionTS(sf::FloatRect elem)
{
    bool collision=false;
    if((elem.left<sourisX && elem.left+elem.width>sourisX) &&
       (elem.top<sourisY && elem.top+elem.height>sourisY))
    {
        collision=true;
    }
    return collision;
}


void Joueur::afficheGrille()
{
    //grille
    m_fenetre->draw(m_grille.sGrille);

    //les pieces
    int compt=0;
    while(compt<m_grille.joueurs.size())
    {
        int compt2=0;
        while(compt2<m_grille.joueurs.at(compt).pieces.size())
        {
            m_fenetre->draw( m_grille.joueurs.at(compt).pieces.at(compt2));
            compt2++;
        }
        compt++;
    }
}

void Joueur::afficheBouton()
{
    m_fenetre->draw(m_sbPause);
}

void Joueur::afficheText()
{
    m_fenetre->draw(m_text);
}

Joueur::~Joueur()
{

}
