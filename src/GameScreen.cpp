#include <iostream>
#include "GameScreen.hpp"

namespace pixel
{
    GameScreen::GameScreen ()
    {
    }

    GameScreen::~GameScreen ()
    {
    }

    void GameScreen::activate ()
    {
        this->escapeKeyPressed = false;
    }

    void GameScreen::deactivate ()
    {
    }

    void GameScreen::update (ScreenManager *manager, float dt)
    {
        if (this->escapeKeyPressed)
        {
            manager->replace (new EndScreen ());
        }
    }

    void GameScreen::render (sf::RenderWindow *window)
    {
        window->clear (sf::Color::Green);
        window->display ();
    }

    void GameScreen::keyPressed (sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::Key::Escape:
            this->escapeKeyPressed = true;
            break;
        }
    }

    void GameScreen::keyReleased (sf::Keyboard::Key key)
    {
    }

    void GameScreen::mouseMoved (int x, int y)
    {
    }

    void GameScreen::mouseButtonPressed (sf::Mouse::Button button, int x, int y)
    {
    }

    void GameScreen::mouseButtonReleased (sf::Mouse::Button button, int x, int y)
    {
    }
}