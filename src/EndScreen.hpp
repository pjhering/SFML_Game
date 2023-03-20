#pragma once
#include "Screen.hpp"
#include "ScreenManager.hpp"
#include "SplashScreen.hpp"

namespace pixel
{
    class EndScreen : public Screen
    {
    public:
        EndScreen ();
        ~EndScreen ();

    public:
        void activate () override;
        void deactivate () override;
        void update (ScreenManager *manager, float dt) override;
        void render (sf::RenderWindow *window) override;
        void keyPressed (sf::Keyboard::Key key) override;
        void keyReleased (sf::Keyboard::Key key) override;
        void mouseMoved (int x, int y) override;
        void mouseButtonPressed (sf::Mouse::Button button, int x, int y) override;
        void mouseButtonReleased (sf::Mouse::Button button, int x, int y) override;

    private:
        bool escapeKeyPressed;
    };
}