//
// Created by macie on 17.06.2021.
//

#ifndef SPACEINVADERSJH_GAMEOVER_H
#define SPACEINVADERSJH_GAMEOVER_H

#include "SFML/Graphics.hpp"
#include "SpaceInvadersBoard.h"
#include "SFMLView.h"

class GameOver : public sf::Drawable
{
    sf::RenderWindow &win;
    SpaceInvadersBoard &board;
    SFMLView &view;

    sf::Text continueText;
    sf::Text scoreText;
    sf::Text levelText;

    sf::Font font;

public:
    GameOver(sf::RenderWindow &win, SpaceInvadersBoard &board, SFMLView &view);
    void update();  //wykonuje się co klatke

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void handleEvent(sf::Event &event, int &scene);

};


#endif //SPACEINVADERSJH_GAMEOVER_H
