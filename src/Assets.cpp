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
        nlohmann::json mu = doc["music"];
        nlohmann::json ft = doc["fonts"];

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
        
        for (auto it = mu.begin (); it != mu.end (); ++it)
        {
            sf::Music *m = new sf::Music ();
            m->openFromFile (it.value ());
            this->music[it.key ()] = m;
        }
        
        for (auto it = ft.begin (); it != ft.end (); ++it)
        {
            sf::Fpnt *f = new sf::Font ();
            f->loadFromFile (it.value ());
            this->music[it.key ()] = f;
        }
    }


    Assets::~Assets ()
    {
        for (auto &it : this->textures)
        {
            delete it.second;
        }
        this->textures.clear ();

        for (auto &it : this->sounds)
        {
            delete it.second->getBuffer ();
            delete it.second;
        }
        this->sounds.clear ();
        
        for (auto &it : this->music)
        {
            delete it.second ();
        }
        this->music.clear ();
        
        for (auto &it : this->fonts)
        {
            delete it.second ();
        }
        this->fonts.clear ();
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


    sf::Music *Assets::getMusic (std::string id)
    {
        if (this->music.find (id) != this->music.end ())
        {
            return this->music[id];
        }
        else
        {
            return nullptr;
        }
    }


    sf::Font *Assets::getFont (std::string id)
    {
        if (this->fonts.find (id) != this->fonts.end ())
        {
            return this->fonts[id];
        }
        else
        {
            return nullptr;
        }
    }
}
