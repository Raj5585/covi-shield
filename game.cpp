#include "GAME.h"
//static functions 
void Game::initWindow()
{
	window = new RenderWindow(VideoMode(1440, 810), "Game");//(img.getSize().x)*5, (img.getSize().y)*5
	window->setFramerateLimit(90);
}
//intializut

Game::Game()
{
	shoottime = 18;
	int score = 0;
	int life = 10;
	int masktime = 500;
	isgameover = false;	
	eshapespawn = 50;
	//std::string newString;

	this->initWindow();
	this->background();
	this->player();
	this->enemy();
	this->Bullet();
	this->mask();
	this->score_bar();
	this->fonts();
	this->gameover();
	this->gamesound();
	


}

Game::~Game()
{
	delete this->window;
	score = 0;
	life = 10;
}

//functions 
void Game::updateevents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->window->close();

		if (this->event.KeyPressed && this->event.key.code == Keyboard::Escape)
			this->window->close();
	}
	
}
void Game::update()
{
	this->updateevents();
}


void Game::render()
{
	this->window->clear(Color::Cyan);
	this->window->draw(this->backgroundshape);
	this->window->draw(this->pshape);
	for (int i = 0; i < eshapes.size(); i++)
	{
		this->window->draw(this->eshapes[i]);
	}
	for (int i = 0; i < bullets.size(); i++)
	{
		this->window->draw(this->bullets[i]);
	}
	for (int i = 0; i < mshapes.size(); i++)
	{
		this->window->draw(this->mshapes[i]);
	}
	this->window->draw(this->scoretext);
	this->window->draw(this->sb);
	if (life == 0) {
		this->window->draw(this->goshape);
		this->window->draw(this->playagaintext);		
	}
	this->window->display();

}


void Game::run()
{
	while (this->window->isOpen())
	{		
		this->update();
		if (life != 0) {
			this->score_bar();
			this->playerupdate();
			this->Bulletupdate();
			this->enemyupdate();
			this->maskupdate();
		}
		if (life == 0 && Keyboard::isKeyPressed(Keyboard::Space)) {
			score = 0;
			life = 10;
			this->score_bar();
			this->playerupdate();
			this->Bulletupdate();
			this->enemyupdate();
			this->maskupdate();
			isgameover = false;
		}			
		this->render();
		if (life == 0 && isgameover == false) {
			std::ofstream outf("score", ios::app);
			outf << score << endl;
			outf.close();
			isgameover = true;
		}
						
	}
	
}
void Game::player() {
	if (!this->playertex.loadFromFile("images/fireman2.png"))
		throw "couldnot load picture";

	   playertex.setSmooth(true);
	this->pshape.setTexture(playertex);
	this->pshape.setScale(Vector2f(0.1f, 0.1f));


}
void Game::gamesound() {

	if (!this->soundB1.loadFromFile("sounds/mask.wav"))
		throw"unable to load";
this->sound1.setBuffer(soundB1);


	/*if (!this->soundB2.loadFromFile("sounds/spray.mp3"))
		throw"unable to load";
this->sound2.setBuffer(soundB2);*/
}
void Game::enemy() {
	if (!this->enemytex.loadFromFile("images/corona2.png"))
		throw "couldnot load picture";
		enemytex.setSmooth(true);
	this->eshape.setTexture(enemytex);
	
	if (!this->enemytex2.loadFromFile("images/corona.png"))
		throw "couldnot load picture";
	enemytex2.setSmooth(true);
	this->eshape2.setTexture(enemytex2);
}

