#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
#include<fstream>
using namespace sf;
using namespace std;
class Game
{
private:

	RenderWindow* window;
	Event event;
	
	//game objects
	SoundBuffer soundB1, soundB2;
	Sound sound1, sound2;
	Image img;
	Sprite pshape, eshape, eshape2, bshape, mshape, goshape, backgroundshape;
	Texture playertex, enemytex, enemytex2, bullettex, mtex, gotex, backgroundtex;
	std::vector<Sprite> eshapes, mshapes;
	std::vector<Sprite> bullets;
	RectangleShape sb;
	Font font;
	Text scoretext, playagaintext;
	int eshapespawn;
	int shoottime;
	int score;
	int life = 10;
	int masktime;
	int largest_element;
	//std::string newString;
	bool isgameover;
	int a;
public:
	Game();
	~Game();
	//functions
	void initWindow();
	void updateevents();
	void update();
	void player();
	void enemy();
	void playerupdate();
	void enemyupdate();
	void Bullet();
	void Bulletupdate();
	void run();
	void render();
	void fonts();
	void score_bar();
	void mask();
	void maskupdate();
	void gameover();
	void background();
	void gamesound();
	//void filescore();
	
};
#endif

