#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace pixel
{
  class Assets
  {
  public:
    Assets ();
    ~Assets ();
    void loadTexture (const std::string *path);
    sf::Texture *getTexture (const std::string *path);
    
  private:
    std::unordered_map<std::string, *sf::Texture> textures ();
  };
}
