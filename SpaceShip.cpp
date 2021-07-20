//
// Created by macie on 30.05.2021.
//

#include "SpaceShip.h"

SpaceShip::SpaceShip(sf::RenderWindow &win) : win(win)
{
    speed = 400;    //inicjujemy prędkość na 400

    bullet.visible = false; //ustawiamy na start że kula nie jest widoczna
    isMoving = false;

    placeSpaceship(200, 50 );

}

void SpaceShip::placeSpaceship(float x, float y)
{
    spacePos.x = x;    //ustawiamy statek w przekazanym x
    spacePos.y = y;     //ustawiamy statek w przekazanym y
}

sf::Vector2f SpaceShip::getSpacePos()
{
    return spacePos;
}

void SpaceShip::moveSpaceship(float frameTime)
{
    isMoving = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && spacePos.y > 0) //jeżeli jest przyciśnięty przycisk W na klawiaturze
    {   //pozycja statku zmienia się na pozycje statku - prękość * frameTime, frameTime powoduje że statek równo się porusza
        spacePos.y = spacePos.y - (float(speed) * frameTime);
        isMoving = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && spacePos.y < win.getSize().y - 10)
    {
        spacePos.y = spacePos.y + (float(speed) * frameTime);
        isMoving = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spacePos.x > 0)
    {
        spacePos.x = spacePos.x - (float(speed) * frameTime);
        isMoving = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && spacePos.x < win.getSize().x - 10)
    {
        spacePos.x = spacePos.x + (float(speed) * frameTime);
        isMoving = true;
    }
}

void SpaceShip::resetBullet()
{
    bullet.x = -20; //ustawia kule poza widoczną strefą
    bullet.y = -20;
    bullet.visible = false; //ustawia widzialność kuli na fałsz
}

bool SpaceShip::checkIfBulletVisible()
{
    return bullet.y > 0;    //sprawdza czy kula jest już poza ekranem
}

void SpaceShip::shoot()
{
    bullet.x = spacePos.x + 10; //ustawia kule na środku statku
    bullet.y = spacePos.y;
    bullet.visible = true;  //kula jest widoczna
}

void SpaceShip::moveBullet(float frameTime)
{
    if(bullet.visible)  //jeżeli kula jest widoczna
    {
        bullet.y = bullet.y - (float(speed) * frameTime * 10);  //kula się porusza
    }
    if(!checkIfBulletVisible()) //jeżeli kula wyleci poza ekran
    {
        resetBullet();  //resetuje kule
    }
}

sf::Vector2f SpaceShip::getBulletPos() {
    return sf::Vector2f(bullet.x, bullet.y);    //zwracca pozycje kuli
}

bool SpaceShip::getIsMoving()
{
    return isMoving;
}

void SpaceShip::update(float frameTimeAsSeconds)
{
    moveSpaceship(frameTimeAsSeconds);
    moveBullet(frameTimeAsSeconds);
}

void SpaceShip::checkIfShoot(sf::Event &event)
{
    if(event.type == sf::Event::KeyReleased && !checkIfBulletVisible())
    {
        if(event.key.code == sf::Keyboard::Space)
        {
            shoot();
        }
    }
}


