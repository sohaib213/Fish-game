#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>
#include <string>
using namespace sf;
using namespace std;

// Tony Code

/*
        ............Game Sate.................................display................
        :                                  :                                        :
        :             (0)                  :                 main menu              :
        :             (1)                  :                 game options           :
        :             (2)                  :                 highscore              :
        :             (3)                  :                 player name            :
        :             (4)                  :                 show levels            :
        :             (5)                  :                 level one              :
        :             (6)                  :                 level two              :
        :             (7)                  :                 level three            :
        :             (8)                  :                 pause                  :
        :             (9)                  :                 after finshing level   :
        :             (10)                 :                 game over              :
        :............................................................................

*/

const int size = 23;
int gameState = 0;
int tempState = 0;


//function to save history
void His(RenderWindow& window, int& gameState) {
    Texture bgTexture;
    bgTexture.loadFromFile("levels.png");
    Sprite bg;
    bg.setTexture(bgTexture);
    bg.setOrigin(280, 224.5);
    bg.setPosition(640, 480);
    bg.setScale(1.6, 1.6);

    Texture bgText;
    bgText.loadFromFile("menu1.png");
    Sprite bg2;
    bg2.setTexture(bgText);
    bg2.setOrigin(319.5, 240);
    bg2.setPosition(640, 480);
    bg2.setScale(2, 2);

    Font font;
    if (!font.loadFromFile("Reach-Fill.ttf")) {
        cout << "Error: Font file not found." << endl;
        return;
    }

    ifstream infile("history.txt");
    if (!infile.is_open()) {
        cout << "Error: Unable to open history file." << endl;
        return;
    }

    Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color::Green);

    float startY = 100.0f;
    float lineHeight = 50.0f;

    Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return;
            }
            else if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    gameState = 0; // Return to main menu
                    return;
                }
                else if (event.key.code == Keyboard::Up) {
                    startY += 20; // Scroll up
                }
                else if (event.key.code == Keyboard::Down) {
                    startY -= 20; // Scroll down
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the background sprites
        window.draw(bg);
        window.draw(bg2);

        // Reset startY for repositioning the text
        float currentY = startY;

        // Reset the file stream to the beginning
        infile.clear();
        infile.seekg(0, ios::beg);

        // Read and draw text from the file
        string line;
        while (getline(infile, line, '*')) {
            text.setString(line);
            text.setPosition(50.0f, currentY);
            window.draw(text);
            currentY += lineHeight;
        }

        // Display the window contents
        window.display();
    }

    infile.close();
}



//Function to set sprites
void setSprites(Sprite sprites[], const Texture textures[], const Vector2f positions[], const Vector2f scales[], int size) {
    for (int i = 0; i < size; ++i) {
        sprites[i].setTexture(textures[i]);
        sprites[i].setPosition(positions[i]);
        sprites[i].setScale(scales[i]);
    }
}

// Function to create a button
Text createButton(const string& buttonText, Font& font, int fontSize, const Color& color, float x, float y) {
    Text button;
    button.setString(buttonText);
    button.setFont(font);
    button.setCharacterSize(fontSize);
    button.setFillColor(color);
    button.setPosition(x, y);
    return button;
}

// Function to handle button selection
void setSelected(Text& buttonText, bool isSelected) {
    if (isSelected) {

        buttonText.setFillColor(Color::Cyan);
    }
    else {
        buttonText.setFillColor(Color::White);
    }
}

//Function to set player name
void Pname(RenderWindow& window, string& name) {
    if (!name.empty()) {
        name.clear();
    }
    Font font;
    font.loadFromFile("Reach-Fill.ttf");
    Text t1, t2;
    t1.setFont(font);
    t2.setFont(font);
    t1.setString("Enter your name");
    t1.setCharacterSize(50);
    t2.setCharacterSize(40);
    t1.setPosition(460, 400);
    t2.setPosition(550, 450);
    t1.setFillColor(Color::Green);
    t2.setFillColor(Color::Green);
    Texture bgTexture;
    bgTexture.loadFromFile("levels.png");
    Sprite bg;
    Texture bgText;
    bgText.loadFromFile("menu1.png");
    Sprite bg2;
    bg2.setTexture(bgText);
    bg.setTexture(bgTexture);
    bg2.setOrigin(319.5, 240);
    bg2.setPosition(640, 480);
    bg2.setScale(2, 2);
    bg.setOrigin(280, 224.5);
    bg.setPosition(640, 480);
    bg.setScale(1.6, 1.6);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b' && !name.empty()) {
                    name.pop_back(); // Backspace handling
                }
                else if (event.text.unicode < 128) {
                    name += static_cast<char>(event.text.unicode); // Add typed characters to name
                }
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Enter && name.size() > 1) {
                    gameState = 4;
                    return;
                }
                else if (event.key.code == Keyboard::Escape) {
                    // Escape key pressed, return to main menu
                    gameState = 0;
                    return;
                }
            }
        }
        t2.setString(name);
        window.clear();
        window.draw(bg2);
        window.draw(bg);
        window.draw(t1);
        window.draw(t2);
        window.display();
    }


}




// Sohaib Code-----------------------------------------------------------------------------------------------------------
// Global things------------------------------------------------------------------------------------------------------
int windowWidth = 1280;
int windowHeight = 960;
View view(FloatRect(0, 0, windowWidth / 1.24, windowHeight / 1.24));


Sprite bubble;
Sprite bubble2;
Sprite bubbles[5];
vector<Sprite> BubblesInBack;

Text plus_10;  // ScoreEffect Line (461)
Text plus_20;
Text plus_30;
vector<Text> T1;
float length;
Vector2f dir;

Sprite star;
vector<Sprite> stars;
int spwanTimerStars = 240;
vector<int> smallStarsTimers;
Sprite smalStarw;
Sprite smalStary;
vector<Sprite> smallStars;
vector<int> counter; // Number of smallStars Now
Sprite spark1;
vector<Sprite> sparks1;
vector<int> countSpark1; // Number of Sparks Now
vector <int> sparksTimer;

Sound bS;  // bite Star
Sound b1;  // bite 1

Sprite Yum;
Sprite Gulb;

Sound feddingFren;
Sound doubleFrenzy;

Text OnFireText;

// Wining effect
Sprite Bubs[7];
Text Perfect[7];
int PerfectTime = 0;
int endPerfect = 0;
Sound winSound;
int winingTime = 0;
// Losing effect
Sprite Bubs1[5];
Text Sorry[5];
int SorryTime = 0;
int endSorry = 0;
Sound losSound;
int LosingTime = 0;

bool TurboCheck = 0;
int TurboTime = 0;
Vector2f turboVelocity = Vector2f(0, 0);

Sound dashSound;

int score = 0;
int hb_score = 0;


// Struct players
struct player {
    Sprite Spri;
    int score = 0;
    int health = 3;
}players[3];


// Functions------------------------------------------------------------------------------------------------------
void direction(float mPxc, float mPxp, float mPyc, float mPyp, bool c, int& dix, int& diy, bool& Tr, bool& Tl)
{
    // Determine the direction
    if (mPxc > mPxp && c == 1)
    {
        if (dix == -1)
        {
            Tr = 1;
        }
        dix = 1;
    }
    else if (mPxc < mPxp && c == 1)
    {
        if (dix == 1)
        {
            Tl = 1;
        }
        dix = -1;
    }

    if (mPyc > mPyp && c == 1)
    {
        diy = 1;
    }
    else if (mPyc < mPyp && c == 1)
    {
        diy = -1;
    }
}

void velocity_x(int dix, bool c, float mPxc, float mPxp, int vm, float& vx)
{
    if (dix == 1)
    {
        if (c == 1)
        {
            if (vx + (mPxc - mPxp) / 15 < vm)   // limit the velocity
                vx += (mPxc - mPxp) / 15;
        }



    }
    if (dix == -1)
    {
        if (c == 1)
        {
            if (vx + (mPxc - mPxp) / 15 > -vm)    // limit the velocity
                vx += (mPxc - mPxp) / 15;
        }

    }
    // Reduce the velocity.x
    if (vx > 0)
        vx -= 0.1;
    else if (vx < 0)
        vx += 0.1;
}

void velocity_y(int diy, bool c, float mPyc, float mPyp, int vm, float& vy)
{
    if (diy == 1)
    {
        if (c == 1)
        {
            if (vy + (mPyc - mPyp) / 20 < vm)
                vy += (mPyc - mPyp) / 20;
        }
    }
    else if (diy == -1)
    {
        if (c == 1)
        {
            if (vy + (mPyc - mPyp) / 20 > -vm)
                vy += (mPyc - mPyp) / 20;
        }
    }

    // Reduce the velocity.y
    if (vy > 0)
        vy -= 0.1;
    else if (vy < 0)
        vy += 0.1;
}

void limitV(float& vx, float& vy, int vm)
{
    if (sqrt(vx * vx + vy * vy) >= vm)
    {
        vx = vx / sqrt(2);
        vy = vy / sqrt(2);
    }
}

