#include"GAMEMENU.h"
#include"GAME.h"

void gamemenu::initWindow1()
{   
   window1.create(VideoMode(700,600), "Kill to score");//(img.getSize().x)*5, (img.getSize().y)*5
   window1.setFramerateLimit(60);     
}

//intializ
gamemenu::gamemenu(void){
    this->initWindow1();
    this->updateevents1();
    this->uploads();
    this->initilize();
    //this->getscore();
    onoff = 0;
     mousetime = 10;
}
gamemenu::~gamemenu(void){
    //std::cout << "challyoo";
}

 void gamemenu::updateevents1(void)
{
    while (window1.pollEvent(this->event1))
    {
        if (mousetime < 10)
            mousetime++;

        if (this->event1.type == Event::Closed)
            window1.close();

        if (this->event1.KeyPressed && this->event1.key.code == Keyboard::Escape)
            window1.close();

        if (isSpriteHover(sprite.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!this->texture.loadFromFile("images/playgame2.png"))
                throw "couldnot load picture";

            texture.setSmooth(true);

            if (Mouse::isButtonPressed(Mouse::Left))
                //if (event1.type == sf::Event::MouseButtonReleased && event1.mouseButton.button == sf::Mouse::Left)
            {
               
                sound.play();
                Game game;
                game.run();
                sound.play();

            }
        }
        else {

            if (!this->texture.loadFromFile("images/playgame.png"))
                throw "couldnot load picture";

            texture.setSmooth(true);
        }

        if (isSpriteHover(sprite2.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!this->texture2.loadFromFile("images/sb2.png"))
                throw "couldnot load picture";
            texture.setSmooth(true);

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound.play();
                RenderWindow window2(sf::VideoMode(900, 500), "SCORE-BOARD");
               

               while (window2.isOpen())
               {
                   sf::Event event;
                   while (window2.pollEvent(event))
                   {
                       if (event.type == sf::Event::Closed)
                           window2.close();

                   }
                   int max = 0;
                   ifstream inf("score");   
                   while (getline(inf, prevscore))
                   {
                      totalscore.push_back(prevscore);
                      
                      a = std::stoi(prevscore);
                      if (a > max)
                          max = a;
                   }                                 
                   scoretext.setFont(font);
                   scoretext.setFillColor(Color::Red);
                   scoretext.setOutlineThickness(2);
                   scoretext.setOutlineColor(Color::Cyan);
                   scoretext.setPosition(0, 30);
                   scoretext.setStyle(sf::Text::Bold);
                   scoretext.setScale(Vector2f(2, 2));
                   scoretext.setString("High score: " + to_string(max) );

                   previous_score.setFont(font);
                   previous_score.setFillColor(Color::Red);
                   previous_score.setOutlineThickness(2);
                   previous_score.setOutlineColor(Color::Cyan);
                   previous_score.setPosition(0, 120);
                   previous_score.setStyle(sf::Text::Bold);
                   previous_score.setScale(Vector2f(2, 2));
                   previous_score.setString("Your  previous score was:  " + totalscore[totalscore.size() - 1]);
                   
                   window2.clear(Color::Red);
                  
                   window2.draw(scoretext);    
                   window2.draw(previous_score);
                   window2.display();
               }
            }
        }
        else {
            if (!this->texture2.loadFromFile("images/sb.png"))
                throw "couldnot load picture";
            texture.setSmooth(true);
        }

        if (isSpriteHover(sprite3.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!this->texture3.loadFromFile("images/exit2.png"))
                throw "couldnot load picture";
            texture.setSmooth(true);
        
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound.play();
                window1.close();

            }
        }
        else
        {
            if (!this->texture3.loadFromFile("images/exit.png"))
                throw "couldnot load picture";
                texture.setSmooth(true);

        }
    }

    if (isSpriteHover(sprite4.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
    {            
        if (event1.type == sf::Event::MouseButtonReleased && event1.mouseButton.button == sf::Mouse::Left && mousetime >= 10) {
            onoff++;          
            mousetime = 0;
            if (onoff % 2 == 0) {
                if (!this->texture4.loadFromFile("images/speakeroff.png"))
                    throw "couldnot load picture";
            texture.setSmooth(true);
            sound2.pause();          
            }

            if (onoff % 2 == 1) {
                if (!this->texture4.loadFromFile("images/speakeron2.png"))
                    throw "couldnot load picture";  

             texture.setSmooth(true);
             sound2.play();
             sound2.setLoop(true);             
            }         
        }
         }
}


void gamemenu::update1()
{
    this->updateevents1();

}
void gamemenu::render1()
{
    window1.clear();
    window1.draw(this->pic);
    window1.draw(this->sprite);
    window1.draw(this->sprite2);
    window1.draw(this->sprite3);
    window1.draw(this->sprite4);
    //window1.draw(this->sprite5);
    window1.display();

}
void gamemenu::run1(void)
{

    while (window1.isOpen())
    {
        this->update1();     
        this->render1();

    }
}

bool gamemenu:: isSpriteHover(sf::FloatRect sprite, Vector2f mp)
{

    mp.x = Mouse::getPosition(window1).x;
    mp.y = Mouse::getPosition(window1).y;

    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}


void gamemenu::uploads() {
    if (!this->tex.loadFromFile("images/GAMEBG.png"))
        throw"unable to load";

    if (!this->menusound.loadFromFile("sounds/menu2.wav"))
        throw"unable to load";

    if (!this->bgsound.loadFromFile("sounds/bgmusic2.wav"))
        throw"unable to load";

    if (!font.loadFromFile("fonts/testfont.ttf"))
        throw"doesn't load font";

    if (!this->texture4.loadFromFile("images/speakeroff.png"))
        throw "couldnot load picture";
    

}
void gamemenu::initilize() {
    //bg image 
    sound.setBuffer(menusound);
    sound2.setBuffer(bgsound);
   
    pic.setTexture(tex);
    pic.setScale(0.6, 0.5);

    sprite.setTexture(texture);
    sprite2.setTexture(texture2);
    sprite3.setTexture(texture3);
    sprite4.setTexture(texture4);
    



    sprite.setScale(0.8, 0.8);
    sprite.setPosition(window1.getSize().x / 2 - 10 - sprite.getGlobalBounds().width / 2, 200);
    

    sprite2.setScale(0.8, 0.8);
    sprite2.setPosition(window1.getSize().x / 2 - 10 - sprite2.getGlobalBounds().width / 2, 200 + sprite.getScale().y + 100);
   
    sprite3.setScale(0.8, 0.8);
    sprite3.setPosition(window1.getSize().x / 2 - 10 - sprite3.getGlobalBounds().width / 2, sprite2.getPosition().y + sprite.getScale().y + 100);

    sprite4.setScale(0.25, 0.25);
    sprite4.setPosition(50, 20);


}




    
  

    
   



   


   

    
