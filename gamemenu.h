#ifndef GAMEMENU_H
#define GAMEMENU_H
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>
#include<string>
using namespace sf;
using namespace std;
class gamemenu
{
private:

    RenderWindow window1;
    Event event1;
    void initWindow1();

    //game objects
    Texture texture, texture2, texture3,texture4, tex;
    sf::Sprite sprite, sprite2, sprite3, sprite4, pic;
    SoundBuffer menusound , bgsound;
    Sound sound , sound2;
    sf::Vector2f mp;
     int onoff,a, mousetime;
    Font font;
    Text scoretext, previous_score;
    std::vector <string> totalscore;
    string prevscore;
public:
    //functions
    
    gamemenu(void);
    ~gamemenu(void);
    bool isSpriteHover(sf::FloatRect sprite, Vector2f mp);
    void updateevents1(void);
    void update1(void);
    void render1(void);
    void run1(void);
    void uploads(void);
    void initilize(void);

};
#endif