void makeBubblesWhenEating(Sprite p, Vector2f& playerP, bool& EB, double& bubbsT, int& dix)
{
    // bubbels
    if (EB == 1)
    {
        if (bubbsT <= 10)
        {
            if (bubbsT == 0)
            {
                bubbles[0].setScale(0.4f, 0.4f);
                playerP = p.getPosition();
                if (dix == 1)
                    bubbles[0].setPosition(playerP.x + p.getGlobalBounds().width - 15, playerP.y + p.getGlobalBounds().height / 2);
                else
                    bubbles[0].setPosition(playerP.x - 15, playerP.y + p.getGlobalBounds().height / 2);
            }
            if (bubbsT >= 0.9 && bubbsT <= 1.2)
            {
                bubbles[1].setScale(0.4f, 0.4f);
                if (dix == 1)
                    bubbles[1].setPosition(playerP.x + p.getGlobalBounds().width, playerP.y + p.getGlobalBounds().height / 2);
                else
                    bubbles[1].setPosition(playerP.x, playerP.y + p.getGlobalBounds().height / 2);
            }
            if (bubbsT >= 1.8 && bubbsT <= 2.1)
            {
                bubbles[2].setScale(0.4f, 0.4f);
                if (dix == 1)
                    bubbles[2].setPosition(playerP.x + p.getGlobalBounds().width + 20, playerP.y + p.getGlobalBounds().height / 2);
                else
                    bubbles[2].setPosition(playerP.x + 20, playerP.y + p.getGlobalBounds().height / 2);
            }
            if (bubbsT >= 2.7 && bubbsT <= 3)
            {
                bubbles[3].setScale(0.3f, 0.3f);
                if (dix == 1)
                    bubbles[3].setPosition(playerP.x + p.getGlobalBounds().width + 15, playerP.y + p.getGlobalBounds().height / 2);
                else
                    bubbles[3].setPosition(playerP.x + 15, playerP.y + p.getGlobalBounds().height / 2);
            }
            if (bubbsT >= 5.1 && bubbsT <= 5.4)
            {
                bubbles[4].setScale(0.4f, 0.4f);
                if (dix == 1)
                    bubbles[4].setPosition(playerP.x + p.getGlobalBounds().width - 5, playerP.y + p.getGlobalBounds().height / 2);
                else
                    bubbles[4].setPosition(playerP.x - 5, playerP.y + p.getGlobalBounds().height / 2);
            }


            for (int i = 0; i < 5; i++)
            {
                bubbles[i].move(0, -1);
            }
            bubbsT += 0.3;
        }
        else // bubbules die
        {
            for (int i = 0; i < 5; i++)
            {
                bubbles[i].setScale(0, 0);
            }
            bubbsT = 0;
            EB = 0;
        }
    }
}

void CollisionWithWindow(Sprite& p, RenderWindow& window, View view)
{
    // Collision with window
    if (p.getPosition().x < 0)
        p.setPosition(0, p.getPosition().y);

    if (p.getPosition().y < 127 + view.getCenter().y - view.getSize().y / 2)
        p.setPosition(p.getPosition().x, 127 + view.getCenter().y - view.getSize().y / 2);

    if (p.getPosition().x > window.getSize().x - p.getGlobalBounds().width)
        p.setPosition(window.getSize().x - p.getGlobalBounds().width, p.getPosition().y);

    if (p.getPosition().y > window.getSize().y - p.getGlobalBounds().height + (127))
        p.setPosition(p.getPosition().x, window.getSize().y - p.getGlobalBounds().height + 127);
}

void KeepMouseInWindow(Vector2f mousePosition, RenderWindow& window, Vector2f windowPo, bool& c, float& mPyc, float& mPxc)
{
    // keep mouse in window
    if (mousePosition.x > window.getSize().x - 20)
    {
        Mouse::setPosition(Vector2i(0 + windowPo.x + 30, mousePosition.y + windowPo.y + 30));
        c = 0;
    }
    if (mousePosition.x < 20)
    {
        Mouse::setPosition(Vector2i(window.getSize().x + windowPo.x - 30, mousePosition.y + windowPo.y + 30));
        c = 0;
        mPxc = Mouse::getPosition().x;
    }
    if (mousePosition.y > window.getSize().y - 50)
    {
        Mouse::setPosition(Vector2i(mousePosition.x + windowPo.x + 8, 0 + windowPo.y + 40));
        c = 0;

        mPyc = Mouse::getPosition().y;
    }
    if (mousePosition.y < 20)
    {
        Mouse::setPosition(Vector2i(mousePosition.x + windowPo.x + 8, window.getSize().y + windowPo.y - 60));
        c = 0;

        mPyc = Mouse::getPosition().y;
    }
}

void ScoreEffectControl(RenderWindow& window)
{
    // Score effect
    for (int i = 0; i < T1.size(); i++)
    {
        Vector2f dir = Vector2f(960, 0) - Vector2f(T1[i].getPosition().x, T1[i].getPosition().y);
        length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
        dir /= length;

        T1[i].move(5 * dir.x, 5 * dir.y);
        if (T1[i].getPosition().x >= 960 && T1[i].getPosition().y <= 50)
        {
            T1.erase(T1.begin() + i);
        }
    }
}

void ScoreEffectCreate(int dix, Sprite p, float x, int N)
{
    plus_10.setString("+" + to_string((int)x * N));
    if (dix == -1)
        plus_10.setPosition((p.getPosition().x) * 1.24 - 1.24 * (view.getCenter().x - view.getSize().x / 2), (p.getPosition().y + p.getGlobalBounds().height / 2) * 1.24 - 1.24 * (view.getCenter().y - view.getSize().y / 2));
    else
        plus_10.setPosition((p.getPosition().x + p.getGlobalBounds().width) * 1.24 - 1.24 * (view.getCenter().x - view.getSize().x / 2), (p.getPosition().y + p.getGlobalBounds().height / 2) * 1.24 - 1.24 * (view.getCenter().y - view.getSize().y / 2));
    T1.push_back(plus_10);
}

void CreateStars(vector<int>& count)
{
    // Create Stars
    if (spwanTimerStars == 240)
    {
        star.setPosition(rand() % (windowWidth - 40), windowHeight);
        stars.push_back(star);
        spwanTimerStars = 0;
        smallStarsTimers.push_back(0);
        counter.push_back(0);
        count.push_back(0);
        sparksTimer.push_back(0);
        countSpark1.push_back(0);
    }
    spwanTimerStars++;
}

void CreateSmallStars(vector<int>& count)
{
    // Create small Stars to Each Big Star
    for (int i = 0; i < stars.size(); i++)
    {
        if (smallStarsTimers[i] == 10)
        {
            smalStarw.setPosition(rand() % 40 + stars[i].getPosition().x - 15, stars[i].getPosition().y + 30); // set its position to Big star
            smalStary.setPosition(rand() % 40 + stars[i].getPosition().x - 15, stars[i].getPosition().y + 30); // set its position to Big star
            if (count[i] % 2 == 0)  // make a wight small star in one time
                smallStars.push_back(smalStarw);
            if (count[i] % 2 == 1) // make a yellow small star in onother time
                smallStars.push_back(smalStary);
            counter[i] += 1;
            if (counter[i] >= 8)  // start Removing small Stars after they be 8 stars
            {
                if (counter[i] % 2 == 0)
                    smallStars.erase(smallStars.begin() + 0);
                if (counter[i] % 2 == 1)
                    smallStars.erase(smallStars.begin() + 1);
                counter[i]--;
            }
            smallStarsTimers[i] = 0;
            count[i]++;
        }
    }
    for (int i = 0; i < smallStarsTimers.size(); i++)
        smallStarsTimers[i]++;
}

void CreateSparks()
{
    // Create Sparks to Each Big Star
    for (int i = 0; i < stars.size(); i++)
    {
        if (sparksTimer[i] == 30)
        {
            spark1.setPosition(rand() % 55 + stars[i].getPosition().x - 20, stars[i].getPosition().y + star.getGlobalBounds().height - 20); // set its position to Big star
            sparks1.push_back(spark1);
            countSpark1[i]++;
            // Delete Sparks
            if (countSpark1[i] > 4)
            {
                sparks1.erase(sparks1.begin() + 0);
                countSpark1[i]--;
            }
            sparksTimer[i] = 0;
        }

    }
    for (int i = 0; i < sparksTimer.size(); i++)
        sparksTimer[i]++;
}

void MoveStars_SmallStars_Sparks()
{
    // Move Stars
    for (int i = 0; i < stars.size(); i++)
    {
        stars[i].move(0, -2);
    }
    // move Small Stars
    for (int i = 0; i < smallStars.size(); i++)
    {
        smallStars[i].move(0, 1);
    }
    // move Sparks
    for (int i = 0; i < sparks1.size(); i++)
    {
        sparks1[i].move(0, -1.8);
    }
}

void EatStars(player &p, vector<int>& count, bool& E, bool& EB, int dix, int& scoreNumber, float OnFire1Score, int& starsNumberEaten)
{
    for (int i = 0; i < stars.size(); i++)
    {
        if (p.Spri.getGlobalBounds().intersects(stars[i].getGlobalBounds()))
        {
            bS.play();
            E = 1;
            EB = 1;
            stars.erase(stars.begin() + i);
            smallStarsTimers.erase(smallStarsTimers.begin() + 0);
            for (int j = 0; j < counter[i]; j++)
                smallStars.erase(smallStars.begin() + 0);
            counter.erase(counter.begin() + 0);
            count.erase(count.begin() + 0);
            b1.play();
            scoreNumber = 40;
            p.score += scoreNumber * (int)OnFire1Score;
            starsNumberEaten++;

            ScoreEffectCreate(dix, p.Spri, OnFire1Score, scoreNumber);
            for (int j = 0; j < countSpark1[i]; j++)
            {
                sparks1.erase(sparks1.begin() + 0);
            }
            countSpark1.erase(countSpark1.begin() + 0);
            sparksTimer.erase(sparksTimer.begin() + 0);
        }
    }
}

