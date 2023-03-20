#include <iostream>
#include "EndScreen.hpp"

namespace pixel
{
    EndScreen::EndScreen ()
    {
    }

    EndScreen::~EndScreen ()
    {
    }

    void EndScreen::activate ()
    {
    }

    void EndScreen::deactivate ()
    {
    }

    void EndScreen::update (ScreenManager *manager, float dt)
    {
        if (this->escapeKeyPressed)
        {
            manager->replace (new SplashScreen ());
        }
    }

    void EndScreen::render (sf::RenderWindow *window)
    {
        window->clear (sf::Color::Blue);
        window->display ();
    }

    void EndScreen::keyPressed (sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::Key::Escape:
            this->escapeKeyPressed = true;
            break;
        }
    }

    void EndScreen::keyReleased (sf::Keyboard::Key key)
    {
    }

    void EndScreen::mouseMoved (int x, int y)
    {
    }

    void EndScreen::mouseButtonPressed (sf::Mouse::Button button, int x, int y)
    {
    }

    void EndScreen::mouseButtonReleased (sf::Mouse::Button button, int x, int y)
    {
    }
}