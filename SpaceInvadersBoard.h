#ifndef SPACEINVADERSJH_SPACEINVADERSBOARD_H
#define SPACEINVADERSJH_SPACEINVADERSBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SpaceShip.h"
#include "iostream"

struct EnemySpaceShips
{
    float posX; //pozycja x jednego przeciwnika
    float posY; //pozycja y jednego przeciwnika

    bool isAlive;   //mówi czy przeciwnik żyje
};

struct enemyBullet
{
    float posX; //x kuli przeciwnika
    float posY; //x kuli przeciwnika

    bool isVisible; //zwraca czy kula jest widoczna
};

class SpaceInvadersBoard
{
    std::vector<std::vector<int>> board;    //plansza
    int mapWidth;   //szerokość mapy
    int mapHeight;  //wysokość mapy

    std::vector<EnemySpaceShips> enemy; //wektor przeciwników
    int enemyCount; //ilość przeciwników
    int enemySizeX; //szerokość
    int enemySizeY; //wysokość
    float speed;   //prędkość przeciwników
    int enemyDir;   //kierunek przeciwników
    enemyBullet bullet; //pocisk przeciwnika

    int enemyAlive; //żywi przeciwnicy

    SpaceShip &player;  //gracz
    sf::RenderWindow &win;  //okno

    int level;
    int score;

public:
    SpaceInvadersBoard(SpaceShip &player, sf::RenderWindow &win);

    void prepareEnemy();    //przygotowuje przeciwników, ustawia ich itp
    void placeEnemy(float x, float y, int counter); //stawia przeciwnika w (x,y)
    int getEnemyCount();    //zwraca ilość przeciwników
    sf::Vector2f getEnemyPos(int index);  //zwraca pozycje przeciwnika
    void killEnemy(int i);  //robi przeciwnika niewidzialnym
    bool isEnemyAlive(int i); //sprawdza czy przeciwnik żyje
    void moveEnemy(float frameTime);    //porusza przeciwników
    void turnEnemy();    //odbija przeciwników
    void moveEnemyDown();    //przesuwa przeciwnika w dół
    void shoot(sf::Clock &clock, float difficulty);   //przeciwnik strzela
    void moveEnemyBullet(float frameTime);
    float getBulletX();
    float getBulletY();
    void resetBullet();
    void update(float frameTimeAsSeconds, sf::Clock &enemyClock, float diff);  //wykonywane co klatke

    bool checkIfWon();

    int getLevel();
    int getScore();

    int getMapWidth();  //zwraca szerokość mapy
    int getMapHeight(); //zwraca wysokość mapy


};


#endif //SPACEINVADERSJH_SPACEINVADERSBOARD_H