void OnFire(float& OnFire1Score, float& OnFire1ScorePrev, bool& c1, bool& c2, Sprite p, bool& OnFire1Check, int& OnFire1Timer)
{
    // checks On fire
    if (OnFire1Score >= 2 && OnFire1ScorePrev <= 2)
    {
        c1 = 1;
    }
    if (OnFire1Score >= 3 && OnFire1ScorePrev <= 3)
    {
        c2 = 1;
    }
    if (c1 == 1 || c2 == 1)
    {
        if (c1 == 1)
        {
            feddingFren.play();
            Yum.setPosition(p.getPosition().x, p.getPosition().y);
        }
        if (c2 == 1)
        {
            doubleFrenzy.play();
            Gulb.setPosition(p.getPosition().x, p.getPosition().y);
        }
        OnFire1Check = 1;
    }

    if (OnFire1Check == 1)
    {
        if (OnFire1Timer <= 60)
        {
            OnFire1Timer++;
            if (c1 == 1)
                Yum.setScale(1, 1);
            if (c2 == 1)
                Gulb.setScale(1, 1);
        }
        else
        {
            Yum.setScale(0, 0);
            Gulb.setScale(0, 0);
            OnFire1Timer = 0;
            OnFire1Check = 0;
        }
    }
    // Reducing OnFire Score by Time
    if (OnFire1Score - 0.002 > 1)
        OnFire1Score -= 0.002;

    // Reset Checks
    c1 = 0;
    c2 = 0;

    // Texture Number Of X
    OnFireText.setString(to_string((int)OnFire1Score) + "x");
    if ((int)OnFire1Score == 2)
        OnFireText.setFillColor(Color::Green);
    else if ((int)OnFire1Score == 3)
        OnFireText.setFillColor(Color::Red);
    else if ((int)OnFire1Score == 1)
        OnFireText.setFillColor(Color::White);
}

void PerfectDisplay(Music& music)
{
    for (int i = 0; i < endPerfect; i++)
    {
        Perfect[i].setScale(1, 1);
        Bubs[i].setScale(1.5, 1.5);
        if (Perfect[i].getPosition().y < 520)
        {
            Perfect[i].move(0, 0.4);
            Bubs[i].move(0, 0.4);
        }
    }
    if (PerfectTime >= 20)
    {
        if (endPerfect < 7)
            endPerfect++;
        PerfectTime = 0;
    }
    if (winingTime == 1)
    {
        winSound.play();
    }
    music.stop();
}

void SorryDisplay(Music& music)
{
    for (int i = 0; i < endSorry; i++)
    {
        Sorry[i].setScale(1, 1);
        Bubs1[i].setScale(1.5, 1.5);
        if (Sorry[i].getPosition().y < 520)
        {
            Sorry[i].move(0, 0.4);
            Bubs1[i].move(0, 0.4);

        }
    }
    if (SorryTime >= 20)
    {
        if (endSorry < 5)
            endSorry++;
        SorryTime = 0;
    }
    if (LosingTime == 1)
    {
        losSound.play();
    }
    music.stop();
}

void Turbo(float vx, float vy)
{
    // Turbo
    if (Mouse::isButtonPressed(Mouse::Left) && TurboCheck == 0)
    {
        TurboCheck = 1;

        // direction
        turboVelocity = Vector2f(vx / sqrt(vx * vx + vy * vy), vy / sqrt(vx * vx + vy * vy));

        turboVelocity.x = turboVelocity.x * 8;
        turboVelocity.y = turboVelocity.y * 8;
        dashSound.play();
    }



    if (TurboCheck == 1)
    {
        TurboTime++;
        if (TurboTime < 50)
        {
            // reducing turbo Velocity
            if (turboVelocity.x > 0)
                turboVelocity.x -= 0.15;
            else
                turboVelocity.x += 0.15;
            if (turboVelocity.y > 0)
                turboVelocity.y -= 0.15;
            else
                turboVelocity.y += 0.15;
        }
        else
        {
            turboVelocity.x = 0;
            turboVelocity.y = 0;
            TurboTime = 0;
            TurboCheck = 0;
        }
    }
}

void VIEW(Sprite p, float vx, float vy, Sprite& item1, Sprite& item2, Sprite& item3, Sprite& item4, Sprite& item5)
{
    // Moving view
    if (p.getPosition().x > view.getCenter().x + view.getSize().x / 4 && view.getCenter().x < windowWidth - (view.getSize().x / 2) - 8)
    {
        if (vx > 0)
        {
            view.move(vx, 0);
            item1.move(-vx / 3.f, 0);
            item2.move(-vx / 3.f, 0);
            item3.move(-vx / 3.f, 0);
            item4.move(-vx / 3.f, 0);
            item5.move(-vx / 3.f, 0);
        }

    }
    if (p.getPosition().y > view.getCenter().y + view.getSize().y / 4 && view.getCenter().y < windowHeight - (view.getSize().y / 2) + 127 - 5)
    {
        if (vy > 0)
            view.move(0, vy);
    }
    if (p.getPosition().x < view.getCenter().x - view.getSize().x / 4 && view.getCenter().x >(view.getSize().x / 2) + 5)
    {
        if (vx < 0)
        {
            view.move(vx, 0);
            item1.move(-vx / 3.f, 0);
            item2.move(-vx / 3.f, 0);
            item3.move(-vx / 3.f, 0);
            item4.move(-vx / 3.f, 0);
            item5.move(-vx / 3.f, 0);
        }
    }
    if (p.getPosition().y < view.getCenter().y - view.getSize().y / 4 && view.getCenter().y >(view.getSize().y / 2) + 10)
    {
        if (vy < 0)
            view.move(0, vy);
    }

}

