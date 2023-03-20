#include <iostream>
#include "ScreenManager.hpp"

namespace pixel
{
    ScreenManager::ScreenManager ()
    {
    }

    ScreenManager::~ScreenManager ()
    {
        while (!stack.empty ())
        {
            Screen *screen = stack.front ();
            screen->deactivate ();
            stack.pop ();

            delete screen;
        }
    }

    Screen *ScreenManager::current ()
    {
        return stack.front ();
    }

    void ScreenManager::push (Screen *screen)
    {
        if (!stack.empty ())
        {
            stack.front ()->deactivate ();
        }

        screen->activate ();
        stack.push (screen);
    }

    void ScreenManager::replace (Screen *screen)
    {
        if (!stack.empty ())
        {
            Screen *old = stack.front ();
            old->deactivate ();
            stack.pop ();

            delete old;
        }

        screen->activate ();
        stack.push (screen);
    }

    void ScreenManager::pop ()
    {
        if (!stack.empty ())
        {
            Screen *old = stack.front ();
            old->deactivate ();
            stack.pop ();

            delete old;
        }
    }
}