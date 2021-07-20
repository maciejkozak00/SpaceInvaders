//
// Created by macie on 16.06.2021.
//

#ifndef SPACEINVADERSJH_MAINMENU_H
#define SPACEINVADERSJH_MAINMENU_H

#include "SFML/Graphics.hpp"

class MainMenu : public sf::Drawable
{
    sf::RenderWindow &win;

    sf::RectangleShape startButton;
    sf::Text startText;
    sf::RectangleShape easyButton;
    sf::Text easyText;
    sf::RectangleShape mediumButton;
    sf::Text mediumText;
    sf::RectangleShape hardButton;
    sf::Text hardText;

    sf::Font font;

    bool startGame;

public:
    MainMenu(sf::RenderWindow &win);

    void setMenu();
    void updateMenu(float diff);
    void handleEvent(sf::Event &event, float &diff);

    bool getStartGame();
    void setStartGameFalse();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //SPACEINVADERSJH_MAINMENU_H
