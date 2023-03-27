#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Audio.hpp>
#include <SFML/Font.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Music.hpp>

namespace pixel
{
    class Assets
    {
    public:
        Assets (std::string);
        ~Assets ();
        sf::Texture *getTexture (std::string id);
        sf::Sound *getSound (std::string id);
        sf::Music *getMusic (std::string id);
        sf::Font *getFont (std::string id);

    private:
        std::unordered_map<std::string, sf::Texture *> textures;
        std::unordered_map<std::string, sf::Sound *> sounds;
        std::unordered_map<std::string, sf::Music *> music;
        std::unordered_map<std::string, sf::Font *> fonts;
    };
}
