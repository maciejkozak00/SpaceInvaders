//
// Created by macie on 16.06.2021.
//

#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &win) : win(win)
{
    startGame = false;
    setMenu();

    font.loadFromFile("assets/open-sans.ttf");
    startText.setFont(font);
    easyText.setFont(font);
    mediumText.setFont(font);
    hardText.setFont(font);
}

void MainMenu::setMenu()
{
    startButton.setSize(sf::Vector2f(200, 100));
    easyButton.setSize(sf::Vector2f(150, 50));
    mediumButton.setSize(sf::Vector2f(150, 50));
    hardButton.setSize(sf::Vector2f(150, 50));

    startButton.setPosition(100, 300);
    easyButton.setPosition(400, 300);
    mediumButton.setPosition(400, 400);
    hardButton.setPosition(400, 500);

    startButton.setFillColor(sf::Color::White);
    easyButton.setFillColor(sf::Color::White);
    mediumButton.setFillColor(sf::Color::White);
    hardButton.setFillColor(sf::Color::White);

    startButton.setOutlineColor(sf::Color::Green);
    easyButton.setOutlineColor(sf::Color::Red);
    mediumButton.setOutlineColor(sf::Color::Red);
    hardButton.setOutlineColor(sf::Color::Red);

    startButton.setOutlineThickness(5);

    startText.setCharacterSize(50);
    easyText.setCharacterSize(30);
    mediumText.setCharacterSize(30);
    hardText.setCharacterSize(30);

    startText.setPosition(startButton.getPosition());
    easyText.setPosition(easyButton.getPosition());
    mediumText.setPosition(mediumButton.getPosition());
    hardText.setPosition(hardButton.getPosition());

    startText.setString("START");
    easyText.setString("EASY");
    mediumText.setString("MEDIUM");
    hardText.setString("HARD");

    startText.setFillColor(sf::Color::Magenta);
    easyText.setFillColor(sf::Color::Green);
    mediumText.setFillColor(sf::Color::Yellow);
    hardText.setFillColor(sf::Color::Red);

    startText.setOutlineColor(sf::Color::Black);
    easyText.setOutlineColor(sf::Color::Black);
    mediumText.setOutlineColor(sf::Color::Black);
    hardText.setOutlineColor(sf::Color::Black);

    startText.setOutlineThickness(2);
    easyText.setOutlineThickness(2);
    mediumText.setOutlineThickness(2);
    hardText.setOutlineThickness(2);
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(startButton);
    target.draw(easyButton);
    target.draw(mediumButton);
    target.draw(hardButton);

    target.draw(startText);
    target.draw(easyText);
    target.draw(mediumText);
    target.draw(hardText);
}

void MainMenu::updateMenu(float diff)
{
    if(diff == 4.0)
        easyButton.setOutlineThickness(3);
    else
        easyButton.setOutlineThickness(0);

    if(diff == 2.0f)
        mediumButton.setOutlineThickness(3);
    else
        mediumButton.setOutlineThickness(0);
    if(diff == 0.3f)
        hardButton.setOutlineThickness(3);
    else
        hardButton.setOutlineThickness(0);
}

void MainMenu::handleEvent(sf::Event &event, float &diff)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(event.mouseButton.x >= startButton.getPosition().x &&
            event.mouseButton.x < startButton.getPosition().x + startButton.getSize().x &&
            event.mouseButton.y > startButton.getPosition().y &&
            event.mouseButton.y < startButton.getPosition().y + startButton.getSize().y)
            {
                startGame = true;
            }
            if(event.mouseButton.x >= easyButton.getPosition().x &&
               event.mouseButton.x < easyButton.getPosition().x + easyButton.getSize().x &&
               event.mouseButton.y > easyButton.getPosition().y &&
               event.mouseButton.y < easyButton.getPosition().y + easyButton.getSize().y)
            {
                diff = 4.0f;
            }
            if(event.mouseButton.x >= mediumButton.getPosition().x &&
               event.mouseButton.x < mediumButton.getPosition().x + mediumButton.getSize().x &&
               event.mouseButton.y > mediumButton.getPosition().y &&
               event.mouseButton.y < mediumButton.getPosition().y + mediumButton.getSize().y)
            {
                diff = 2.0f;
            }
            if(event.mouseButton.x >= hardButton.getPosition().x &&
               event.mouseButton.x < hardButton.getPosition().x + hardButton.getSize().x &&
               event.mouseButton.y > hardButton.getPosition().y &&
               event.mouseButton.y < hardButton.getPosition().y + hardButton.getSize().y)
            {
                diff = 0.3f;
            }
        }
    }
}

bool MainMenu::getStartGame() {
    return startGame;
}

void MainMenu::setStartGameFalse()
{
    startGame = false;
}
