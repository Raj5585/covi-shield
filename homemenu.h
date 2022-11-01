#ifndef HOMEMENU_H
#define  HOMEMENU_H
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class homemenu
{
private:

    RenderWindow window2;
    Event event1;
   

    //game objects
    Texture texture, texture2, texture3, texture4, texture5, tex;
    sf::Sprite sprite, sprite2, sprite3,sprite4, sprite5, pic;
    SoundBuffer menusound;
    Sound sound;
    sf::Vector2f mp;
  
public:
    //functions

    homemenu();
    ~homemenu();
    void initWindow1();
    bool isSpriteHover(sf::FloatRect sprite, Vector2f mp);
    void updateevents1();
    void update1();
    void render1();
    void run1();
    void uploads();
    void initilize();
    //  void getscore();

};
#endif

