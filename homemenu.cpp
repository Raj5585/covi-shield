#include"HOMEMENU.h"
#include"GAMEMENU.h"
#include"sourc.h"
#include"strings.h"
#include"covid.h"
void homemenu::initWindow1()
{
    window2.create(VideoMode(900,900), "Kill to score");//(img.getSize().x)*5, (img.getSize().y)*5
    window2.setFramerateLimit(60);
}

//intializ
homemenu::homemenu() {
    this->initWindow1();
    this->updateevents1();
    this->uploads();
    this->initilize();
}
homemenu::~homemenu() {
    //std::cout << "challyoo";
}

void homemenu::updateevents1()
{


    while (window2.pollEvent(this->event1))
    {


        if (this->event1.type == Event::Closed)
            window2.close();

        if (this->event1.KeyPressed && this->event1.key.code == Keyboard::Escape)
            window2.close();
        if (isSpriteHover(sprite.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!texture.loadFromFile("images/covid2.png"))
                throw"unable to load";
            texture.setSmooth(true);

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound.play();
                system("cls");
                cout << "\n\n\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
                    << endl;
                cout << "\t\t\n\n\n Powered By:- COVID HELP AND RESCUE " << endl;
                cout << "\t\t\n\n\n\t\t\tHEY WELCOME TO THE SYSTEM PRESS ANY THING TO CONTINUE..." << endl;
                _getch();
                system("cls");
                login_ask();               
            }
        }
        else {
            if (!texture.loadFromFile("images/covac.png"))
                throw"unable to load";
            texture.setSmooth(true);
        }

        if (isSpriteHover(sprite2.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!texture2.loadFromFile("images/bot2.png"))
                throw"unable to load";
            texture.setSmooth(true);

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound.play();
                system("cls");
               
                bot symp;
                prob test;
                random hi;
                num_game start;
                // guessdis disease;
                const int max_resp = 3;
                string input;

                cout << "Welcome to COVID  Friendly Bot" << endl;
                Sleep(1000);
                cout << "I am here to answer your queries on corona and also you can talk to me" << endl;
                Sleep(1000);
                cout << "I hope we can have a great time" << endl;
                system("cls");
                cout << "\t\t\t\t\t";
                cout << "Helper-BOt {Enter exit to close program.}" << endl;
                cout << "\t\t\t\t\t\t\t";

                while (1) {
                    // string input;
                    getline(cin, input);
                    int len = input.length();

                    //conversion to uppercase to match with the keywords
                    for (int i = 0; i <= len; i++) {
                        if (input[i] >= 97 && input[i] <= 122) {
                            input[i] = input[i] - 32;
                        }
                    }

                    //time for comparing the keywords between them
                    if (input.find("HI") != string::npos) {
                        hi.hi_replies();
                        Sleep(1000);
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("HELLO") != string::npos) {
                        hi.hi_replies();
                        Sleep(1000);
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("THANK") != string::npos) {
                        cout << "IT'S MY PLEASURE TO HELP YOU." << endl;
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("WHO ARE YOU") != string::npos) {
                        hi.who_replies();                   
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("WHAT ARE YOU") != string::npos) {
                        hi.what_replies();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("INTELLIGENT") != string::npos) {
                        hi.intelligence();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("SICK") != string::npos) {
                        hi.health();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("SYMPTOMS") != string::npos) {
                        cout << "symptoms is ready" << endl;
                        symp.symptoms();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("PREVENT") != string::npos) {
                        cout << "\t\t\t\t\tprevention is ready" << endl;
                        symp.treatment();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("HOSPITAL") != string::npos) {
                        cout << "\t\t\tGoogle map is opening showing nearby hospitals In your default Browser>>>>" << endl;
                        Sleep(1500);
                        string map = "start https://www.google.com/maps/@27.6922368,85.344256,13z";
                        system(map.c_str());                
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                      
                    if (input.find("PROBABILITY") != string::npos || input.find("TEST") != string::npos
                        || input.find("CHECK") != string::npos) {
                        test.infection_prob();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("GAME") != string::npos) {
                        start.play_game();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("ACTIVITIES") != string::npos) {
                        hi.activities();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                    if (input.find("MANUAL") != string::npos) {
                        hi.guidelines();
                        cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                    }
                     if (input.find("BORE")!= string::npos){
                         cout << "\t\t\tWHAT CAN I DO TO ENTERTAIN YOU?[PLAY GMAE OR LISTEN TO MUSIC]" << endl;
                        // cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                     }
                     if (input.find("MUSIC") != string::npos || input.find("SONG") != string::npos) {
                         cout << "\t\t\t\t\tLOADING>>>>>>>>>>>" << endl;
                         Sleep(1000);
                         string map = "start https://www.youtube.com/";
                        string map2 = map + "rick and roll";
                         system(map2.c_str());
                         //cout << "\t\t\t\t\t\tHOW CAN I HELP YOU?" << endl;
                     }
                    if (input.find("BYE") != string::npos || input.find("EXIT") != string::npos) {
                        cout << "\t\t\tNice knowing you\T HOPE TO SEE YOU SOON." << endl
                            <<"\t\t\tSTAY SAFE, STAY HOME!!";
                        break;
                    }

                };


            }

        }
        else {
            if (!texture2.loadFromFile("images/bot.png"))
                throw"unable to load";
            texture.setSmooth(true);
        }
        if (isSpriteHover(sprite3.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!texture3.loadFromFile("images/game2.png"))
                throw"unable to load";
            texture.setSmooth(true);

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound.play();
                gamemenu menu;
                menu.run1();
            }
        }
        else {
            if (!texture3.loadFromFile("images/game5.png"))
                throw"unable to load";
            texture.setSmooth(true);
        }
        if (isSpriteHover(sprite4.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!texture4.loadFromFile("images/aboutus2.png"))
                throw"unable to load";
            texture.setSmooth(true);

            if (Mouse::isButtonPressed(Mouse::Left))
            {
               //cout<<arjalk j
            }
        }
        else {
            if (!texture4.loadFromFile("images/aboutus.png"))
                throw"unable to load";
            texture.setSmooth(true);
        }


        if (isSpriteHover(sprite5.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
        {
            if (!texture5.loadFromFile("images/hexit2.png"))
                throw"unable to load";
            texture.setSmooth(true);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound.play();
                window2.close();
            }
        }
        else {
            if (!texture5.loadFromFile("images/hexit.png"))
                throw"unable to load";
         texture.setSmooth(true);
        }
    }
}

void homemenu::update1()
{
    this->updateevents1();

}
void homemenu::render1()
{
    window2.clear();
        //Draw  
        window2.draw(pic);
        window2.draw(sprite);
        window2.draw(sprite2);
        window2.draw(sprite3);
        window2.draw(sprite4);
        window2.draw(sprite5);
        window2.display();
   
}
void homemenu::run1()
{

    while (window2.isOpen())
    {
        this->update1();
        this->render1();

    }
}

bool homemenu::isSpriteHover(sf::FloatRect sprite, Vector2f mp)
{

    mp.x = Mouse::getPosition(window2).x;
    mp.y = Mouse::getPosition(window2).y;

    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}


void homemenu::uploads() {
    if (!this->tex.loadFromFile("images/homepage.png"))
        throw"unable to load";

    if (!this->menusound.loadFromFile("sounds/menu2.wav"))
        throw"unable to load";
}

void homemenu::initilize() {
    //bg image 

    sound.setBuffer(menusound);
    pic.setTexture(tex);
    pic.setScale(0.75, 0.75);
            sprite.setTexture(texture);
            sprite2.setTexture(texture2);
            sprite3.setTexture(texture3);
            sprite4.setTexture(texture4);
            sprite5.setTexture(texture5);
        
         
            sprite.setPosition(window2.getSize().x / 2   - 50 , 212);   //-sprite.getGlobalBounds().width / 2

            sprite2.setPosition(window2.getSize().x / 2  - 50, 112 + sprite.getPosition().y);
        
            sprite3.setPosition(window2.getSize().x / 2 - 50 , 112 + sprite2.getPosition().y);

            sprite4.setPosition(window2.getSize().x / 2  - 50, 112 + sprite3.getPosition().y);

            sprite5.setPosition(window2.getSize().x / 2 - 50 , 112 + sprite4.getPosition().y);
}

    

        