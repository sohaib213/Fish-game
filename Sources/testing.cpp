//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <vector>
//#include <fstream>
//#include <string>
//
//using namespace sf;
//using namespace std;
//
//const int size = 23;
//
////Function to set sprites
//void setSprites(Sprite sprites[], const Texture textures[], const Vector2f positions[], const Vector2f scales[], int size) {
//    for (int i = 0; i < size; ++i) {
//        sprites[i].setTexture(textures[i]);
//        sprites[i].setPosition(positions[i]);
//        sprites[i].setScale(scales[i]);
//    }
//}
//
//// Function to create a button
//Text createButton(const string& buttonText, Font& font, int fontSize, const Color& color, float x, float y) {
//    Text button;
//    button.setString(buttonText);
//    button.setFont(font);
//    button.setCharacterSize(fontSize);
//    button.setFillColor(color);
//    button.setPosition(x, y);
//    return button;
//}
//
//// Function to handle button selection
//void setSelected(Text& buttonText, bool isSelected) {
//    if (isSelected) {
//
//        buttonText.setFillColor(Color::Yellow);
//    }
//    else {
//        buttonText.setFillColor(Color::White);
//    }
//}
//
//
////main
//int main() {
//
//    RenderWindow window(VideoMode(1280, 960), "Frenzy Fish");
//    srand(NULL);
//    window.setFramerateLimit(60);
//
//    Font font;
//    if (!font.loadFromFile("SuperMario256.ttf")) {
//        return EXIT_FAILURE;
//    }
//
//    Texture textures[23];
//    textures[0].loadFromFile("menu1.png");
//    textures[1].loadFromFile("title.png");
//    textures[2].loadFromFile("1.png");
//    textures[3].loadFromFile("exit1.png");
//    textures[4].loadFromFile("3.png");
//    textures[5].loadFromFile("highscore1.png");
//    textures[6].loadFromFile("l1selected.png");
//    textures[7].loadFromFile("l1selected.png");
//    textures[8].loadFromFile("2.png");
//    textures[9].loadFromFile("exit2.png");
//    textures[10].loadFromFile("gameoptions2.png");
//    textures[11].loadFromFile("highscore2.png");
//    textures[12].loadFromFile("l1unselected.png");
//    textures[13].loadFromFile("l1unselected.png");
//    textures[14].loadFromFile("menu1.png");
//    textures[15].loadFromFile("menu1.png");
//    textures[16].loadFromFile("level 2.png");
//    textures[17].loadFromFile("pause.png");
//    textures[18].loadFromFile("mute.png");
//    textures[19].loadFromFile("unmute.jpg");
//    textures[20].loadFromFile("level3.png");
//    textures[21].loadFromFile("l1selected.png");
//    textures[22].loadFromFile("l1unselected.png");
//
//    // Create sprites
//    Sprite sprites[23];
//    sprites[0].setOrigin(319.5, 240);
//    sprites[1].setOrigin(103, 41);
//    sprites[14].setOrigin(319.5, 240);
//    sprites[16].setOrigin(398.5, 300);
//    sprites[17].setOrigin(226, 195.5);
//    sprites[20].setOrigin(398.5, 300);
//
//    Vector2f positions[23] = {
//        Vector2f(640,480),  //0
//        Vector2f(640,150),  //1
//        Vector2f(400,300),  //2
//        Vector2f(800,700),  //3
//        Vector2f(800,450),  //4
//        Vector2f(400,600),  //5
//        Vector2f(450,230),  //6
//        Vector2f(750,710),  //7
//        Vector2f(400,300),  //8
//        Vector2f(800,700),  //9
//        Vector2f(800,450),  //10
//        Vector2f(400,600),  //11
//        Vector2f(450,230),  //12
//        Vector2f(750,710),  //13
//        Vector2f(640,240),  //14
//        Vector2f(300,300),  //15
//        Vector2f(960,750),  //16
//        Vector2f(640,480),  //17
//        Vector2f(700,370),  //18
//        Vector2f(700,370),  //19
//        Vector2f(300,750),  //20
//        Vector2f(100,700),  //21
//        Vector2f(100,700),  //22
//    };
//    Vector2f scales[23] = {
//        Vector2f(2,2),         //0                             
//        Vector2f(2,2),         //1     
//        Vector2f(1.6,1.6),     //2 
//        Vector2f(1.7,1.7),     //3 
//        Vector2f(1.7,1.7),     //4 
//        Vector2f(1.7,1.7),     //5 
//        Vector2f(3.1,2.4),     //6 
//        Vector2f(3.1,2.4),     //7 
//        Vector2f(1.6,1.6),     //8 
//        Vector2f(1.7,1.7),     //9 
//        Vector2f(1.7,1.7),     //10 
//        Vector2f(1.7,1.7),     //11 
//        Vector2f(3.1,2.4),     //12 
//        Vector2f(3.1,2.4),     //13 
//        Vector2f(2,1.2),       //14     
//        Vector2f(1,1),         //15 
//        Vector2f(0.9,0.74),    //16 
//        Vector2f(2.8,2.4),     //17 
//        Vector2f(0.5,0.5),     //18 
//        Vector2f(0.3,0.3),     //19 
//        Vector2f(0.75,0.74),   //20 
//        Vector2f(3.1,2.4),     //21 
//        Vector2f(3.1,2.4),     //22 
//    };
//    setSprites(sprites, textures, positions, scales, 23);
//
//    // Create buttons
//    bool b1l = 0, b2l = 0, b3l = 0, b4l = 0;
//    bool b5l = 0, b6l = 0, b12l = 0;
//    bool b7l = 0, b8l = 0, b9l = 0, b10l = 0;
//    bool b11l = 0;
//    int gameState = 0;
//
//    Text continueButton = createButton("Continue", font, 60, Color::White, 400, 300);
//    Text exitButton = createButton("Exit", font, 50, Color::White, 400, 600);
//    Text l1Button = createButton("     Level 1\n(Sunken Treasure)", font, 35, Color::White, 480, 240);
//    Text l2Button = createButton("   level 2\n(pottery cave)", font, 40, Color::Black, 140, 710);
//    Text l3Button = createButton(" Level 3\n(Deap Sea)", font, 40, Color::Blue, 850, 720);
//    Text mainmenuButton = createButton("Main Menu", font, 55, Color::White, 400, 400);
//    Text levelButton = createButton("Levels", font, 55, Color::White, 400, 500);
//    Text muteButton = createButton("Mute", font, 35, Color::White, 400, 400);
//    Text escapeButton = createButton("Press ESC to go back", font, 20, Color::White, 20, 30);
//    Text Pbutton = createButton("Press p to pause", font, 20, Color::White, 30, 930);
//
//    // Music
//    Music music;
//    music.openFromFile("Feeding-Frenzy-Track-1.ogg");
//    music.play();
//    bool isMuted = false;
//    double mt = 0;
//
//
//    // mouse
//    RectangleShape mouse;
//    mouse.setSize(Vector2f(10, 10));
//
//    while (window.isOpen()) {
//
//        Event event;
//        // Game loop
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//
//            mouse.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
//
//            // Start Menu event handling
//            if (gameState == 0)
//            {
//                b1l = 0;
//                b2l = 0;
//                b3l = 0;
//                b4l = 0;
//
//                if (mouse.getGlobalBounds().intersects(sprites[2].getGlobalBounds()))
//                    b1l = 1;
//
//                if (b1l == 1 && Mouse::isButtonPressed(Mouse::Left))//show levels
//                    gameState = 4;
//                if (mouse.getGlobalBounds().intersects(sprites[3].getGlobalBounds()))
//                    b2l = 1;
//
//                if (b2l == 1 && Mouse::isButtonPressed(Mouse::Left))
//                    window.close();
//                if (mouse.getGlobalBounds().intersects(sprites[4].getGlobalBounds()))
//                    b3l = 1;
//
//                if (b3l == 1 && Mouse::isButtonPressed(Mouse::Left))//game optins
//                    gameState = 1;
//                if (mouse.getGlobalBounds().intersects(sprites[5].getGlobalBounds()))
//                    b4l = 1;
//
//                if (b4l == 1 && Mouse::isButtonPressed(Mouse::Left))//level two
//                    gameState = 6;
//
//            }
//            //show levels
//            if (gameState == 4)
//            {
//                b5l = 0;
//                b6l = 0;
//                b12l = 0;
//
//
//                if (mouse.getGlobalBounds().intersects(sprites[12].getGlobalBounds()))
//                    b5l = 1;
//                if (b5l == 1 && Mouse::isButtonPressed(Mouse::Left))//level one
//                    gameState = 5;
//
//                if (mouse.getGlobalBounds().intersects(sprites[22].getGlobalBounds()))
//                    b12l = 1;
//                if (b12l == 1 && Mouse::isButtonPressed(Mouse::Left))//level one
//                    gameState = 5;
//
//                if (mouse.getGlobalBounds().intersects(sprites[13].getGlobalBounds()))
//                    b6l = 1;
//                if (b6l == 1 && Mouse::isButtonPressed(Mouse::Left))//high score
//                    gameState = 2;
//
//            }
//            //level one
//            if (gameState == 5)
//            { // Game event handling
//                if (event.type == Event::KeyPressed)
//                {
//                    if (event.key.code == Keyboard::P)
//                    {
//                        gameState = 7; // Pause the game
//                    }
//                }
//            }
//
//            //Game Options
//            if (gameState == 1)
//            {
//                b11l = 0;
//                setSelected(muteButton, false);
//
//                if (mouse.getGlobalBounds().intersects(muteButton.getGlobalBounds())) {
//                    b11l = 1;
//                    setSelected(muteButton, true);
//                }
//                if (b11l == 1 && Mouse::isButtonPressed(Mouse::Left)) {
//                    // Toggle between mute and unmute when the mute button is pressed
//                    isMuted = !isMuted;
//                    // Set the text color of the mute button based on the mute state
//                    setSelected(muteButton, isMuted);
//
//                    if (isMuted)
//                    {
//                        music.pause();
//                    }
//                    else
//                    {
//                        music.play();
//                    }
//                }
//                else if (exitButton.getFillColor() == Color::Yellow)
//                {
//                    window.close();
//                }
//                else if (event.key.code == Keyboard::Escape)
//                {
//                    gameState = 0;//menu
//                }
//
//            }
//
//            // Pause Menu 
//            if (gameState == 7)
//            {
//                b7l = 0;
//                b8l = 0;
//                b9l = 0;
//                b10l = 0;
//                setSelected(continueButton, false);
//                setSelected(exitButton, false);
//                setSelected(mainmenuButton, false);
//                setSelected(levelButton, false);
//
//                if (mouse.getGlobalBounds().intersects(continueButton.getGlobalBounds())) {
//                    b7l = 1;
//                    setSelected(continueButton, true);
//                }
//                if (b7l == 1 && Mouse::isButtonPressed(Mouse::Left))
//                    gameState = 5;//level one
//
//                if (mouse.getGlobalBounds().intersects(mainmenuButton.getGlobalBounds())) {
//                    b8l = 1;
//                    setSelected(mainmenuButton, true);
//                }
//                if (b8l == 1 && Mouse::isButtonPressed(Mouse::Left))
//                    gameState = 0;//menu
//
//                if (mouse.getGlobalBounds().intersects(levelButton.getGlobalBounds())) {
//                    b9l = 1;
//                    setSelected(levelButton, true);
//                }
//                if (b9l == 1 && Mouse::isButtonPressed(Mouse::Left))
//                    gameState = 4;//show levels
//
//                if (mouse.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
//                    b10l = 1;
//                    setSelected(exitButton, true);
//                }
//                if (b10l == 1 && Mouse::isButtonPressed(Mouse::Left))
//                    window.close();
//            }
//        }
//
//        // Game logic
//        if (gameState == 5)
//        {
//
//
//        }
//
//        window.clear();
//
//        // Draw 
//        if (gameState == 0)
//        {
//            window.draw(sprites[0]);
//            window.draw(sprites[1]);
//            if (b1l == 1)
//                window.draw(sprites[8]);
//            else
//                window.draw(sprites[2]);
//            if (b2l == 1)
//                window.draw(sprites[9]);
//            else
//                window.draw(sprites[3]);
//            if (b3l == 1)
//                window.draw(sprites[10]);
//            else
//                window.draw(sprites[4]);
//            if (b4l == 1)
//                window.draw(sprites[11]);
//            else
//                window.draw(sprites[5]);
//        }
//        else if (gameState == 4)
//        {
//            window.draw(escapeButton);
//            window.draw(sprites[14]);
//            window.draw(sprites[16]);
//            window.draw(sprites[20]);
//
//            if (b5l == 1)
//                window.draw(sprites[6]);
//            else
//                window.draw(sprites[12]);
//            if (b12l == 1)
//                window.draw(sprites[21]);
//            else
//                window.draw(sprites[22]);
//            if (b6l == 1)
//                window.draw(sprites[7]);
//            else
//                window.draw(sprites[13]);
//
//            window.draw(l1Button);
//            window.draw(l2Button);
//            window.draw(l3Button);
//        }
//        else if (gameState == 5)
//        { // Draw the game
//            window.draw(Pbutton);
//        }
//        else if (gameState == 7)
//        { // Draw the pause menu
//            window.draw(sprites[17]);
//            window.draw(levelButton);
//            window.draw(mainmenuButton);
//            window.draw(continueButton);
//            window.draw(exitButton);
//        }
//        else if (gameState == 1)
//        {
//            window.draw(sprites[17]);
//            window.draw(escapeButton);
//            window.draw(muteButton);
//            if (isMuted)
//                window.draw(sprites[18]);
//            else
//                window.draw(sprites[19]);
//        }
//        else if (gameState == 2) {
//
//        }
//
//        window.display();
//    }
//
//    return 0;
//}