#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace pixel
{
    class Assets
    {
    public:
        Assets (std::string);
        ~Assets ();
        sf::Texture *getTexture (std::string id);
        sf::Sound *getSound (std::string id);

    private:
        std::unordered_map<std::string, sf::Texture *> textures;
        std::unordered_map<std::string, sf::Sound *> sounds;
    };
}
