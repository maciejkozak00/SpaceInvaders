#ifndef SPACEINVADERSJH_SPACESHIP_H
#define SPACEINVADERSJH_SPACESHIP_H

#include <SFML/Graphics.hpp>

struct Bullet
{
    float x;    //x kuli
    float y;    //y kuli

    bool visible;   //czy kula jest widzialna
};

class SpaceShip
{
    sf::RenderWindow &win;  //okno

    sf::Vector2f spacePos;  //pozycja gracza

    int speed;  //prędkość
    bool isMoving;  //przechowuje czy gracz się porusza

    Bullet bullet;  //kula

public:
    explicit SpaceShip(sf::RenderWindow &win);   //konstruktor z referencją na okno
    void placeSpaceship(float x, float y);  //ustawia statek w pozycji (x, y)

    sf::Vector2f getSpacePos(); //zwraca pozycje statku

    void moveSpaceship(float frameTime);    //ruch statkiem
    bool getIsMoving();    //zwraca czy statek się porusza

    void update(float frameTimeAsSeconds);  //wykonywane co klatke

    void resetBullet(); //resetuje kule
    bool checkIfBulletVisible();    //sprawdza czy kula jest widoczna
    void shoot();   //strzał
    void moveBullet(float frameTime);   //porusza kule
    sf::Vector2f getBulletPos();    //zwraca pozycje kuli
    void checkIfShoot(sf::Event &event);

};


#endif //SPACEINVADERSJH_SPACESHIP_H
