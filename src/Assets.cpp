#include "Assets.hpp"

namespace pixel
{
    Assets::~Assets ()
    {
      for (const auto &pair : this.textures)
      {
        delete pair->second;
      }
      this.textures.clear ();
    }
  
    Assets *Assets::getInstance ()
    {
      if (this->instance == nullptr)
      {
        this->instance = new Assets ();
      }
      return this->instance;
    }
  
    void Assets::loadTexture (const std::string *path)
    {
      if (!this.textures.contains (path))
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
