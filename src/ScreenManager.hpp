#pragma once
#include <queue>
#include "Screen.hpp"

namespace pixel
{
    class Screen;

    class ScreenManager
    {
    public:
        ScreenManager ();
        ~ScreenManager ();

    public:
        Screen *current ();
        void push (Screen *screen);
        void replace (Screen *screen);
        void pop ();

    private:
        std::queue<Screen *> stack;
    };
}