#include "Assets.hpp"

namespace pixel
{
    Assets::Assets ()
    {
    }
    
    Assets::~Assets ()
    {
      for (const auto &pair : this.textures)
      {
        delete pair->second;
      }
      this.textures.clear ();
    }
  
    void Assets::loadTexture (const std::string *path)
    {
      if (this.textures.find (path) != this.textures.end ())
      {
        sf::Texture *t = new Texture ();
        t->loadFromFile (path);
        this.textures[path] = t;
      }
    }
  
    sf::Texture *Assets::getTexture (const std::string *path)
    {
      return this.textures[path];
    }
}
