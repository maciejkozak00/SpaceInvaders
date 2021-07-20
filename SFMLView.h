//
// Created by macie on 31.05.2021.
//

#ifndef SPACEINVADERSJH_SFMLVIEW_H
#define SPACEINVADERSJH_SFMLVIEW_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include "SpaceShip.h"
#include "SpaceInvadersBoard.h"

class SFMLView : public sf::Drawable
{
    sf::RenderWindow &win;
    SpaceShip &player;
    SpaceInvadersBoard &board;

    sf::Vector2f blockSize;  //rozmiar jednego bloku

    sf::RectangleShape spaceShip;   //gracz jako prostokąt
    sf::Texture spaceShipTexture;   //tesktura gracza
    sf::Texture spaceShipMovingTexture;   //tesktura gracza
    sf::RectangleShape bullet;  //strzała

    std::vector<sf::RectangleShape> enemy; //wektor przeciwników jako prostokąty
    sf::Texture enemyTexture;   //tekstura przeciwnika
    sf::RectangleShape enemyBullet; //kula ale to prostokąt



public:
    SFMLView(sf::RenderWindow &win, SpaceShip &player, SpaceInvadersBoard &board);

    void setBlockSize();    //ustala rozmiar jednego bloku

    void setScreen();       //funckja wywoływana tylko raz, ustawia wielkość rzeczy na ekranie, kolor, teksture itp itp
    void updateScreen();    //funckja wywoływana przy każdej klatce, przemieszcza obiekty itp

    void draw(sf::RenderTarget &target, sf::RenderStates states) const; //odziedziczona metoda po sf::Drawable, rysuje na targecie

    void checkIfEnemyKilled();  //sprawdza czy przeciwnik jest zabity
    bool checkCollision();  //sprawdza kolizje między graczem a przeciwnikami
    bool checkIfKilled();  //sprawdza statek został zestrzelony
    bool checkIfEscaped();  //sprawdza czy przeciwnicy są poza ekranem

    void loadTextures(); //ładuje tekstury
    void update();

};


#endif //SPACEINVADERSJH_SFMLVIEW_H
