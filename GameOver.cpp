//
// Created by macie on 17.06.2021.
//

#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow &win, SpaceInvadersBoard &board, SFMLView &view) :win(win), board(board), view(view)
{
    font.loadFromFile("assets/open-sans.ttf");
    continueText.setFont(font);
    scoreText.setFont(font);
    levelText.setFont(font);
}

void GameOver::update()
{
    continueText.setString("Press Space To continue");
    scoreText.setString("Score:" + std::to_string(board.getScore()));
    levelText.setString("Level:" + std::to_string(board.getLevel()));

    continueText.setPosition(100, 50);
    scoreText.setPosition(200, 300);
    levelText.setPosition(200, 400);
}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(continueText);
    target.draw(scoreText);
    target.draw(levelText);
}

void GameOver::handleEvent(sf::Event &event, int &scene)
{
    if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == sf::Keyboard::Space)
        {
            scene = 0;
        }
    }
}
