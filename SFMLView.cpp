//
// Created by macie on 31.05.2021.
//

#include "SFMLView.h"

SFMLView::SFMLView(sf::RenderWindow &win, SpaceShip &player, SpaceInvadersBoard &board) : win(win), player(player), board(board)
{
    loadTextures();
    setBlockSize(); //ustawia rozmiar bloku
    setScreen();
}

void SFMLView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(spaceShip); //rysuje statek
    for(int i = 0; i < board.getEnemyCount(); i++)  //dla każdego przeciwnika
    {
        target.draw(enemy.at(i));   //rysuje przeciwnika
    }
    target.draw(bullet);    //rysuje kule gracza
    target.draw(enemyBullet);   //rysuje kule przeciwnika
}

void SFMLView::setScreen()
{
    spaceShip.setSize(sf::Vector2f(blockSize.x * 2, blockSize.y * 2));   //rozmiar gracza

    enemy.resize(board.getEnemyCount());
    for(int i = 0; i < board.getEnemyCount(); i++)
    {
        enemy.at(i).setSize(blockSize);
        enemy.at(i).setTexture(&enemyTexture);
    }
    bullet.setSize(sf::Vector2f(blockSize.x / 3, blockSize. y / 3));
    bullet.setFillColor(sf::Color::Yellow);
    enemyBullet.setSize(sf::Vector2f(blockSize.x / 3, blockSize.y / 3));
    enemyBullet.setFillColor(sf::Color::Cyan);
}

void SFMLView::updateScreen()
{
    if(!player.getIsMoving())   //jeżeli gracz się porusza
    {
        spaceShip.setTexture(&spaceShipTexture);    //ustawia teksture na spaceShipeTexture załadowaną z pliku (wskaźnik)
    }
    else
    {
        spaceShip.setTexture(&spaceShipMovingTexture);
    }

    spaceShip.setPosition(player.getSpacePos());
    for(int i = 0; i < board.getEnemyCount(); i++)
    {
        if(board.isEnemyAlive(i))
        {
            enemy.at(i).setPosition(board.getEnemyPos(i).x * blockSize.x, board.getEnemyPos(i).y * blockSize.y);
        }
        else
        {
            enemy.at(i).setPosition(-100, -100);
        }
    }
    bullet.setPosition(player.getBulletPos());
    enemyBullet.setPosition(board.getBulletX() * blockSize.x, board.getBulletY() * blockSize.y);

}

void SFMLView::setBlockSize()
{
    blockSize.x = float(win.getSize().x) / float(board.getMapWidth());
    blockSize.y = float(win.getSize().y) / float(board.getMapHeight());
}

void SFMLView::checkIfEnemyKilled()
{
    for(int i = 0; i < enemy.size(); i++)
    {
        if(enemy.at(i).getGlobalBounds().intersects(bullet.getGlobalBounds()))
        {
            board.killEnemy(i);
            player.resetBullet();
        }
    }
}

void SFMLView::loadTextures()
{
    spaceShipTexture.loadFromFile("assets/spaceship.png");
    spaceShipMovingTexture.loadFromFile("assets/spaceshipflying.png");
    enemyTexture.loadFromFile("assets/enemy.png");
}

bool SFMLView::checkCollision() {
    for(int i = 0; i < board.getEnemyCount(); i++)
    {
        if(enemy.at(i).getGlobalBounds().intersects(spaceShip.getGlobalBounds()) && board.isEnemyAlive(i))
        {
            return true;
        }
    }
    return false;
}

void SFMLView::update() {
    updateScreen();
    checkIfEnemyKilled();
}

bool SFMLView::checkIfKilled() {
    return enemyBullet.getGlobalBounds().intersects(spaceShip.getGlobalBounds());
}

bool SFMLView::checkIfEscaped() {
    for(int i = 0; i < enemy.size(); i++)
    {
        if(board.isEnemyAlive(i) && enemy.at(i).getPosition().y > win.getSize().y - (4 * blockSize.y))
        {
            return true;
        }
    }
    return false;
}