//main
int main() {

    RenderWindow window(VideoMode(1280, 960), "Frenzy Fish", Style::Fullscreen);
    srand(NULL);
    window.setFramerateLimit(60);

    // Tony Code -------------------------------------------------------------------------------------
    Font font;
    if (!font.loadFromFile("SuperMario256.ttf")) {
        return EXIT_FAILURE;
    }

    string name;

    Texture textures[23];
    textures[0].loadFromFile("menu1.png");
    textures[1].loadFromFile("title.png");
    textures[2].loadFromFile("1.png");
    textures[3].loadFromFile("exit1.png");
    textures[4].loadFromFile("3.png");
    textures[5].loadFromFile("highscore1.png");
    textures[6].loadFromFile("l1selected.png");
    textures[7].loadFromFile("l1selected.png");
    textures[8].loadFromFile("2.png");
    textures[9].loadFromFile("exit2.png");
    textures[10].loadFromFile("gameoptions2.png");
    textures[11].loadFromFile("highscore2.png");
    textures[12].loadFromFile("l1unselected.png");
    textures[13].loadFromFile("l1unselected.png");
    textures[14].loadFromFile("menu1.png");
    textures[15].loadFromFile("menu1.png");
    textures[16].loadFromFile("level 2.png");
    textures[17].loadFromFile("pause.png");
    textures[18].loadFromFile("mute.png");
    textures[19].loadFromFile("unmute.jpg");
    textures[20].loadFromFile("level3.png");
    textures[21].loadFromFile("l1selected.png");
    textures[22].loadFromFile("l1unselected.png");

    // Create sprites
    Sprite sprites[23];
    sprites[0].setOrigin(319.5, 240);
    sprites[1].setOrigin(103, 41);
    sprites[14].setOrigin(319.5, 240);
    sprites[16].setOrigin(398.5, 300);
    sprites[17].setOrigin(226, 195.5);
    sprites[20].setOrigin(398.5, 300);

    Vector2f positions[23] = {
        Vector2f(640,480),  //0
        Vector2f(640,150),  //1
        Vector2f(400,300),  //2
        Vector2f(800,700),  //3
        Vector2f(800,450),  //4
        Vector2f(400,600),  //5
        Vector2f(450,230),  //6
        Vector2f(750,710),  //7
        Vector2f(400,300),  //8
        Vector2f(800,700),  //9
        Vector2f(800,450),  //10
        Vector2f(400,600),  //11
        Vector2f(450,230),  //12
        Vector2f(750,710),  //13
        Vector2f(640,240),  //14
        Vector2f(300,300),  //15
        Vector2f(960,750),  //16
        Vector2f(640,480),  //17
        Vector2f(700,370),  //18
        Vector2f(700,370),  //19
        Vector2f(300,750),  //20
        Vector2f(100,700),  //21
        Vector2f(100,700),  //22
    };
    Vector2f scales[23] = {
        Vector2f(2,2),         //0                             
        Vector2f(2,2),         //1     
        Vector2f(1.6,1.6),     //2 
        Vector2f(1.7,1.7),     //3 
        Vector2f(1.7,1.7),     //4 
        Vector2f(1.7,1.7),     //5 
        Vector2f(3.1,2.4),     //6 
        Vector2f(3.1,2.4),     //7 
        Vector2f(1.6,1.6),     //8 
        Vector2f(1.7,1.7),     //9 
        Vector2f(1.7,1.7),     //10 
        Vector2f(1.7,1.7),     //11 
        Vector2f(3.1,2.4),     //12 
        Vector2f(3.1,2.4),     //13 
        Vector2f(2,1.2),       //14     
        Vector2f(1,1),         //15 
        Vector2f(0.9,0.74),    //16 
        Vector2f(2.8,2.4),     //17 
        Vector2f(0.5,0.5),     //18 
        Vector2f(0.3,0.3),     //19 
        Vector2f(0.75,0.74),   //20 
        Vector2f(3.1,2.4),     //21 
        Vector2f(3.1,2.4),     //22 
    };
    setSprites(sprites, textures, positions, scales, 23);

    // Create buttons
    bool b1l = 0, b2l = 0, b3l = 0, b4l = 0;
    bool b5l = 0, b6l = 0, b12l = 0;
    bool b7l = 0, b8l = 0, b9l = 0, b10l = 0;
    bool b11l = 0, b20l = 0;


    Text continueButton = createButton("Continue", font, 60, Color::White, 400, 300);
    Text exitButton = createButton("Exit", font, 50, Color::White, 400, 600);
    Text l1Button = createButton("     Level 1\n(Sunken Treasure)", font, 35, Color::Blue, 480, 240);
    Text l2Button = createButton("   level 2\n(pottery cave)", font, 40, Color::Blue, 140, 710);
    Text l3Button = createButton(" Level 3\n(Deap Sea)", font, 40, Color::Blue, 850, 720);
    Text mainmenuButton = createButton("Main Menu", font, 55, Color::White, 400, 400);
    Text levelButton = createButton("Levels", font, 55, Color::White, 400, 500);
    Text muteButton = createButton("Mute", font, 35, Color::White, 400, 400);
    Text escapeButton = createButton("Press ESC to go back", font, 20, Color::White, 20, 30);
    Text Pbutton = createButton("Press p to pause", font, 20, Color::White, 30, 930);


    // Music
    Music music;
    music.openFromFile("Feeding-Frenzy-Track-1.ogg");
    music.play();
    bool isMuted = false;
    double mt = 0;


    // mouse
    RectangleShape mouse;
    mouse.setSize(Vector2f(10, 10));

    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------


    // Sohaib Diclarations ---------------------------------------------------------------------------------------------
    view.setCenter(windowWidth / 2, windowHeight / 2);

    // BackGround
    Texture back;
    if (!back.loadFromFile("sea1.png"))
        return EXIT_FAILURE;
    Sprite b;
    b.setTexture(back);
    b.setPosition(0, 127);

    // Players

     // player 1
    Texture player1;
    if (!player1.loadFromFile("p.png"))
        return EXIT_FAILURE;
    players[0].Spri.setTexture(player1);
    float pwi1 = 122, phe1 = 104;     // player1  ( width, height )
    players[0].Spri.setTextureRect(IntRect(2, 425 / 2, 125, 105));
    float x = 0;    // counter of animation
    players[0].Spri.setScale(0.7, 0.7);
    players[0].Spri.setPosition(windowWidth / 2, windowHeight / 2);


    Texture player3;
    if (!player3.loadFromFile("p3.png"))
        return EXIT_FAILURE;
    players[2].Spri.setTexture(player3);
    int pwi3 = 186, phe3 = 166;     // player3  ( width, height )
    players[2].Spri.setScale(0.7, 0.7);




    Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

    // Mouse Position Declaration (current , previous)
    float mPxc, mPxp = 0;
    float mPyc, mPyp = 0;
    // check if the mouse is out of window
    bool c = 1;


    // Direction of moving
    int dix = 0, diy = 0;

    // velocity
    float vx = 0, vy = 0, vmx = 12, vmy = 8;

    //Turn
    double xr = 0, xl = 0;
    bool Tr = 0, Tl = 0;


    // Fish 1
    int const fN = 25;  // Nomber of fish
    std::vector<CircleShape> a;
    for (int i = 0; i < fN; ++i)
    {
        sf::CircleShape circle(16); // Radius of 20
        circle.setFillColor(Color::Red); // Set color
        circle.setPosition(std::rand() % windowWidth, std::rand() % windowHeight); // Random position
        a.push_back(circle);
    }
    double Vx[fN];
    double Vy[fN];
    float spwanT[fN] = { 0 };
    for (int i = 0; i < fN; i++)
    {
        spwanT[i] = 60;
    }
    int f1NumberEaten = 0, f2NumberEaten = 0, f3NumberEaten = 0, starsNumberEaten = 0;


    // score effect
    Font font1;
    if (!font1.loadFromFile("Sunny Spells Basic.ttf"))
        return EXIT_FAILURE;

    plus_10.setFont(font1);
    plus_10.setCharacterSize(45);
    plus_10.setFillColor(Color::White);
    plus_10.setString("+10");

    plus_20.setFont(font1);
    plus_20.setCharacterSize(45);
    plus_20.setFillColor(Color::White);
    plus_20.setString("+20");

    plus_30.setFont(font1);
    plus_30.setCharacterSize(45);
    plus_30.setFillColor(Color::White);
    plus_30.setString("+30");


    int scoreNumber;


    // Effects Sprite Sheet
    Texture Effects;
    if (!Effects.loadFromFile("Effects.png"))
        return EXIT_FAILURE;

    // Effects Onfire
    float OnFire1Score = 1, OnFire1ScorePrev = 1;
    bool OnFire1Check = 0;
    int OnFire1Timer = 0;

    Yum.setTexture(Effects);
    Yum.setTextureRect(IntRect(745, 2, 107, 90));

    Gulb.setTexture(Effects);
    Gulb.setTextureRect(IntRect(344, 2, 169, 138));
    Gulb.setScale(0, 0);



    // Feeding Frenzy Sound
    SoundBuffer buf;
    if (!buf.loadFromFile("feedingFrenzy.wav"))
        return EXIT_FAILURE;

    feddingFren.setBuffer(buf);
    feddingFren.setVolume(50);

    // Feshing Frenzy Sound
    SoundBuffer Double;
    if (!Double.loadFromFile("doubleFrenzy.wav"))
        return EXIT_FAILURE;

    doubleFrenzy.setBuffer(Double);
    doubleFrenzy.setVolume(50);
    bool c1 = 0, c2 = 0, c3 = 0;

    // On Fire Score
    Font fontOnfire;
    if (!fontOnfire.loadFromFile("Reach-Fill.ttf"))
        return EXIT_FAILURE;

    OnFireText.setFont(fontOnfire);
    OnFireText.setCharacterSize(40);
    OnFireText.setString(to_string((int)OnFire1Score) + "X");
    OnFireText.setPosition(1200, 30);
    // Stars effect
    Texture Bonus;
    if (!Bonus.loadFromFile("Bonus.png"))
        return EXIT_FAILURE;

    star.setTexture(Bonus);
    star.setTextureRect(IntRect(2, 272, 38, 40));
    star.setScale(1.5, 1.5);


    // Small Stars
    smalStarw.setTexture(Effects);
    smalStarw.setTextureRect(IntRect(3, 166, 28, 30));
    smalStary.setTexture(Effects);
    smalStary.setTextureRect(IntRect(3, 200, 28, 30));
    vector<int> count;   // Number of All smallStars created


    // Sparks
    Texture spark1Texture;
    if (!spark1Texture.loadFromFile("spark2.png"))
        return EXIT_FAILURE;
    spark1.setTexture(spark1Texture);
    //spark1.setScale(0.16, 0.16);



    // Sound when Eating A Star
    SoundBuffer buff;
    if (!buff.loadFromFile("starPickup.wav"))
        return EXIT_FAILURE;
    bS.setBuffer(buff);



    // Sound When Eating Fish 1
    SoundBuffer buffer;
    if (!buffer.loadFromFile("bite1.wav"))
        return EXIT_FAILURE;
    b1.setBuffer(buffer);

    // Music
    Music music1;
    if (!music1.openFromFile("Feeding-Frenzy-Track-1.ogg"))
        return EXIT_FAILURE;

    //music1.play();
    double mt1 = 0;

    // Time
    Clock clock, clo;
    double dt = 0;

    // check eating
    bool EatingCheck = 0;

    // Position of window
    Vector2f windowPo(window.getPosition().x, window.getPosition().y);

    // Bubbles effect when eating fish
    Texture bub1T;
    if (!bub1T.loadFromFile("bubble2.png"))
        return EXIT_FAILURE;

    bubble.setTexture(bub1T);
    bubble.setScale(0, 0);
    for (int i = 0; i < 5; i++)
    {
        bubbles[i] = bubble;
    }

    double eT = 0;
    double bubbsT = 0;  // Bubbles Time
    bool EB = 0;        // Bubbles when eating check

    // Bubbles In Back
    int Ti = 0;
    bubble2.setTexture(bub1T);
    vector<float> bubbleScale;

    // player position
    Vector2f playerP;

    // rock
    Texture Back1T;
    if (!Back1T.loadFromFile("back 1 t.png"))
        return EXIT_FAILURE;

    Sprite ro;
    ro.setTexture(Back1T);
    ro.setTextureRect(IntRect(0, 0, 390, 108));
    ro.setPosition(500, window.getSize().y - 108 + 127);

    Sprite ro2;
    ro2 = ro;
    ro2.setPosition(-100, ro2.getPosition().y);

    // Coral reefs
    Sprite coral1;
    coral1.setTexture(Back1T);
    coral1.setTextureRect(IntRect(138, 111, 182, 115));
    coral1.setPosition(650, windowHeight - 160 + 127);

    Sprite coral2;
    coral2.setTexture(Back1T);
    coral2.setTextureRect(IntRect(322, 117, -180, 110));
    coral2.setPosition(530, windowHeight - 160 + 127);

    Sprite coral3;
    coral3 = coral1;
    coral3.setScale(1.3, 1.3);
    coral3.setPosition(200, windowHeight);

    Sprite coral4;
    coral4 = coral2;
    coral4.setScale(0.8, 0.8);
    coral4.setPosition(800, windowHeight + 50);

    // Shrub 
    Sprite shrub;
    shrub.setTexture(Back1T);
    shrub.setTextureRect(IntRect(0, 239, 137, 252));
    shrub.setPosition(0, 840);



    // Wining

        // Wining Sound
    SoundBuffer winBuf;
    winBuf.loadFromFile("stageClear.wav");
    winSound.setBuffer(winBuf);
    bool winSoundCheck = 0;

    // Bubbles
    Texture BigBubble;
    BigBubble.loadFromFile("bub.png");
    Bubs[0].setTexture(BigBubble);
    Bubs[0].setOrigin(Bubs[0].getGlobalBounds().width / 2, Bubs[0].getGlobalBounds().height / 2);

    // Perfect letters

    Perfect[0].setCharacterSize(100);
    Perfect[0].setFont(font1);
    Perfect[0].setString("P");
    Perfect[0].setFillColor(Color::Red);
    Perfect[0].setOrigin(Perfect[0].getGlobalBounds().width / 2, Perfect[0].getGlobalBounds().height / 2);
    Perfect[0].setPosition(301, 505);
    Perfect[0].setScale(0, 0);
    Bubs[0].setScale(0, 0);
    Bubs[0].setPosition(301, 545);

    for (int i = 1; i < 7; i++)
    {
        Bubs[i] = Bubs[0];
        Bubs[i].setPosition(Bubs[0].getPosition().x + (113 * i), 545);
        Perfect[i] = Perfect[0];
        Perfect[i].setPosition(Perfect[0].getPosition().x + (113 * i), 505);
    }

    Perfect[1].setString("E");
    Perfect[2].setString("R");
    Perfect[3].setString("F");
    Perfect[4].setString("E");
    Perfect[5].setString("C");
    Perfect[6].setString("T");


    // Losing

        // Losing Sound
    SoundBuffer losBuf;
    losBuf.loadFromFile("gameOver.wav");
    losSound.setBuffer(losBuf);
    bool losSoundCheck = 0;

    // Bubbles
    Bubs1[0].setTexture(BigBubble);
    Bubs1[0].setOrigin(Bubs1[0].getGlobalBounds().width / 2, Bubs1[0].getGlobalBounds().height / 2);

    // Sorry letters

    Sorry[0].setCharacterSize(100);
    Sorry[0].setFont(font1);
    Sorry[0].setString("S");
    Sorry[0].setFillColor(Color::Red);
    Sorry[0].setOrigin(Sorry[0].getGlobalBounds().width / 2, Sorry[0].getGlobalBounds().height / 2);
    Sorry[0].setPosition(340, 505);
    Sorry[0].setScale(0, 0);
    Bubs1[0].setScale(0, 0);
    Bubs1[0].setPosition(340, 545);

    for (int i = 1; i < 5; i++)
    {
        Bubs1[i] = Bubs1[0];
        Bubs1[i].setPosition(Bubs1[0].getPosition().x + (113 * i), 545);
        Sorry[i] = Sorry[0];
        Sorry[i].setPosition(Sorry[0].getPosition().x + (113 * i), 505);
    }

    Sorry[1].setString("O");
    Sorry[2].setString("R");
    Sorry[3].setString("R");
    Sorry[4].setString("Y");


    // Turbo


    SoundBuffer dashBuff;
    if (!dashBuff.loadFromFile("playerDash.wav"))
        return EXIT_FAILURE;

    dashSound.setBuffer(dashBuff);


    // Result Screen

        //board
    Texture boardText;
    if (!boardText.loadFromFile("levels.png"))
        return EXIT_FAILURE;
    Sprite resultBoard(boardText);
    resultBoard.setOrigin(resultBoard.getGlobalBounds().width / 2, resultBoard.getGlobalBounds().height / 2);
    resultBoard.setPosition(640, 480);
    resultBoard.setScale(0, 0);

    // Title
    Texture TitleTexture;
    if (!TitleTexture.loadFromFile("title.png"))
        return EXIT_FAILURE;
    Sprite Title(TitleTexture);
    Title.setOrigin(Title.getGlobalBounds().width / 2, Title.getGlobalBounds().height / 2);
    Title.setPosition(670, 115);
    Title.setScale(0, 0);

    // Fishs
    Sprite enemeisBoard[9];
    Texture ememeisBoardTex[9];

    if (!ememeisBoardTex[0].loadFromFile("f.png"))
        return EXIT_FAILURE;
    if (!ememeisBoardTex[1].loadFromFile("f2.png"))
        return EXIT_FAILURE;
    if (!ememeisBoardTex[2].loadFromFile("f3.png"))
        return EXIT_FAILURE;
    for (int i = 0; i < 9; i++)
    {
        enemeisBoard[i].setTexture(ememeisBoardTex[i]);
        enemeisBoard[i].setOrigin(enemeisBoard[i].getGlobalBounds().width / 2, enemeisBoard[i].getGlobalBounds().width / 2);
        enemeisBoard[i].setScale(0, 0);
    }

    enemeisBoard[0].setPosition(260, 400);
    enemeisBoard[1].setPosition(480, 400);
    enemeisBoard[2].setPosition(700, 390);



    // Star
    Sprite starBoard;
    starBoard.setTexture(Bonus);
    starBoard.setTextureRect(IntRect(2, 272, 38, 40));
    starBoard.setOrigin(starBoard.getGlobalBounds().width / 2, starBoard.getGlobalBounds().height / 2);
    starBoard.setScale(0, 0);
    starBoard.setPosition(1000, 400);

    //font
    Text stageCompleted;
    stageCompleted.setFont(font1);
    stageCompleted.setString("STAGE COMPLETE!");
    stageCompleted.setCharacterSize(100);
    stageCompleted.setPosition(350, 200);
    stageCompleted.setScale(0, 0);


    Text numbersEatenText[12];
    for (int i = 0; i < 12; i++)
    {
        numbersEatenText[i].setFont(font1);
        numbersEatenText[i].setOrigin(numbersEatenText[i].getGlobalBounds().width / 2, numbersEatenText[i].getGlobalBounds().height / 2);
        numbersEatenText[i].setScale(0, 0);
    }
    numbersEatenText[0].setPosition(250, 430);
    numbersEatenText[1].setPosition(470, 430);
    numbersEatenText[2].setPosition(680, 430);

    Text numberStarsEatenText;
    numberStarsEatenText.setFont(font1);
    numberStarsEatenText.setPosition(990, 435);
    numberStarsEatenText.setScale(0, 0);

    // Chomp
    Sprite Chomp;
    Chomp.setTexture(Effects);
    Chomp.setTextureRect(IntRect(517, 2, 107, 89));
    Chomp.setOrigin(Chomp.getGlobalBounds().width / 2, Chomp.getGlobalBounds().height / 2);
    Chomp.setScale(0.8, 0.8);

    // Time
    int resultTime = 0;



    // Abdo Declarations ==================================================================================
    sf::RectangleShape rectangle(sf::Vector2f(1280.f, 150.f));
    rectangle.setFillColor(sf::Color(40, 120, 100));
    ////////
    Color lineColor = Color::Black;
    RectangleShape line(Vector2f(1280, 5));
    line.setFillColor(lineColor);
    line.setPosition(0, 150);
    RectangleShape line_GROWTH(Vector2f(350, 15));
    line_GROWTH.setFillColor(lineColor);
    line_GROWTH.setPosition(200, 110);

    RectangleShape line_ABILITY(Vector2f(220, 15));
    line_ABILITY.setFillColor(lineColor);
    line_ABILITY.setPosition(900, 110);

    ConvexShape triangle;
    triangle.setPointCount(3); //  number of points 
    triangle.setPoint(0, sf::Vector2f(260, 135));
    triangle.setPoint(1, sf::Vector2f(280, 135));
    triangle.setPoint(2, sf::Vector2f(270, 120));
    triangle.setFillColor(sf::Color::Red);
    ////////
    ConvexShape triangle2;
    triangle2.setPointCount(3);
    triangle2.setPoint(0, sf::Vector2f(400, 135));
    triangle2.setPoint(1, sf::Vector2f(420, 135));
    triangle2.setPoint(2, sf::Vector2f(410, 120));
    triangle2.setFillColor(sf::Color::Red);

    Texture score_tab;
    score_tab.loadFromFile("score_tab.png");
    Sprite tab[4];
    tab[0].setTexture(score_tab);
    tab[0].setColor(Color::Black);
    tab[0].setPosition(900, 30);
    tab[0].setScale(1.8f, 1.5f);
    for (int i = 1; i < 4; i++)
        tab[i] = tab[0];
    tab[1].setPosition(900, 30);
    tab[2].setPosition(960, 30);
    tab[3].setPosition(960, 30);

    ////////
    Texture double_tab;
    double_tab.loadFromFile("score_tab.png");
    Sprite Doublect(double_tab);
    Doublect.setColor(Color::Black);
    Doublect.setPosition(1200, 30);
    Doublect.setScale(0.4f, 1.5f);

    Texture double_tab2;
    double_tab2.loadFromFile("score_tab.png");
    Sprite Doublect2(double_tab);
    Doublect2.setColor(Color::Black);
    Doublect2.setPosition(1200, 30);
    Doublect2.setScale(0.4f, 1.5f);

    RectangleShape triple_tab(Vector2f(25, 25));
    triple_tab.setFillColor(lineColor);
    triple_tab.setPosition(1200, 110);

    /////////
    Texture bub1;
    bub1.loadFromFile("bub.png");
    Sprite Bub(bub1);
    Bub.setColor(Color::Blue);
    Bub.setScale(1.5f, 1.2f);
    Bub.setPosition(300, 25);
    //////////
    Texture bub2;
    bub2.loadFromFile("bub.png");
    Sprite Bub2(bub2);
    Bub2.setScale(1.5f, 1.3f);
    Bub2.setColor(Color::Blue);
    Bub2.setPosition(420, 20);

    Texture fish1;
    if (!fish1.loadFromFile("fish1.png")) {
        cout << "Failed to load image!" << std::endl;
        return 1;
    }


    Sprite sprite1(fish1);
    sprite1.setScale(1.3f, 1.3f);
    // set the position of photo
    sprite1.setPosition(180, 35);
    ///////////////
    Texture fish2;
    fish2.loadFromFile("fish2.png");
    Sprite sprite2(fish2);
    sprite2.setScale(0.6f, 0.6f);
    sprite2.setPosition(300, 40);
    ////////////////
    Texture fish3;
    fish3.loadFromFile("fish3.png");
    Sprite sprite3(fish3);
    sprite3.setScale(0.5f, 0.5f);
    sprite3.setPosition(420, 20);


    Font tab_font;

    if (!tab_font.loadFromFile("PermanentMarker-Regular.ttf")) {
        cout << "faild to load font  " << endl;
        return 1;
    }
    Text menu;
    menu.setFont(tab_font);
    menu.setString("MENU");
    menu.setCharacterSize(25);
    menu.setFillColor(Color(200, 255, 255));
    menu.setPosition(80, 40);

    Text GROWTH;
    GROWTH.setFont(tab_font);
    GROWTH.setString("GROWTH");
    GROWTH.setCharacterSize(25);
    GROWTH.setFillColor(Color(200, 255, 255));
    GROWTH.setPosition(80, 100);

    Text SCORE;
    SCORE.setFont(tab_font);
    SCORE.setString("SCORE");
    SCORE.setCharacterSize(25);
    SCORE.setFillColor(Color(200, 255, 255));
    SCORE.setPosition(800, 40);
    Text SCORE_0;
    SCORE_0.setFont(tab_font);
    SCORE.setCharacterSize(30);
    SCORE_0.setString("0");
    SCORE_0.setPosition(1080, 40);


    Text ABILTY;
    ABILTY.setFont(tab_font);
    ABILTY.setString("ABILTY");
    ABILTY.setCharacterSize(25);
    ABILTY.setFillColor(Color(200, 255, 255));
    ABILTY.setPosition(800, 100);
    //////////////////////
    RectangleShape hb;
    hb.setFillColor(Color::Yellow);
    hb.setPosition(200, 110);
    // ===========================================================================================

    while (window.isOpen()) {

        Event event;
        // Game loop
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            mouse.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

            // Start Menu event handling

            if (gameState == 0)
            {
                b1l = 0;
                b2l = 0;
                b3l = 0;
                b4l = 0;
                b20l = 0;

                if (mouse.getGlobalBounds().intersects(sprites[2].getGlobalBounds()))
                    b1l = 1;

                if (b1l == 1 && Mouse::isButtonPressed(Mouse::Left))//enter player name
                    gameState = 3;
                if (mouse.getGlobalBounds().intersects(sprites[3].getGlobalBounds()))
                    b2l = 1;

                if (b2l == 1 && Mouse::isButtonPressed(Mouse::Left))
                    window.close();
                if (mouse.getGlobalBounds().intersects(sprites[4].getGlobalBounds()))
                    b3l = 1;

                if (b3l == 1 && Mouse::isButtonPressed(Mouse::Left))//game optins
                    gameState = 1;
                if (mouse.getGlobalBounds().intersects(sprites[5].getGlobalBounds()))
                    b4l = 1;

                if (b4l == 1 && Mouse::isButtonPressed(Mouse::Left))//level two
                    gameState = 6;

                if (mouse.getGlobalBounds().intersects(sprites[11].getGlobalBounds()))
                    b20l = 1;

                if (b20l == 1 && Mouse::isButtonPressed(Mouse::Left))//level two
                    gameState = 2;
            }
            //Take player name
            if (gameState == 3) {
                Pname(window, name);
            }
            if (gameState == 2) {
                His(window, gameState);
            }
            //show levels
            if (gameState == 4)
            {
                b5l = 0;
                b6l = 0;
                b12l = 0;



                if (mouse.getGlobalBounds().intersects(sprites[12].getGlobalBounds()))
                    b5l = 1;
                if (b5l == 1 && Mouse::isButtonPressed(Mouse::Left))//level one
                    gameState = 5;

                if (mouse.getGlobalBounds().intersects(sprites[22].getGlobalBounds()))
                    b12l = 1;
                if (b12l == 1 && Mouse::isButtonPressed(Mouse::Left))//level two
                    gameState = 6;

                if (mouse.getGlobalBounds().intersects(sprites[13].getGlobalBounds()))
                    b6l = 1;
                if (b6l == 1 && Mouse::isButtonPressed(Mouse::Left))//level 3
                    gameState = 7;

            }
            //level one
            if (gameState == 5 || gameState == 6 || gameState == 7)
            { // Game event handling
                if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::P || event.key.code == Keyboard::Escape)
                    {
                        gameState = 8; // Pause the game
                    }
                }
            }

            //Game Options
            if (gameState == 1)
            {
                b11l = 0;
                setSelected(muteButton, false);

                if (mouse.getGlobalBounds().intersects(muteButton.getGlobalBounds())) {
                    b11l = 1;
                    setSelected(muteButton, true);
                }
                if (b11l == 1 && Mouse::isButtonPressed(Mouse::Left)) {
                    // Toggle between mute and unmute when the mute button is pressed
                    isMuted = !isMuted;
                    // Set the text color of the mute button based on the mute state
                    setSelected(muteButton, isMuted);

                    if (isMuted)
                    {
                        music.pause();
                    }
                    else
                    {
                        music.play();
                    }
                }
                else if (exitButton.getFillColor() == Color::Yellow)
                {
                    window.close();
                }
                else if (event.key.code == Keyboard::Escape)
                {
                    gameState = 0;//menu
                }

            }

            // Pause Menu 
            if (gameState == 8)
            {
                b7l = 0;
                b8l = 0;
                b9l = 0;
                b10l = 0;
                setSelected(continueButton, false);
                setSelected(exitButton, false);
                setSelected(mainmenuButton, false);
                setSelected(levelButton, false);

                if (mouse.getGlobalBounds().intersects(continueButton.getGlobalBounds())) {
                    b7l = 1;
                    setSelected(continueButton, true);
                }
                if (b7l == 1 && Mouse::isButtonPressed(Mouse::Left))
                    gameState = tempState;  //return to the game

                if (mouse.getGlobalBounds().intersects(mainmenuButton.getGlobalBounds())) {
                    b8l = 1;
                    setSelected(mainmenuButton, true);
                }
                if (b8l == 1 && Mouse::isButtonPressed(Mouse::Left))
                    gameState = 0;//menu

                if (mouse.getGlobalBounds().intersects(levelButton.getGlobalBounds())) {
                    b9l = 1;
                    setSelected(levelButton, true);
                }
                if (b9l == 1 && Mouse::isButtonPressed(Mouse::Left))
                    gameState = 4;//show levels

                if (mouse.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
                    b10l = 1;
                    setSelected(exitButton, true);
                }
                if (b10l == 1 && Mouse::isButtonPressed(Mouse::Left))
                    window.close();
            }
            window.setMouseCursorVisible(true);
        }

        // Game logic
        if (gameState == 5)
        {
            tempState = 5;
            if (1)  // Still in game condition
            {
                // Make mouse unvisible
                window.setMouseCursorVisible(false);

                // delta time
                dt = clock.restart().asSeconds();

                mt1++;
                //// Music
                //if (mt >= 72)
                //{
                //    music1.play();
                //    mt = 0;
                //}


                x += 0.09;
                if (x >= 15)
                    x = 0;

                Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);



                mPxc = mousePosition.x;
                mPyc = mousePosition.y;


                direction(mPxc, mPxp, mPyc, mPyp, c, dix, diy, Tr, Tl);


                // Moving
                // X

                velocity_x(dix, c, mPxc, mPxp, vmx, vx);

                if (dix == 1 && c == 1)
                    players[0].Spri.setTextureRect(IntRect(125 + (int)x * 126, 214, -pwi1, phe1));
                else if (dix == -1 && c == 1)
                    players[0].Spri.setTextureRect(IntRect(3 + (int)x * 126, 214, pwi1, phe1));


                // Y

                velocity_y(diy, c, mPyc, mPyp, vmy, vy);

                // Limit Velocity
                limitV(vx, vy, vmx);




                // Perform a Turn
                if (Tr == 1)
                {
                    if (xr > 4)
                    {
                        xr = 0;
                        Tr = 0;
                    }
                    else
                    {
                        xr += 0.3;
                        players[0].Spri.setTextureRect(IntRect(3 + (int)xr * 126, 320, pwi1, phe1));
                    }

                }
                if (Tl == 1)
                {
                    if (xl > 4)
                    {
                        xl = 0;
                        Tl = 0;
                    }
                    else
                    {
                        xl += 0.3;
                        players[0].Spri.setTextureRect(IntRect(124 + (int)xl * 126, 320, -pwi1, phe1));
                    }
                }


                // Turbo
                if(mt1 > 100)
                Turbo(vx, vy);
                mt1++;

                // Collision with window
                CollisionWithWindow(players[0].Spri, window, view);


                // Collision with fish
                if (EatingCheck == 1)
                {
                    // eating animation
                    if (eT <= 6)
                    {
                        if (dix == -1)
                        {
                            players[0].Spri.setTextureRect(IntRect(2 + (int)eT * 126, 2, 122, 104));
                        }
                        else if (dix == 1)
                        {
                            players[0].Spri.setTextureRect(IntRect(125 + (int)eT * 126, 2, -122, 104));
                        }
                        eT += 0.3;
                    }
                    else
                    {
                        EatingCheck = 0;
                        eT = 0;
                    }
                }

                makeBubblesWhenEating(players[0].Spri, playerP, EB, bubbsT, dix);


                // Bubbles In Back----------------------------------------------------
                Ti++;
                if (Ti == 60)
                {
                    Ti = 0;
                    bubble2.setPosition(rand() % windowWidth, rand() % windowHeight);
                    BubblesInBack.push_back(bubble2);
                    bubbleScale.push_back(0.6);
                }

                for (int i = 0; i < BubblesInBack.size(); i++)
                {
                    BubblesInBack[i].move(-1, 0);
                    BubblesInBack[i].setScale(bubbleScale[i], bubbleScale[i]);
                    bubbleScale[i] -= 0.003;
                    if (bubbleScale[i] < 0.3)
                        bubbleScale[i] = 0;
                }

                // Stars---------------------------------------------------------------

                    // Create Stars
                CreateStars(count);

                // Create small Stars to Each Big Star
                CreateSmallStars(count);

                // Create Sparks to Each Big Star
                CreateSparks();

                // Move Stars
                // move Small Stars
                // move Sparks
                MoveStars_SmallStars_Sparks();


                // Eat Stars
                EatStars(players[0], count, EatingCheck, EB, dix, scoreNumber, OnFire1Score, starsNumberEaten);


                //f1----------------------------------------------------------------------
                for (int i = 0; i < a.size(); i++)
                {
                    // collision with player
                    if (players[0].Spri.getGlobalBounds().intersects(a[i].getGlobalBounds()))
                    {
                        EatingCheck = 1;
                        if (OnFire1Score + 0.2 < 4)
                            OnFire1Score += 0.2;
                        if (EB == 1)
                            bubbsT = 0;

                        EB = 1;

                        a[i].setScale(0, 0);
                        b1.play();
                        scoreNumber = 10;
                        ScoreEffectCreate(dix, players[0].Spri, OnFire1Score, scoreNumber);
                        f1NumberEaten++;
                        players[0].score += scoreNumber * (int)OnFire1Score;
                        hb_score += scoreNumber;
                    }

                    if (spwanT[i] >= 60)
                    {
                        Vx[i] = ((rand() % 21) - 10) / 5.f;
                        Vy[i] = ((rand() % 21) - 10) / 5.f;
                        spwanT[i] = 0;
                    }
                    a[i].move(Vx[i], Vy[i]);
                }
                for (int i = 0; i < fN; i++)
                {
                    spwanT[i]++;
                }



                // OnFire Effects
                OnFire(OnFire1Score, OnFire1ScorePrev, c1, c2, players[0].Spri, OnFire1Check, OnFire1Timer);

                OnFire1ScorePrev = OnFire1Score;

                // Score effect
                ScoreEffectControl(window);


                c = 1;

                // keep mouse in window
                KeepMouseInWindow(mousePosition, window, windowPo, c, mPyc, mPxc);

                //Vectory Effect


                // Moving view
                VIEW(players[0].Spri, vx, vy, ro, ro2, coral1, coral2, coral3);


                SCORE_0.setString("" + to_string(players[0].score));
                hb.setSize(Vector2f((float)hb_score / 30 * 5.f, 15.f));

                // Final velocity of the player
                players[0].Spri.move(vx + turboVelocity.x, vy + turboVelocity.y);


                mPxp = mPxc;
                mPyp = mPyc;
            }
            // Perfect Effect
            if (0)
            {
                winingTime++;
                PerfectDisplay(music1);
                PerfectTime++;
            }

            // Losing Effect
            if (0)
            {
                LosingTime++;
                SorryDisplay(music1);
                SorryTime++;
            }
            if (0) // End Game condition
            {
                numbersEatenText[0].setString(to_string(f1NumberEaten));
                numbersEatenText[1].setString(to_string(f2NumberEaten));
                numbersEatenText[2].setString(to_string(f3NumberEaten));
                numberStarsEatenText.setString(to_string(starsNumberEaten));
                resultTime++;

                resultBoard.setScale(2, 2);
                Title.setScale(2, 2);
                stageCompleted.setScale(1, 1);

                starBoard.setScale(2, 2);
                enemeisBoard[0].setScale(1.6, 1.6);
                enemeisBoard[1].setScale(0.9, 0.9);
                enemeisBoard[2].setScale(0.7, 0.7);

                if (resultTime == 30)
                {
                    numbersEatenText[0].setScale(1, 1);
                    Chomp.setPosition(numbersEatenText[0].getPosition().x, numbersEatenText[0].getPosition().y - 10);
                    b1.play();
                }
                if (resultTime == 60)
                {
                    numbersEatenText[1].setScale(1, 1);
                    Chomp.setPosition(numbersEatenText[1].getPosition().x, numbersEatenText[1].getPosition().y - 10);
                    b1.play();
                }
                if (resultTime == 90)
                {
                    numbersEatenText[2].setScale(1, 1);
                    Chomp.setPosition(numbersEatenText[2].getPosition().x, numbersEatenText[2].getPosition().y - 10);
                    b1.play();
                }
                if (resultTime == 120)
                {
                    numberStarsEatenText.setScale(1, 1);
                    Chomp.setPosition(numberStarsEatenText.getPosition().x, numberStarsEatenText.getPosition().y - 10);
                    b1.play();
                }
                Chomp.move(0, -0.5);
            }

            //if (players[0].score == 1000 || players[0].health == 0) {
            //    ofstream offile;
            //    offile.open("history.txt", ios::app);
            //    offile << name << "        " << players[0].score << "*" << endl;
            //    players[0].score = 0;
            //    players[0].health = 3;
            //    gameState = 0;
            // }


        }
        if (gameState == 6) {
            tempState = 6;
        }
        if (gameState == 7) {
            tempState = 7;
            // Make mouse unvisible
            window.setMouseCursorVisible(false);

            // delta time
            dt = clock.restart().asSeconds();


            // Music
            mt += dt;
            if (mt >= 72)
            {
                music1.play();
                mt = 0;
            }


            x += 0.09;
            if (x >= 15)
                x = 0;

            Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);



            mPxc = mousePosition.x;
            mPyc = mousePosition.y;


            direction(mPxc, mPxp, mPyc, mPyp, c, dix, diy, Tr, Tl);


            // Moving
            // X

            velocity_x(dix, c, mPxc, mPxp, vmx, vx);

            if (dix == 1 && c == 1)
                players[2].Spri.setTextureRect(IntRect(188 + (int)x * (3016 / 15), 376, -pwi3, phe3));
            else if (dix == -1 && c == 1)
                players[2].Spri.setTextureRect(IntRect(3 + (int)x * (3016 / 15), 376, pwi3, phe3));


            // Y

            velocity_x(diy, c, mPyc, mPyp, vmy, vy);

            // Limit Velocity
            limitV(vx, vy, vmx);






            // Perform a Turn
            if (Tr == 1)
            {
                if (xr > 4)
                {
                    xr = 0;
                    Tr = 0;
                }
                else
                {
                    xr += 0.3;
                    players[2].Spri.setTextureRect(IntRect(3 + (int)xr * 201, 546, pwi3, phe3));
                }

            }
            if (Tl == 1)
            {
                if (xl > 4)
                {
                    xl = 0;
                    Tl = 0;
                }
                else
                {
                    xl += 0.3;
                    players[2].Spri.setTextureRect(IntRect(188 + (int)xl * 201, 546, -pwi3, phe3));
                }
            }


            // Turbo
            if(mt > 10)
              Turbo(vx, vy);

            // Collision with window
            CollisionWithWindow(players[2].Spri, window, view);


            // Collision with fish
            if (EatingCheck == 1)
            {
                // eating animation
                if (eT <= 6)
                {
                    if (dix == -1)
                    {
                        players[2].Spri.setTextureRect(IntRect(10 + (int)eT * 200, 1, pwi3, 180));
                    }
                    else if (dix == 1)
                    {
                        players[2].Spri.setTextureRect(IntRect(188 + (int)eT * (3016 / 15), 1, -pwi3, 180));
                    }
                    eT += 0.3;
                }
                else
                {
                    EatingCheck = 0;
                    eT = 0;
                }
            }

            makeBubblesWhenEating(players[2].Spri, playerP, EB, bubbsT, dix);


            // Bubbles In Back----------------------------------------------------
            Ti++;
            if (Ti == 60)
            {
                Ti = 0;
                bubble2.setPosition(rand() % windowWidth, rand() % windowHeight);
                BubblesInBack.push_back(bubble2);
                bubbleScale.push_back(0.6);
            }

            for (int i = 0; i < BubblesInBack.size(); i++)
            {
                BubblesInBack[i].move(-1, 0);
                BubblesInBack[i].setScale(bubbleScale[i], bubbleScale[i]);
                bubbleScale[i] -= 0.003;
                if (bubbleScale[i] < 0.3)
                    bubbleScale[i] = 0;
            }

            // Stars---------------------------------------------------------------

                // Create Stars
            CreateStars(count);

            // Create small Stars to Each Big Star
            CreateSmallStars(count);

            // Create Sparks to Each Big Star
            CreateSparks();

            // Move Stars
            // move Small Stars
            // move Sparks
            MoveStars_SmallStars_Sparks();


            // Eat Stars
            EatStars(players[2], count, EatingCheck, EB, dix, scoreNumber, OnFire1Score, starsNumberEaten);


            //f1----------------------------------------------------------------------
            for (int i = 0; i < a.size(); i++)
            {
                // collision with player
                if (players[2].Spri.getGlobalBounds().intersects(a[i].getGlobalBounds()))
                {
                    EatingCheck = 1;
                    if (OnFire1Score + 0.2 < 4)
                        OnFire1Score += 0.2;
                    if (EB == 1)
                        bubbsT = 0;

                    EB = 1;

                    a[i].setScale(0, 0);
                    b1.play();
                    scoreNumber = 10;
                    ScoreEffectCreate(dix, players[2].Spri, OnFire1Score, scoreNumber);
                    f1NumberEaten++;
                    players[2].score += scoreNumber * (int)OnFire1Score;
                    hb_score += scoreNumber;
                }

                if (spwanT[i] >= 60)
                {
                    Vx[i] = ((rand() % 21) - 10) / 5.f;
                    Vy[i] = ((rand() % 21) - 10) / 5.f;
                    spwanT[i] = 0;
                }
                a[i].move(Vx[i], Vy[i]);
            }
            for (int i = 0; i < fN; i++)
            {
                spwanT[i]++;
            }



            // OnFire Effects
            OnFire(OnFire1Score, OnFire1ScorePrev, c1, c2, players[2].Spri, OnFire1Check, OnFire1Timer);

            OnFire1ScorePrev = OnFire1Score;

            // Score effect
            ScoreEffectControl(window);


            c = 1;

            // keep mouse in window
            KeepMouseInWindow(mousePosition, window, windowPo, c, mPyc, mPxc);

            //Vectory Effect
           if (0)
           {
           	winingTime++;
           	PerfectDisplay(music1);
           	PerfectTime++;
           }

           // Losing Effect
           if (0)
           {
           	LosingTime++;
           	SorryDisplay(music1);
           	SorryTime++;
           }

           // Moving view
           VIEW(players[2].Spri, vx, vy, ro, ro2, coral1, coral2, coral3);


           SCORE_0.setString("" + to_string(players[2].score));
           hb.setSize(Vector2f((float)hb_score / 30 * 5.f, 15.f));

           // Final velocity of the player
           players[2].Spri.move(vx + turboVelocity.x, vy + turboVelocity.y);




            mPxp = mPxc;
            mPyp = mPyc;
        }

        window.clear();

        // Draw 
        if (gameState == 0)
        {
            window.draw(sprites[0]);
            window.draw(sprites[1]);
            if (b1l == 1)
                window.draw(sprites[8]);
            else
                window.draw(sprites[2]);
            if (b2l == 1)
                window.draw(sprites[9]);
            else
                window.draw(sprites[3]);
            if (b3l == 1)
                window.draw(sprites[10]);
            else
                window.draw(sprites[4]);
            if (b4l == 1)
                window.draw(sprites[11]);
            else
                window.draw(sprites[5]);
        }
        else if (gameState == 1)
        {
            window.draw(sprites[17]);
            window.draw(escapeButton);
            window.draw(muteButton);
            if (isMuted)
                window.draw(sprites[18]);
            else
                window.draw(sprites[19]);
        }
        else if (gameState == 2) {
        }
        else if (gameState == 3) {
        }
        else if (gameState == 4)
        {
            window.draw(escapeButton);
            window.draw(sprites[14]);
            window.draw(sprites[16]);
            window.draw(sprites[20]);

            if (b5l == 1)
                window.draw(sprites[6]);
            else
                window.draw(sprites[12]);
            if (b12l == 1)
                window.draw(sprites[21]);
            else
                window.draw(sprites[22]);
            if (b6l == 1)
                window.draw(sprites[7]);
            else
                window.draw(sprites[13]);

            window.draw(l1Button);
            window.draw(l2Button);
            window.draw(l3Button);
        }
        else if (gameState == 5)
        { // Draw the game
            window.draw(Pbutton);

            if (1)  // Still in game condition
            {
                window.setView(view);
                window.draw(b);
                window.draw(coral4);
                window.draw(shrub);
                window.draw(coral1);
                window.draw(coral2);
                window.draw(ro);
                window.draw(ro2);
                window.draw(coral3);


                window.draw(players[0].Spri);

                for (int i = 0; i < a.size(); i++)
                {
                    window.draw(a[i]);
                }

                if (EB == 1)
                    for (int i = 0; i < 5; i++)
                        window.draw(bubbles[i]);
                for (int i = 0; i < BubblesInBack.size(); i++)
                {
                    window.draw(BubblesInBack[i]);
                }
                if (OnFire1Check == 1)
                    window.draw(Yum);
                if (OnFire1Check == 1)
                    window.draw(Gulb);


                for (int i = 0; i < stars.size(); i++)
                    window.draw(stars[i]);

                for (int i = 0; i < smallStars.size(); i++)
                    window.draw(smallStars[i]);

                for (int i = 0; i < sparks1.size(); i++)
                    window.draw(sparks1[i]);


                window.setView(window.getDefaultView());
                // Abdo Draw ----------------------------
                window.draw(rectangle);
                window.draw(line);
                window.draw(line_GROWTH);
                window.draw(line_ABILITY);
                window.draw(triangle);
                window.draw(triangle2);
                for (int i = 0; i < 4; i++)
                    window.draw(tab[i]);
                window.draw(sprite1);
                window.draw(sprite2);
                window.draw(sprite3);
                window.draw(menu);
                window.draw(GROWTH);
                window.draw(SCORE);
                window.draw(SCORE_0);
                window.draw(ABILTY);
                window.draw(Bub);
                window.draw(Bub2);
                window.draw(Doublect);
                window.draw(Doublect2);
                window.draw(triple_tab);
                window.draw(hb);


                // ---------------------------------------

                window.draw(OnFireText);
                for (int i = 0; i < T1.size(); i++)
                {
                    window.draw(T1[i]);
                }

                for (int i = 0; i < 7; i++)
                {
                    window.draw(Perfect[i]);
                    window.draw(Bubs[i]);

                }
                for (int i = 0; i < 5; i++)
                {
                    window.draw(Sorry[i]);
                    window.draw(Bubs1[i]);

                }
            }
            else
            {
                window.setView(window.getDefaultView());
                b.setPosition(0, 0);
                window.draw(b);
                window.draw(resultBoard);
                window.draw(Title);
                for (int i = 0; i < 3; i++)
                {
                    window.draw(enemeisBoard[i]);
                }
                window.draw(starBoard);
                for (int i = 0; i < 3; i++)
                {
                    window.draw(numbersEatenText[i]);
                }
                window.draw(numberStarsEatenText);
                window.draw(stageCompleted);
                if (resultTime < 150)
                    window.draw(Chomp);
            }
        }
        else if (gameState == 6) {
            window.draw(Pbutton);
        }
        else if (gameState == 7) {
            window.draw(Pbutton);
            window.setView(view);
            window.draw(b);
            window.draw(coral4);
            window.draw(shrub);
            window.draw(coral1);
            window.draw(coral2);
            window.draw(ro);
            window.draw(ro2);
            window.draw(coral3);


            window.draw(players[2].Spri);

            for (int i = 0; i < a.size(); i++)
            {
                window.draw(a[i]);
            }

            if (EB == 1)
                for (int i = 0; i < 5; i++)
                    window.draw(bubbles[i]);
            for (int i = 0; i < BubblesInBack.size(); i++)
            {
                window.draw(BubblesInBack[i]);
            }
            if (OnFire1Check == 1)
                window.draw(Yum);
            if (OnFire1Check == 1)
                window.draw(Gulb);


            for (int i = 0; i < stars.size(); i++)
                window.draw(stars[i]);

            for (int i = 0; i < smallStars.size(); i++)
                window.draw(smallStars[i]);

            for (int i = 0; i < sparks1.size(); i++)
                window.draw(sparks1[i]);


            window.setView(window.getDefaultView());
            // Abdo Draw ----------------------------
            window.draw(rectangle);
            window.draw(line);
            window.draw(line_GROWTH);
            window.draw(line_ABILITY);
            window.draw(triangle);
            window.draw(triangle2);
            for (int i = 0; i < 4; i++)
                window.draw(tab[i]);
            window.draw(sprite1);
            window.draw(sprite2);
            window.draw(sprite3);
            window.draw(menu);
            window.draw(GROWTH);
            window.draw(SCORE);
            window.draw(SCORE_0);
            window.draw(ABILTY);
            window.draw(Bub);
            window.draw(Bub2);
            window.draw(Doublect);
            window.draw(Doublect2);
            window.draw(triple_tab);
            window.draw(hb);


            // ---------------------------------------

            window.draw(OnFireText);
            for (int i = 0; i < T1.size(); i++)
            {
                window.draw(T1[i]);
            }

            for (int i = 0; i < 7; i++)
            {
                window.draw(Perfect[i]);
                window.draw(Bubs[i]);

            }
            for (int i = 0; i < 5; i++)
            {
                window.draw(Sorry[i]);
                window.draw(Bubs1[i]);

            }

        }
        else if (gameState == 8)
        { // Draw the pause menu
            window.draw(sprites[17]);
            window.draw(levelButton);
            window.draw(mainmenuButton);
            window.draw(continueButton);
            window.draw(exitButton);
        }


        window.display();
    }

    return 0;
}