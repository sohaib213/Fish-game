//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <vector>
//
//using namespace sf;
//using namespace std;
//
//
//Sprite bubble;
//Sprite bubbles[5];
//Text plus_20;
//vector<Text> T1;
//float length;
//Vector2f dir;
//
//void direction(float mPxc, float mPxp, float mPyc, float mPyp, bool c, int& dix, int& diy, bool& Tr, bool& Tl)
//{
//    // Determine the direction
//    if (mPxc > mPxp && c == 1)
//    {
//        if (dix == -1)
//        {
//            Tr = 1;
//        }
//        dix = 1;
//    }
//    else if (mPxc < mPxp && c == 1)
//    {
//        if (dix == 1)
//        {
//            Tl = 1;
//        }
//        dix = -1;
//    }
//
//    if (mPyc > mPyp && c == 1)
//    {
//        diy = 1;
//    }
//    else if (mPyc < mPyp && c == 1)
//    {
//        diy = -1;
//    }
//}
//
//
//
//void velocity_x(int dix, bool c, float mPxc, float mPxp, int vm, float& vx)
//{
//    if (dix == 1)
//    {
//        if (c == 1)
//        {
//            if (vx + (mPxc - mPxp) / 10 < vm)   // limit the velocity
//                vx += (mPxc - mPxp) / 10;
//        }
//
//
//
//    }
//    if (dix == -1)
//    {
//        if (c == 1)
//        {
//            if (vx + (mPxc - mPxp) / 10 > -vm)    // limit the velocity
//                vx += (mPxc - mPxp) / 10;
//        }
//
//    }
//    // Reduce the velocity.x
//    if (vx > 0)
//        vx -= 0.1;
//    else if (vx < 0)
//        vx += 0.1;
//}
//
//
//
//void velocity_y(int diy, bool c, float mPyc, float mPyp, int vm, float& vy)
//{
//    if (diy == 1)
//    {
//        if (c == 1)
//        {
//            if (vy + (mPyc - mPyp) / 10 < vm)
//                vy += (mPyc - mPyp) / 10;
//        }
//    }
//    else if (diy == -1)
//    {
//        if (c == 1)
//        {
//            if (vy + (mPyc - mPyp) / 10 > -vm)
//                vy += (mPyc - mPyp) / 10;
//        }
//    }
//
//    // Reduce the velocity.y
//    if (vy > 0)
//        vy -= 0.1;
//    else if (vy < 0)
//        vy += 0.1;
//}
//
//
//void limitV(float& vx, float& vy, int vm)
//{
//    if (sqrt(vx * vx + vy * vy) >= vm)
//    {
//        vx = vx / sqrt(2);
//        vy = vy / sqrt(2);
//    }
//}
//
//void makeBubblesWhenEating(Sprite p, Vector2f& playerP, bool& EB, double& bubbsT, int& dix)
//{
//    // bubbels
//    if (EB == 1)
//    {
//        if (bubbsT <= 10)
//        {
//            if (bubbsT == 0)
//            {
//                bubbles[0].setScale(0.4f, 0.4f);
//                playerP = p.getPosition();
//                if (dix == 1)
//                    bubbles[0].setPosition(playerP.x + p.getGlobalBounds().width - 15, playerP.y + p.getGlobalBounds().height / 2);
//                else
//                    bubbles[0].setPosition(playerP.x - 15, playerP.y + p.getGlobalBounds().height / 2);
//            }
//            if (bubbsT >= 0.9 && bubbsT <= 1.2)
//            {
//                bubbles[1].setScale(0.4f, 0.4f);
//                if (dix == 1)
//                    bubbles[1].setPosition(playerP.x + p.getGlobalBounds().width, playerP.y + p.getGlobalBounds().height / 2);
//                else
//                    bubbles[1].setPosition(playerP.x, playerP.y + p.getGlobalBounds().height / 2);
//            }
//            if (bubbsT >= 1.8 && bubbsT <= 2.1)
//            {
//                bubbles[2].setScale(0.4f, 0.4f);
//                if (dix == 1)
//                    bubbles[2].setPosition(playerP.x + p.getGlobalBounds().width + 20, playerP.y + p.getGlobalBounds().height / 2);
//                else
//                    bubbles[2].setPosition(playerP.x + 20, playerP.y + p.getGlobalBounds().height / 2);
//            }
//            if (bubbsT >= 2.7 && bubbsT <= 3)
//            {
//                bubbles[3].setScale(0.3f, 0.3f);
//                if (dix == 1)
//                    bubbles[3].setPosition(playerP.x + p.getGlobalBounds().width + 15, playerP.y + p.getGlobalBounds().height / 2);
//                else
//                    bubbles[3].setPosition(playerP.x + 15, playerP.y + p.getGlobalBounds().height / 2);
//            }
//            if (bubbsT >= 5.1 && bubbsT <= 5.4)
//            {
//                bubbles[4].setScale(0.4f, 0.4f);
//                if (dix == 1)
//                    bubbles[4].setPosition(playerP.x + p.getGlobalBounds().width - 5, playerP.y + p.getGlobalBounds().height / 2);
//                else
//                    bubbles[4].setPosition(playerP.x - 5, playerP.y + p.getGlobalBounds().height / 2);
//            }
//
//
//            for (int i = 0; i < 5; i++)
//            {
//                bubbles[i].move(0, -1);
//            }
//            bubbsT += 0.3;
//        }
//        else // bubbules die
//        {
//            for (int i = 0; i < 5; i++)
//            {
//                bubbles[i].setScale(0, 0);
//            }
//            bubbsT = 0;
//            EB = 0;
//        }
//    }
//}
//
//void CollisionWithWindow(Sprite& p, RenderWindow& window)
//{
//    // Collision with window
//    if (p.getPosition().x < 0)
//        p.setPosition(0, p.getPosition().y);
//
//    if (p.getPosition().y < 0)
//        p.setPosition(p.getPosition().x, 0);
//
//    if (p.getPosition().x > window.getSize().x - p.getGlobalBounds().width)
//        p.setPosition(window.getSize().x - p.getGlobalBounds().width, p.getPosition().y);
//
//    if (p.getPosition().y > window.getSize().y - p.getGlobalBounds().height)
//        p.setPosition(p.getPosition().x, window.getSize().y - p.getGlobalBounds().height);
//}
//
//void KeepMouseInWindow(Vector2f mousePosition, RenderWindow& window, Vector2f windowPo, bool& c, float& mPyc, float& mPxc)
//{
//    // keep mouse in window
//    if (mousePosition.x > window.getSize().x)
//    {
//        Mouse::setPosition(Vector2i(0 + windowPo.x + 10, mousePosition.y + windowPo.y + 30));
//        c = 0;
//    }
//    if (mousePosition.x < 0)
//    {
//        Mouse::setPosition(Vector2i(window.getSize().x + windowPo.x, mousePosition.y + windowPo.y + 30));
//        c = 0;
//        mPxc = Mouse::getPosition().x;
//    }
//    if (mousePosition.y > window.getSize().y)
//    {
//        Mouse::setPosition(Vector2i(mousePosition.x + windowPo.x + 8, 0 + windowPo.y + 40));
//        c = 0;
//
//        mPyc = Mouse::getPosition().y;
//    }
//    if (mousePosition.y < 0)
//    {
//        Mouse::setPosition(Vector2i(mousePosition.x + windowPo.x + 8, window.getSize().y + windowPo.y));
//        c = 0;
//
//        mPyc = Mouse::getPosition().y;
//    }
//}
//
//void ScoreEffect(RenderWindow& window)
//{
//    // Score effect
//    for (int i = 0; i < T1.size(); i++)
//    {
//        Vector2f dir = Vector2f(window.getSize().x - 10, 0) - Vector2f(T1[i].getPosition().x, T1[i].getPosition().y);
//        length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
//        dir /= length;
//
//        T1[i].move(5 * dir.x, 5 * dir.y);
//        if (T1[i].getPosition().x >= window.getSize().x - 10 && T1[i].getPosition().y <= 0)
//        {
//            T1.erase(T1.begin() + i);
//        }
//    }
//}
//
//
//// Function to create a button..........................................................................................................................
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
//
//// Function to handle button selection.................................................................................................................
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
////main............................................................................................................................................
//int main() {
//
//    RenderWindow window(VideoMode(1280, 960), "Super Mario");
//    srand(NULL);
//    window.setFramerateLimit(60);
//
//    Font font;
//    if (!font.loadFromFile("Metropolis-ExtraBold.otf")) {
//        return EXIT_FAILURE;
//    }
//
//    // Background image for the menu....................................................................................................................
//    Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("menu1.png")) {
//        return EXIT_FAILURE;
//    }
//    Sprite backgroundSprite(backgroundTexture);
//    backgroundSprite.setScale(3, 3.2);
//    backgroundSprite.setPosition(960, 510);
//    backgroundSprite.setOrigin(319.5, 240);
//
//    //Texture titleTex;
//    //if (!titleTex.loadFromFile("title.png"))
//    //    return EXIT_FAILURE;
//    //Sprite title(titleTex);
//    //title.setOrigin(103, 41);
//    //title.setPosition(960, 150);
//    //title.setScale(2, 2);
//
//
//    const int size = 4;
//    Texture selected[size];
//    if (!selected[0].loadFromFile("1.png"))
//        return EXIT_FAILURE;
//    if (!selected[1].loadFromFile("exit1.png"))
//        return EXIT_FAILURE;
//    if (!selected[2].loadFromFile("3.png"))
//        return EXIT_FAILURE;
//    if (!selected[3].loadFromFile("highscore1.png"))
//        return EXIT_FAILURE;
//
//    Sprite sprites[size];
//    for (int i = 0; i < size; ++i)
//        sprites[i].setTexture(selected[i]);
//    sprites[0].setPosition(800, 400);
//    sprites[1].setPosition(1060, 700);
//    sprites[2].setPosition(1060, 500);
//    sprites[3].setPosition(800, 600);
//
//    sprites[0].setScale(1.3, 1.3);
//    sprites[1].setScale(1.3, 1.3);
//    sprites[2].setScale(1.3, 1.3);
//    sprites[3].setScale(1.3, 1.3);
//
//    Texture unselected[size];
//    if (!unselected[0].loadFromFile("2.png"))
//        return EXIT_FAILURE;
//    if (!unselected[1].loadFromFile("exit2.png"))
//        return EXIT_FAILURE;
//    if (!unselected[2].loadFromFile("gameoptions2.png"))
//        return EXIT_FAILURE;
//    if (!unselected[3].loadFromFile("highscore2.png"))
//        return EXIT_FAILURE;
//
//    Sprite sprites2[size];
//    for (int i = 0; i < size; ++i)
//        sprites2[i].setTexture(unselected[i]);
//    sprites2[0].setPosition(800, 400);
//    sprites2[1].setPosition(1060, 700);
//    sprites2[2].setPosition(1060, 500);
//    sprites2[3].setPosition(800, 600);
//
//    sprites2[0].setScale(1.3, 1.3);
//    sprites2[1].setScale(1.3, 1.3);
//    sprites2[2].setScale(1.3, 1.3);
//    sprites2[3].setScale(1.3, 1.3);
//
//    int gameState = 3; // 0: level one, 1: Paused, 2: Game Over, 3: Start Menu, 4:show levels ,5: level two 
//    int selectedOption = 0; // 0: Start Game, 1: Exit
//
//    //levels Background.................................................................................................................................
//    Texture levelgroundTexture;
//    if (!levelgroundTexture.loadFromFile("test.jpg")) {
//        return EXIT_FAILURE;
//    }
//    Sprite levelgroundSprite(levelgroundTexture);
//    levelgroundSprite.setPosition(960, 514);
//    levelgroundSprite.setOrigin(960, 516);
//    levelgroundSprite.setScale(1, 1);
//    //level 1 picture...................................................................................................................................
//    Texture l1Texture;
//    if (!l1Texture.loadFromFile("level 1.png")) {
//        return EXIT_FAILURE;
//    }
//    Sprite l1sprite(l1Texture);
//    l1sprite.setScale(0.16, 0.16);
//    l1sprite.setPosition(540, 400);
//    Sprite level(l1Texture);
//    level.setScale(1, 1);
//    level.setPosition(500, 500);
//    //level 2 picture....................................................................................................................................
//    Texture l2Texture;
//    if (!l2Texture.loadFromFile("level 2.png")) {
//        return EXIT_FAILURE;
//    }
//    Sprite l2sprite(l2Texture);
//    l2sprite.setScale(0.25, 0.25);
//    l2sprite.setPosition(1280, 400);
//    //pause..........................................................................................................................................
//    Texture pauseTexture;
//    if (!pauseTexture.loadFromFile("pause.png"))
//        return EXIT_FAILURE;
//    Sprite pause(pauseTexture);
//    pause.setOrigin(226, 195.5);
//    pause.setScale(4, 2.7);
//    pause.setPosition(960, 540);
//
//    // Create buttons...................................................................................................................................
//    Text startButton = createButton("Start Game", font, 35, Color::White, 850, 400);
//    Text continueButton = createButton("Continue", font, 35, Color::White, 850, 400);
//    Text exitButton = createButton("Exit", font, 30, Color::White, 900, 450);
//    Text gameOptions = createButton("Game options", font, 30, Color::White, 300, 300);
//    Text highscore = createButton("High score", font, 30, Color::White, 350, 600);
//    Text l1Button = createButton("Level 1\n(Sunken Treasure)", font, 40, Color::White, 540, 540);
//    Text l2Button = createButton("Level 2\n(Deap Sea)", font, 40, Color::White, 1280, 540);
//
//
//    // Player............................................................................................................................
//    Sprite p1;
//    Texture player1;
//    if(!player1.loadFromFile("p.png"))
//       return EXIT_FAILURE;
//    p1.setTexture(player1);
//    float pwi = 122, phe = 104;     // player  ( width, height )
//    p1.setTextureRect(IntRect(1, 425 / 2, 125, 105));
//    float x = 0;
//    p1.setScale(0.75, 0.75);
//    p1.setPosition(window.getSize().x / 2 - p1.getGlobalBounds().width / 2, 0);
//    Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
//
//    // Mouse Position Declaration (current , previous)
//    float mPxc, mPxp = 0;
//    float mPyc, mPyp = 0;
//    // check if the mouse is out of window
//    bool c = 1;
//    // Direction of moving
//    int dix = 0, diy = 0;
//
//    // velocity
//    float vx = 0, vy = 0, vm = 10;
//
//    //Turn
//    double xr = 0, xl = 0;
//    bool Tr = 0, Tl = 0;
//
//    // Fish 1
//    int const fN = 15;  // Nomber of fish
//    std::vector<CircleShape> a;
//    for (int i = 0; i < fN; ++i)
//    {
//        sf::CircleShape circle(16); // Radius of 20
//        circle.setFillColor(Color::Red); // Set color
//        circle.setPosition(std::rand() % 800, std::rand() % 600); // Random position
//        a.push_back(circle);
//    }
//    double Vx[fN];
//    double Vy[fN];
//    float spwanT[fN] = { 0 };
//    for (int i = 0; i < fN; i++)
//    {
//        spwanT[i] = 60;
//    }
//    // score effect
//
//    Font font1;
//    if (!font1.loadFromFile("Metropolis-ExtraBold.otf"))
//        return EXIT_FAILURE;
//    //font1.loadFromFile("Metropolis-ExtraBold.otf");
//
//    plus_20.setFont(font1);
//    plus_20.setCharacterSize(25);
//    plus_20.setFillColor(Color::White);
//    plus_20.setString("+20");
//
//    SoundBuffer buffer;
//    if(!buffer.loadFromFile("bite1.wav"))
//    return EXIT_FAILURE;
//    Sound b1;
//    b1.setBuffer(buffer);
//
//    // Music
//    Music music;
//    if(!music.openFromFile("Feeding-Frenzy-Track-1.ogg"))
//    return EXIT_FAILURE;
//    music.play();
//    double mt = 0;
//
//    // Time
//    Clock clock, clo;
//    double dt = 0;
//
//    // check eating
//    bool E = 0;
//
//    // Position of window
//    Vector2f windowPo(window.getPosition().x, window.getPosition().y);
//
//    // Bubbles effect when eating fish
//    Texture bub1T;
//    if(!bub1T.loadFromFile("bubble1.png"))
//    return EXIT_FAILURE;
//
//    bubble.setTexture(bub1T);
//    for (int i = 0; i < 5; i++)
//    {
//        bubbles[i] = bubble;
//    }
//
//    double eT = 0;
//    double bubbsT = 0;  // Bubbles Time
//    bool EB = 0;        // Bubbles when eating check
//
//    // player position
//    Vector2f playerP;
//
//    // rock
//    Texture Back1T;
//    Back1T.loadFromFile("back 1 t.png");
//    Sprite ro;
//    ro.setTexture(Back1T);
//    ro.setTextureRect(IntRect(0, 0, 390, 108));
//    ro.setPosition(402, window.getSize().y - 108);
//
//    // Coral reefs
//    Sprite coral1;
//    coral1.setTexture(Back1T);
//    coral1.setTextureRect(IntRect(138, 111, 182, 115));
//    coral1.setPosition(560, 595);
//
//    Sprite coral2;
//    coral2.setTexture(Back1T);
//    coral2.setTextureRect(IntRect(322, 117, -180, 110));
//    coral2.setPosition(450, 595);
//
//
//    while (window.isOpen()) {
//
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed)
//                window.close();
//
//            if (gameState == 3) { // Start Menu event handling
//                if (event.type == Event::KeyPressed) {
//                    if (event.type == Event::KeyPressed) {
//                        if (event.key.code == Keyboard::Left) {
//                            setSelected(exitButton, false);
//                            setSelected(highscore, false);
//                            setSelected(startButton, true);
//                            setSelected(gameOptions, false);
//                        }
//                        else if (event.key.code == Keyboard::Right) {
//                            setSelected(startButton, false);
//                            setSelected(gameOptions, false);
//                            setSelected(highscore, true);
//                            setSelected(exitButton, false);
//                        }
//
//                        // Check for up and down keys outside the left/right conditions
//                        if (event.key.code == Keyboard::Up) {
//                            if (startButton.getFillColor() == Color::Yellow) {
//                                setSelected(exitButton, true);
//                                setSelected(startButton, false);
//                            }
//                            else if (gameOptions.getFillColor() == Color::Yellow) {
//                                setSelected(startButton, true);
//                                setSelected(gameOptions, false);
//                            }
//                            else if (highscore.getFillColor() == Color::Yellow) {
//                                setSelected(gameOptions, true);
//                                setSelected(highscore, false);
//                            }
//                            else if (exitButton.getFillColor() == Color::Yellow) {
//                                setSelected(highscore, true);
//                                setSelected(exitButton, false);
//                            }
//                        }
//                        else if (event.key.code == Keyboard::Down) {
//                            if (startButton.getFillColor() == Color::Yellow) {
//                                setSelected(gameOptions, true);
//                                setSelected(startButton, false);
//                            }
//                            else if (gameOptions.getFillColor() == Color::Yellow) {
//                                setSelected(highscore, true);
//                                setSelected(gameOptions, false);
//                            }
//                            else if (highscore.getFillColor() == Color::Yellow) {
//                                setSelected(exitButton, true);
//                                setSelected(highscore, false);
//                            }
//                            else if (exitButton.getFillColor() == Color::Yellow) {
//                                setSelected(startButton, true);
//                                setSelected(exitButton, false);
//                            }
//                        }
//                    }
//
//
//                    if (event.key.code == Keyboard::Enter) {
//                        if (startButton.getFillColor() == Color::Yellow) {
//                            gameState = 4; // Show levels
//                        }
//                        else if (exitButton.getFillColor() == Color::Yellow) {
//                            window.close(); // Exit the game
//                        }
//                    }
//                }
//            }
//            if (gameState == 4) {
//                if (event.type == Event::KeyPressed) {
//                    if (event.key.code == Keyboard::Escape) {
//                        gameState = 3;
//                    }
//                    else if (event.key.code == Keyboard::Right) {
//                        setSelected(l2Button, true);
//                        setSelected(l1Button, false);
//                    }
//                    else if (event.key.code == Keyboard::Left) {
//                        setSelected(l1Button, true);
//                        setSelected(l2Button, false);
//                    }
//                    else if (event.key.code == Keyboard::Enter) {
//                        if (l1Button.getFillColor() == Color::Yellow) {
//                            gameState = 0;
//                        }
//
//                    }
//                }
//            }
//            if (gameState == 0) { // Game event handling
//                if (event.type == Event::KeyPressed) {
//                    if (event.key.code == Keyboard::P) {
//                        gameState = 1; // Pause the game
//                    }
//                }
//            }
//
//            if (gameState == 1) { // Pause Menu event handling
//
//                if (event.type == Event::KeyPressed) {
//                    if (event.key.code == Keyboard::Escape) {
//                        gameState = 0; // Resume the game
//                    }
//                    else if (event.key.code == Keyboard::Up) {
//                        setSelected(continueButton, true);
//                        setSelected(exitButton, false);
//                    }
//                    else if (event.key.code == Keyboard::Down) {
//                        setSelected(continueButton, false);
//                        setSelected(exitButton, true);
//                    }
//                    else if (event.key.code == Keyboard::Enter) {
//                        if (continueButton.getFillColor() == Color::Yellow) {
//                            gameState = 0; // Resume the game
//                        }
//                        else if (exitButton.getFillColor() == Color::Yellow) {
//                            window.close(); // Exit the game
//                        }
//                    }
//                }
//            }
//        }
//
//        if (gameState == 0) { // Game logic..............................................................................................
//            // Make mouse unvisible
//            window.setMouseCursorVisible(false);
//
//            // delta time
//            dt = clock.restart().asSeconds();
//
//            // Music
//            mt += dt;
//            if (mt >= 72)
//            {
//                music.play();
//                mt = 0;
//            }
//
//            x += 0.09;
//            if (x >= 15)
//                x = 0;
//
//            Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
//            mPxc = mousePosition.x;
//            mPyc = mousePosition.y;
//            direction(mPxc, mPxp, mPyc, mPyp, c, dix, diy, Tr, Tl);
//
//            // Moving....................................................................................................................
//            // X
//            velocity_x(dix, c, mPxc, mPxp, vm, vx);
//
//            if (dix == 1 && c == 1)
//                p1.setTextureRect(IntRect(125 + (int)x * 126, 214, -pwi, phe));
//            else if (dix == -1 && c == 1)
//                p1.setTextureRect(IntRect(3 + (int)x * 126, 214, pwi, phe));
//            // Y
//            velocity_x(diy, c, mPyc, mPyp, vm, vy);
//            // Limit Velocity
//            limitV(vx, vy, vm);
//
//            // Perform a Turn
//            if (Tr == 1)
//            {
//                if (xr > 4)
//                {
//                    xr = 0;
//                    Tr = 0;
//                }
//                else
//                {
//                    xr += 0.3;
//                    p1.setTextureRect(IntRect(3 + (int)xr * 126, 320, pwi, phe));
//                }
//
//            }
//            if (Tl == 1)
//            {
//                if (xl > 4)
//                {
//                    xl = 0;
//                    Tl = 0;
//                }
//                else
//                {
//                    xl += 0.3;
//                    p1.setTextureRect(IntRect(124 + (int)xl * 126, 320, -pwi, phe));
//                }
//            }
//            // Collision with window
//            CollisionWithWindow(p1, window);
//
//            // Collision with fish
//            if (E == 1)
//            {
//                // eating animation
//                if (eT <= 6)
//                {
//                    if (dix == -1)
//                    {
//                        p1.setTextureRect(IntRect(2 + (int)eT * 126, 2, 122, 104));
//                    }
//                    else if (dix == 1)
//                    {
//                        p1.setTextureRect(IntRect(125 + (int)eT * 126, 2, -122, 104));
//                    }
//                    eT += 0.3;
//                }
//                else
//                {
//                    E = 0;
//                    eT = 0;
//                }
//            }
//            makeBubblesWhenEating(p1, playerP, EB, bubbsT, dix);
//
//            //f1
//            for (int i = 0; i < a.size(); i++)
//            {
//                // collision with player
//                if (p1.getGlobalBounds().intersects(a[i].getGlobalBounds()))
//                {
//                    E = 1;
//
//                    if (EB == 1)
//                        bubbsT = 0;
//
//                    EB = 1;
//
//                    a[i].setScale(0, 0);
//                    b1.play();
//
//
//                    if (dix == -1)
//                        plus_20.setPosition(p1.getPosition().x, p1.getPosition().y + p1.getGlobalBounds().height / 2);
//                    else
//                        plus_20.setPosition(p1.getPosition().x + p1.getGlobalBounds().width, p1.getPosition().y + p1.getGlobalBounds().height / 2);
//                    T1.push_back(plus_20);
//                }
//
//                if (spwanT[i] >= 60)
//                {
//                    Vx[i] = ((rand() % 21) - 10) / 5.f;
//                    Vy[i] = ((rand() % 21) - 10) / 5.f;
//                    spwanT[i] = 0;
//                }
//                a[i].move(Vx[i], Vy[i]);
//            }
//
//            for (int i = 0; i < fN; i++)
//            {
//                spwanT[i]++;
//            }
//            // Score effect
//            ScoreEffect(window);
//
//            c = 1;
//
//            // keep mouse in window
//            KeepMouseInWindow(mousePosition, window, windowPo, c, mPyc, mPxc);
//
//            // Final velocity of the player
//            p1.move(vx, vy);
//            mPxp = mPxc;
//            mPyp = mPyc;
//
//
//
//        }
//
//        window.clear();
//
//        if (gameState == 3) { // Draw the start menu with background
//            window.draw(backgroundSprite);
//            //window.draw(title);
//            if (startButton.getFillColor() == Color::Yellow) {
//                window.draw(sprites2[0]);
//                window.draw(sprites[1]);
//                window.draw(sprites[2]);
//                window.draw(sprites[3]);
//            }
//            else if (exitButton.getFillColor() == Color::Yellow) {
//                window.draw(sprites[0]);
//                window.draw(sprites2[1]);
//                window.draw(sprites[2]);
//                window.draw(sprites[3]);
//            }
//            else if (gameOptions.getFillColor() == Color::Yellow) {
//                window.draw(sprites[0]);
//                window.draw(sprites[1]);
//                window.draw(sprites2[2]);
//                window.draw(sprites[3]);
//            }
//            else {
//                window.draw(sprites[0]);
//                window.draw(sprites[1]);
//                window.draw(sprites[2]);
//                window.draw(sprites2[3]);
//            }
//
//        }
//        else if (gameState == 4) {
//            window.draw(levelgroundSprite);
//            window.draw(l1sprite);
//            window.draw(l2sprite);
//            window.draw(l1Button);
//            window.draw(l2Button);
//        }
//        else if (gameState == 0) { // Draw the game
//
//            window.draw(level);
//            window.draw(coral1);
//            window.draw(coral2);
//            window.draw(ro);
//            window.draw(p1);
//            for (int i = 0; i < a.size(); i++)
//            {
//                window.draw(a[i]);
//            }
//            for (int i = 0; i < T1.size(); i++)
//            {
//                window.draw(T1[i]);
//            }
//            if (EB == 1)
//                for (int i = 0; i < 5; i++)
//                    window.draw(bubbles[i]);
//
//
//        }
//        else if (gameState == 1) { // Draw the pause menu
//            window.draw(pause);
//            window.draw(continueButton);
//            window.draw(exitButton);
//        }
//
//        window.display();
//    }
//
//    return 0;
//}