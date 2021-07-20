//
// Created by macie on 30.05.2021.
//

#include "SpaceInvadersBoard.h"

SpaceInvadersBoard::SpaceInvadersBoard(SpaceShip &player, sf::RenderWindow &win) : player(player), win(win)
{
    mapWidth = 50;  //szerokośc i wysokość mapy
    mapHeight = 50;

    enemySizeX = 30;    //szerokość i wysokość przeciwników
    enemySizeY = 20;
    enemyCount = enemySizeX * enemySizeY;   //liczy ile ma być przeciwników
    enemy.resize(enemyCount);   //zmienia wielkość wektora przeciwników
    speed = 5;  //prędkość przeciwników na 5
    enemyDir = 1;   //kierunek w którym przeciwnicy będą się poruszać (1 = w prawo, 0,  w lewo)

    bullet.isVisible = false;   //ustawia kule przeciwnika na niewidzialną

    enemyAlive = enemySizeX * enemySizeY;
    prepareEnemy();

    level = 1;
    score = 0;
}

void SpaceInvadersBoard::prepareEnemy()
{
    int i = 0;  //licznik
    for(int x = 0; x < enemySizeX; x++) //dla szerokości przeciwników
    {
        for(int y = 0; y < enemySizeY; y++) //dla wysokości przeciwników
        {
            placeEnemy(float(x), float(y), i);  //stawia przeciwnika
            i++;
        }
    }
    level = 0;
}

void SpaceInvadersBoard::placeEnemy(float x, float y, int counter)
{
    enemy.at(counter).posX = x; //ustaiwa pozycje przeciwnika na x
    enemy.at(counter).posY = y; //ustaiwa pozycje przeciwnika na y
    enemy.at(counter).isAlive = true;   //ustawia, że przeciwnik jest żywy
}

int SpaceInvadersBoard::getMapWidth() {
    return mapWidth;
}

int SpaceInvadersBoard::getMapHeight() {
    return mapHeight;
}

int SpaceInvadersBoard::getEnemyCount()
{
    return enemyCount;
}

sf::Vector2f SpaceInvadersBoard::getEnemyPos(int index)
{
    return sf::Vector2f(enemy.at(index).posX, enemy.at(index).posY);    //zwraca pozycje przeciwnika o podanym indeksie
}

void SpaceInvadersBoard::killEnemy(int i)   //zabija przeciwnika o podanym indeksie
{
    enemyAlive--;   //potrzebne do wygrania
    score++;
    enemy.at(i).isAlive = false;
}

bool SpaceInvadersBoard::isEnemyAlive(int i) {  //sprawdza czy przeciwnik o podanym indeksie żyje
    return enemy.at(i).isAlive;
}

void SpaceInvadersBoard::moveEnemy(float frameTime) //porusza cały wektor przeciwników
{
    for(int i = 0; i < enemyCount; i++)
    {
        enemy.at(i).posX = enemy.at(i).posX + (speed * frameTime * float(enemyDir));
    }
}

void SpaceInvadersBoard::turnEnemy()    //zmienia kierunek poruszania się przeciwników
{
    if(enemy.at(enemyCount - 1).posX >= float(mapWidth - 1))    //jeżeli dotrą do prawego krańca mapy
    {
        enemyDir = -1;
        moveEnemyDown();
    }
    if(enemy.at(0).posX <= 0)   //jeżeli dotrą do lewego krańca mapy
    {
        enemyDir = 1;
        moveEnemyDown();
    }
}

void SpaceInvadersBoard::moveEnemyDown()    //porusza wektor przeciwników o 1 w dół
{
    for(int i = 0; i < enemyCount; i++) //dla każdego przeciwnika
    {
        enemy.at(i).posY++; //++ bo w y zwiększa się w dół
    }
}

void SpaceInvadersBoard::shoot(sf::Clock &clock, float difficulty)  //strzał
{
    if(clock.getElapsedTime().asSeconds() > difficulty && !bullet.isVisible)    //jeżeli upłynie czas podany jako trudność
    {
        int x = rand() % enemyCount;    //wybiera randomowego przeciwnika
        bullet.posX = enemy.at(x).posX; //ustawia pozycje kuli na x i y przeciwnika
        bullet.posY = enemy.at(x).posY;
        bullet.isVisible = true;        //ustawia widoczność kuli
        clock.restart();    //resetuje zegar dla kuli
    }
}

void SpaceInvadersBoard::moveEnemyBullet(float frameTime)
{
    if(bullet.isVisible)    //jeżeli kula jest widoczna
    {
        bullet.posY = bullet.posY + (speed * frameTime * 5);   //porusza kule
    }
}

float SpaceInvadersBoard::getBulletX() {
    return bullet.posX;
}

float SpaceInvadersBoard::getBulletY() {
    return bullet.posY;
}

void SpaceInvadersBoard::resetBullet()  //resetuje kule
{
    if(bullet.posY > mapHeight)
    {
        bullet.isVisible = false;
        bullet.posX = -5;
    }
}

void SpaceInvadersBoard::update(float frameTimeAsSeconds, sf::Clock &enemyClock, float diff)
{
    moveEnemy(frameTimeAsSeconds);
    turnEnemy();
    shoot(enemyClock, diff);
    moveEnemyBullet(frameTimeAsSeconds);
    resetBullet();
    if(checkIfWon())
    {
        level++;
    }
}

bool SpaceInvadersBoard::checkIfWon()
{
    return enemyAlive <= 0;
}

int SpaceInvadersBoard::getLevel() {
    return level;
}

int SpaceInvadersBoard::getScore() {
    return score;
}



