#ifndef DEF_DECOR
#define DEF_DECOR

class Decor
{
public:
    Decor(sf::RenderWindow& fenetre);

    Menu& getMenu();
    Info& getInfo();
    Son& getSon();
    Joueur& getJoueur;

    ~Decor();

private:
    sf::RenderWindow* m_fenetre;
    Menu* m_menu;
    Info* m_info;
    Son* m_son;
    Joueur* m_joueur;

};

#endif // DEF_DECOR
