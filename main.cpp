#include <iostream>
#include "SpaceInvadersBoard.h"
#include "SpaceShip.h"
#include "SFMLView.h"
#include "MainMenu.h"
#include "GameOver.h"

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "SPACE INVADERS", sf::Style::Close);
    SpaceShip player(win);
    SpaceInvadersBoard board(player, win);
    SFMLView view(win, player, board);
    MainMenu menu(win);
    GameOver go(win, board, view);

    sf::Clock clock;
    sf::Clock enemyClock;
    float diff = 0.3f;
    int scene = 0;
    while (win.isOpen())
    {
        float frameTimeAsSeconds = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event{};
        if(win.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                win.close();
            }
            if(scene == 0)
            {
                menu.handleEvent(event, diff);
                if(menu.getStartGame())
                {
                    player.placeSpaceship(750, 800);
                    board.prepareEnemy();
                    board.resetBullet();
                    scene++;
                    menu.setStartGameFalse();
                }
            }
            if(scene == 1)
            {
                player.checkIfShoot(event);
            }
            if(scene == 2)
            {
                go.handleEvent(event, scene);
            }
        }
        win.clear();
        if(scene == 0)
        {
            menu.updateMenu(diff);
            win.draw(menu);
        }
        if(scene == 1)
        {
            player.update(frameTimeAsSeconds);
            view.update();
            board.update(frameTimeAsSeconds, enemyClock, diff);
            if(view.checkCollision() || view.checkIfKilled() || view.checkIfEscaped() || board.checkIfWon())
            {
                board.resetBullet();
                scene++;
            }
            win.draw(view);
        }
        if(scene == 2)
        {
            go.update();
            win.draw(go);
        }
        board.moveEnemyBullet(frameTimeAsSeconds);
        win.display();
    }
}
