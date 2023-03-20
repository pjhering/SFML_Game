#include <iostream>
#include "SplashScreen.hpp"
#include "Screen.hpp"

namespace pixel
{
    SplashScreen::SplashScreen ()
    {
    }

    SplashScreen::~SplashScreen ()
    {
    }

    void SplashScreen::activate ()
    {
        this->escapeKeyPressed = false;
    }

    void SplashScreen::deactivate ()
    {
    }

    void SplashScreen::update (ScreenManager *manager, float dt)
    {
        if (this->escapeKeyPressed)
        {
            manager->replace (new GameScreen ());
        }
    }

    void SplashScreen::render (sf::RenderWindow *window)
    {
        window->clear (sf::Color::Red);
        window->display ();
    }

    void SplashScreen::keyPressed (sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::Key::Escape:
            this->escapeKeyPressed = true;
            break;
        }
    }

    void SplashScreen::keyReleased (sf::Keyboard::Key key)
    {
    }

    void SplashScreen::mouseMoved (int x, int y)
    {
    }

    void SplashScreen::mouseButtonPressed (sf::Mouse::Button button, int x, int y)
    {
    }

    void SplashScreen::mouseButtonReleased (sf::Mouse::Button button, int x, int y)
    {
    }
}