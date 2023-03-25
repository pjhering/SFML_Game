#include "Assets.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace pixel
{
    Assets::Assets (std::string path)
    {
        std::ifstream in;
        std::string data;
        std::ostringstream oss;

        in.open (path);
        oss << in.rdbuf ();
        data = oss.str ();
        in.close ();

        nlohmann::json doc = nlohmann::json::parse (data);
        nlohmann::json tx = doc["textures"];
        nlohmann::json sn = doc["sounds"];

        for (auto it = tx.begin (); it != tx.end (); ++it)
        {
            sf::Texture *t = new sf::Texture ();
            t->loadFromFile (it.value ());
            this->textures[it.key ()] = t;
        }

        for (auto it = sn.begin (); it != sn.end (); ++it)
        {
            sf::SoundBuffer sb;
            sb.loadFromFile (it.value ());

            sf::Sound *s = new sf::Sound (sb);

            this->sounds[it.key ()] = s;
        }
    }


    Assets::~Assets ()
    {
        for (auto &it : this->textures)
        {
            delete it.second;
        }

        for (auto &it : this->sounds)
        {
            delete it.second->getBuffer ();
            delete it.second;
        }
    }


    sf::Texture *Assets::getTexture (std::string id)
    {
        if (this->textures.find (id) != this->textures.end ())
        {
            return this->textures[id];
        }
        else
        {
            return nullptr;
        }
    }


    sf::Sound *Assets::getSound (std::string id)
    {
        if (this->sounds.find (id) != this->sounds.end ())
        {
            return this->sounds[id];
        }
        else
        {
            return nullptr;
        }
    }
}