void Game::playerupdate() {

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		pshape.move(0.f, -5.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		pshape.move(0.f, 5.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		pshape.move(-5.f, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		pshape.move(5.f, 0.f);
	}
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		pshape.move(0.f, -5.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		pshape.move(0.f, 5.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		pshape.move(-5.f, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		pshape.move(5.f, 0.f);
	}
	


	if (pshape.getPosition().y > this->window->getSize().y - pshape.getGlobalBounds().height) {
		pshape.setPosition(pshape.getPosition().x, this->window->getSize().y - pshape.getGlobalBounds().height);
	}
	if (pshape.getPosition().y < 0) {
		pshape.setPosition(pshape.getPosition().x, 0);
	}
	if (pshape.getPosition().x > (this->window->getSize().x - pshape.getGlobalBounds().width) / 2) {
		pshape.setPosition((this->window->getSize().x - pshape.getGlobalBounds().width) / 2, pshape.getPosition().y);
	}
	if (pshape.getPosition().x < 0) {
		pshape.setPosition(0, pshape.getPosition().y);
	}	
}

void Game::enemyupdate() {
	eshape.setScale(0.2f, 0.2f);
	eshape2.setScale(0.05f, 0.05f);


	if (eshapespawn < 50)
		eshapespawn++;

	if (eshapespawn >= 50) {		
		eshape.setPosition(this->window->getSize().x - eshape.getGlobalBounds().width, rand() % int(this->window->getSize().y - eshape.getGlobalBounds().height));
		eshape2.setPosition(this->window->getSize().x - eshape2.getGlobalBounds().width, rand() % int(this->window->getSize().y - eshape2.getGlobalBounds().height));
		eshapes.push_back(Sprite(eshape2));
		eshapes.push_back(Sprite(eshape));
		eshapespawn = 0;

	}
	for (int i = 0; i < eshapes.size(); i++) {

		if (score <= 10)
			eshapes[i].move(-7.f, 0.f);

		if (score > 10 && score < 20)
			eshapes[i].move(-8.f, 0.f);

		 if (score >= 20 && score < 30)
			eshapes[i].move(-10.f, 0.f);

		 if (score >= 30)
			eshapes[i].move(-12.f, 0.f);
		

		if (eshapes[i].getPosition().x <= 0) {
			eshapes.erase(eshapes.begin() + i);
			//	if(life >0)
				   life--;
		}

		if (eshapes[i].getGlobalBounds().intersects(pshape.getGlobalBounds())) {
			if (life > 0)
				life--;
			eshapes.erase(eshapes.begin() + i);
			break;
			//player damage
		}
	}
}

void Game::Bullet() {
	if (!this->bullettex.loadFromFile("images/sanitizer.png"))
		throw "couldnot load picture";
	bullettex.setSmooth(true);
	bshape.setTexture(bullettex);

}

void Game::Bulletupdate() {
	bshape.setScale(0.03f, 0.03f);

	if (shoottime < 18)
		shoottime++;

	if (Mouse::isButtonPressed(Mouse::Left) && shoottime >= 18)
	{
		this->sound2.play();
		bshape.setPosition(pshape.getPosition().x, pshape.getPosition().y + 50);
		bullets.push_back(Sprite(bshape));
		shoottime = 0;
	}

	for (size_t i = 0; i < bullets.size();i++)
	{
		//move bullets
		bullets[i].move(10.f, 0.f);
		


		if (bullets[i].getPosition().x >= this->window->getSize().x - 100) {
			bullets.erase(bullets.begin() + i);
			break;
		}
		//collision between bullet and enemy
		for (int k = 0; k < eshapes.size();k++)
		{
			if (bullets[i].getGlobalBounds().intersects(eshapes[k].getGlobalBounds()))
			{
				eshapes.erase(eshapes.begin() + k);
				bullets.erase(bullets.begin() + i);
				score++;	
				break;
			}
		}
	}
}


void Game::mask() {

	if (!this->mtex.loadFromFile("images/raj's mask.png"))
		throw "couldnot load picture";
	mshape.setTexture(mtex);
}


void Game::maskupdate() {

	mshape.setScale(Vector2f(0.08f, 0.08f));

	if (masktime < 500)
		masktime++;

	if (masktime >= 500) {
		mshape.setPosition(this->window->getSize().x, rand() % int(this->window->getSize().y - mshape.getGlobalBounds().height));
		mshapes.push_back(Sprite(mshape));
		masktime = 0;
	}
	for (int i = 0; i < mshapes.size(); i++) {
		mshapes[i].move(-5, 0);

		if (mshapes[i].getPosition().x <= 0) {
			mshapes.erase(mshapes.begin() + i);
		}
	}
	for (int i = 0; i < mshapes.size();i++) {
		if (pshape.getGlobalBounds().intersects(mshapes[i].getGlobalBounds()))
		{
			if (life < 10)
				life++;
			mshapes.erase(mshapes.begin() + i);
			this->sound1.play();
		}
	}
}

void Game::fonts() {
	if (!this->font.loadFromFile("fonts/testfont.ttf"))
		throw"doesn't load font";
}

void Game::score_bar() {
	//lifebar
	sb.setFillColor(Color::Green);
	sb.setOutlineThickness(2);
	sb.setOutlineColor(Color::Cyan);
	sb.setPosition(this->window->getSize().x / 2, 10);
	sb.setSize(Vector2f(life * 20, 20));

	if (sb.getSize().x <= 100)
		sb.setFillColor(Color::Red);

	if (sb.getSize().x > 100)
		sb.setFillColor(Color::Green);


	scoretext.setFont(font);
	scoretext.setFillColor(Color::Red);
	scoretext.setOutlineThickness(2);
	scoretext.setOutlineColor(Color::Cyan);
	scoretext.setPosition(this->window->getSize().x - 300, 10);
	scoretext.setStyle(sf::Text::Bold);
	scoretext.setScale(Vector2f(2, 2));
	std::stringstream ss;
	ss << score << std::endl;
	std::string newString = ss.str();
	scoretext.setString("score:" + newString);

	playagaintext.setFont(font);
	playagaintext.setFillColor(Color::Cyan);
	playagaintext.setOutlineThickness(2);
	playagaintext.setOutlineColor(Color::Red);
	playagaintext.setPosition(this->backgroundshape.getPosition().x + 300, this->backgroundshape.getPosition().y + 520);
	playagaintext.setStyle(sf::Text::Bold);
	playagaintext.setScale(Vector2f(2, 2));
	playagaintext.setString("Enter space to play again");	
}

void Game::gameover() {
	if (!this->gotex.loadFromFile("images/gameover.png"))
		throw "couldnot load picture";

	this->goshape.setTexture(gotex);
	goshape.setPosition(this->window->getSize().x / 2 - (goshape.getGlobalBounds().width) / 2, this->window->getSize().y / 2 - (goshape.getGlobalBounds().height) / 2);
		
}

void Game::background() {

	if (!this->img.loadFromFile("images/bg2.png"))
		throw"unable to load";
	this->backgroundtex.loadFromImage(img);
	this->backgroundshape.setTexture(backgroundtex);
	backgroundshape.setScale(Vector2f(0.75f,0.75f));
}
