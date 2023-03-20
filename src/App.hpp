#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include "ScreenManager.hpp"

namespace pixel
{
    class App
    {
    public:
        App (Screen *x, std::string s, int width, int height);
        ~App ();

    public:
        void start ();

    private:
        ScreenManager *manager = nullptr;
        sf::RenderWindow *window = nullptr;
    };
}