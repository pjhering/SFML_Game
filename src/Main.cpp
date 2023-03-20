#include <iostream>
#include "App.hpp"
#include "SplashScreen.hpp"

using namespace pixel;

int main ()
{
    SplashScreen *initial = new SplashScreen ();
    App app(initial, "Hello, SFML", 800, 450);
    app.start ();

    return 0;
}