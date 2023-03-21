#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace pixel
{
  class Assets
  {
  public:
    ~Assets ();
    static Assets *getInstance ();
    void loadTexture (const std::string *path);
    sf::Texture *getTexture (const std::string *path);
    
  private:
    Assets *instance = nullptr;
    Assets () {}
    Assets (Assets const&) = delete;
    Assets& operator= (Assets const&) = delete;
    std::unordered_map<std::string, *sf::Texture> textures ();
  };
}
