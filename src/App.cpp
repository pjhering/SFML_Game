#include <iostream>
#include "App.hpp"
#include "ScreenManager.hpp"

namespace pixel
{
    App::App (Screen *initial, std::string title, int width, int height)
    {
        this->window = new sf::RenderWindow (sf::VideoMode (width, height), title);

        this->manager = new ScreenManager ();
        this->manager->push (initial);
    }

    App::~App ()
    {
        delete this->manager;

        this->window->close ();
        delete this->window;
    }

    void App::start ()
    {
        while (window->isOpen ())
        {
            sf::Event event;
            while (window->pollEvent (event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window->close ();
                    break;

                case sf::Event::KeyPressed:
                    manager->current ()-> keyPressed (event.key.code);
                    break;

                case sf::Event::KeyReleased:
                    manager->current ()-> keyReleased (event.key.code);
                    break;

                case sf::Event::MouseMoved:
                    manager->current ()->mouseMoved (event.mouseMove.x, event.mouseMove.y);
                    break;
                }
            }
            manager->current ()->update (manager, 0.f);
            manager->current ()->render (window);
        }
    }
}
