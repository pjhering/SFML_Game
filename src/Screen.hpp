#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenManager.hpp"

namespace pixel
{
    class ScreenManager;

    class Screen
    {
    public:
        Screen ();
        ~Screen ();

    public:
        virtual void activate () = 0;
        virtual void deactivate () = 0;
        virtual void update (ScreenManager *manager, float dt) = 0;
        virtual void render (sf::RenderWindow *window) = 0;
        virtual void keyPressed (sf::Keyboard::Key key) = 0;
        virtual void keyReleased (sf::Keyboard::Key key) = 0;
        virtual void mouseMoved (int x, int y) = 0;
        virtual void mouseButtonPressed (sf::Mouse::Button button, int x, int y) = 0;
        virtual void mouseButtonReleased (sf::Mouse::Button button, int x, int y) = 0;
    };
}