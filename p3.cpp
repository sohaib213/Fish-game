#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <vector>

using namespace sf;
using namespace std;

// Global things------------------------------------------------------------------------------------------------------
int windowWidth = 1280;
int windowHeight = 960;

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
Sprite Bub[7];
Text Perfect[7];
int PerfectTime = 0;
int endPerfect = 0;
Sound winSound;
int winingTime = 0;
// Losing effect
Sprite Bub1[5];
Text Sorry[5];
int SorryTime = 0;
int endSorry = 0;
Sound losSound;
int LosingTime = 0;

bool TurboCheck = 0;
int TurboTime = 0;
Vector2f turboVelocity = Vector2f(0, 0);

Sound dashSound;




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
			if (vx + (mPxc - mPxp) / 10 < vm)   // limit the velocity
				vx += (mPxc - mPxp) / 10;
		}



	}
	if (dix == -1)
	{
		if (c == 1)
		{
			if (vx + (mPxc - mPxp) / 10 > -vm)    // limit the velocity
				vx += (mPxc - mPxp) / 10;
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
			if (vy + (mPyc - mPyp) / 10 < vm)
				vy += (mPyc - mPyp) / 10;
		}
	}
	else if (diy == -1)
	{
		if (c == 1)
		{
			if (vy + (mPyc - mPyp) / 10 > -vm)
				vy += (mPyc - mPyp) / 10;
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

void CollisionWithWindow(Sprite& p, RenderWindow& window)
{
	// Collision with window
	if (p.getPosition().x < 0)
		p.setPosition(0, p.getPosition().y);

	if (p.getPosition().y < 0)
		p.setPosition(p.getPosition().x, 0);

	if (p.getPosition().x > window.getSize().x - p.getGlobalBounds().width)
		p.setPosition(window.getSize().x - p.getGlobalBounds().width, p.getPosition().y);

	if (p.getPosition().y > window.getSize().y - p.getGlobalBounds().height)
		p.setPosition(p.getPosition().x, window.getSize().y - p.getGlobalBounds().height);
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
		Mouse::setPosition(Vector2i(mousePosition.x + windowPo.x + 8, window.getSize().y + windowPo.y - 30));
		c = 0;

		mPyc = Mouse::getPosition().y;
	}
}

void ScoreEffectControl(RenderWindow& window)
{
	// Score effect
	for (int i = 0; i < T1.size(); i++)
	{
		Vector2f dir = Vector2f(window.getSize().x - 100, 0) - Vector2f(T1[i].getPosition().x, T1[i].getPosition().y);
		length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
		dir /= length;

		T1[i].move(5 * dir.x, 5 * dir.y);
		if (T1[i].getPosition().x >= window.getSize().x - 100 && T1[i].getPosition().y <= 40)
		{
			T1.erase(T1.begin() + i);
		}
	}
}

void ScoreEffectCreate(int dix, Sprite p, float x, int N)
{
	plus_10.setString("+" + to_string((int)x * N));
	if (dix == -1)
		plus_10.setPosition(p.getPosition().x, p.getPosition().y + p.getGlobalBounds().height / 2);
	else
		plus_10.setPosition(p.getPosition().x + p.getGlobalBounds().width, p.getPosition().y + p.getGlobalBounds().height / 2);
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

void EatStars(Sprite p, vector<int>& count, bool& E, bool& EB, int dix, int& scoreNumber, float OnFire1Score)
{
	for (int i = 0; i < stars.size(); i++)
	{
		if (p.getGlobalBounds().intersects(stars[i].getGlobalBounds()))
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
			ScoreEffectCreate(dix, p, OnFire1Score, scoreNumber);
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
		Bub[i].setScale(1.5, 1.5);
		if (Perfect[i].getPosition().y < 520)
		{
			Perfect[i].move(0, 0.4);
			Bub[i].move(0, 0.4);
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
		Bub1[i].setScale(1.5, 1.5);
		if (Sorry[i].getPosition().y < 520)
		{
			Sorry[i].move(0, 0.4);
			Bub1[i].move(0, 0.4);

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

//main-------------------------------------------------------------------------------------------------------
int main()
{

	srand(NULL);
	RenderWindow window(VideoMode(windowWidth, windowHeight), "13", Style::Fullscreen);
	window.setFramerateLimit(60);

	// BackGround
	Texture back;
	if (!back.loadFromFile("sea1.png"))
		return EXIT_FAILURE;
	Sprite b;
	b.setTexture(back);

	// Players

		// player 1
	Sprite p1;
	Texture player1;
	if (!player1.loadFromFile("p.png"))
		return EXIT_FAILURE;
	p1.setTexture(player1);
	float pwi1 = 122, phe1 = 104;     // player1  ( width, height )
	p1.setTextureRect(IntRect(2, 425 / 2, 125, 105));
	float x = 0;    // counter of animation
	p1.setScale(0.7, 0.7);

		//player3
	Sprite p3;
	Texture player3;
	if (!player3.loadFromFile("p3.png"))
		return EXIT_FAILURE;
	p3.setTexture(player3);
	float pwi3 = 186, phe3 = 166;     // player3  ( width, height )
	p3.setScale(0.7, 0.7);
	p3.setColor(Color(255,2,255));




	Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

	// Mouse Position Declaration (current , previous)
	float mPxc, mPxp = 0;
	float mPyc, mPyp = 0;
	// check if the mouse is out of window
	bool c = 1;


	// Direction of moving
	int dix = 0, diy = 0;

	// velocity
	float vx = 0, vy = 0, vm = 10;

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


	// score effect
	Font font;
	if (!font.loadFromFile("Sunny Spells Basic.ttf"))
		return EXIT_FAILURE;

	plus_10.setFont(font);
	plus_10.setCharacterSize(45);
	plus_10.setFillColor(Color::White);
	plus_10.setString("+10");

	plus_20.setFont(font);
	plus_20.setCharacterSize(45);
	plus_20.setFillColor(Color::White);
	plus_20.setString("+20");

	plus_30.setFont(font);
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
	OnFireText.setPosition(windowWidth - 50, 0);

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

	music1.play();
	double mt = 0;

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
	ro.setPosition(402, window.getSize().y - 108);

	// Coral reefs
	Sprite coral1;
	coral1.setTexture(Back1T);
	coral1.setTextureRect(IntRect(138, 111, 182, 115));
	coral1.setPosition(windowWidth / 2 - 80, windowHeight - 160);

	Sprite coral2;
	coral2.setTexture(Back1T);
	coral2.setTextureRect(IntRect(322, 117, -180, 110));
	coral2.setPosition(windowWidth / 2 - 210, windowHeight - 160);




	// Wining

		// Wining Sound
	SoundBuffer winBuf;
	winBuf.loadFromFile("stageClear.wav");
	winSound.setBuffer(winBuf);
	bool winSoundCheck = 0;

	// Bubbles
	Texture BigBubble;
	BigBubble.loadFromFile("bub.png");
	Bub[0].setTexture(BigBubble);
	Bub[0].setOrigin(Bub[0].getGlobalBounds().width / 2, Bub[0].getGlobalBounds().height / 2);

	// Perfect letters

	Perfect[0].setCharacterSize(100);
	Perfect[0].setFont(font);
	Perfect[0].setString("P");
	Perfect[0].setFillColor(Color::Red);
	Perfect[0].setOrigin(Perfect[0].getGlobalBounds().width / 2, Perfect[0].getGlobalBounds().height / 2);
	Perfect[0].setPosition(301, 505);
	Perfect[0].setScale(0, 0);
	Bub[0].setScale(0, 0);
	Bub[0].setPosition(301, 545);

	for (int i = 1; i < 7; i++)
	{
		Bub[i] = Bub[0];
		Bub[i].setPosition(Bub[0].getPosition().x + (113 * i), 545);
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
	Bub1[0].setTexture(BigBubble);
	Bub1[0].setOrigin(Bub1[0].getGlobalBounds().width / 2, Bub1[0].getGlobalBounds().height / 2);

	// Sorry letters

	Sorry[0].setCharacterSize(100);
	Sorry[0].setFont(font);
	Sorry[0].setString("S");
	Sorry[0].setFillColor(Color::Red);
	Sorry[0].setOrigin(Sorry[0].getGlobalBounds().width / 2, Sorry[0].getGlobalBounds().height / 2);
	Sorry[0].setPosition(401, 505);
	Sorry[0].setScale(0, 0);
	Bub1[0].setScale(0, 0);
	Bub1[0].setPosition(401, 545);

	for (int i = 1; i < 5; i++)
	{
		Bub1[i] = Bub1[0];
		Bub1[i].setPosition(Bub1[0].getPosition().x + (113 * i), 545);
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




	// Game loop -------------------------------------------------------------------------------------------------
	while (window.isOpen())
	{


		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed())
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}


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

		velocity_x(dix, c, mPxc, mPxp, vm, vx);

		if (dix == 1 && c == 1)
			p3.setTextureRect(IntRect(188 + (int)x * (3016 / 15), 376, -pwi3, phe3));
		else if (dix == -1 && c == 1)
			p3.setTextureRect(IntRect(3 + (int)x * (3016 / 15), 376, pwi3, phe3));


		// Y

		velocity_x(diy, c, mPyc, mPyp, vm, vy);

		// Limit Velocity
		limitV(vx, vy, vm);






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
				p3.setTextureRect(IntRect(3 + (int)xr * 201, 546, pwi3, phe3));
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
				p3.setTextureRect(IntRect(188 + (int)xl * 201, 546, -pwi3, phe3));
			}
		}


		// Turbo
		Turbo(vx, vy);

		// Collision with window
		CollisionWithWindow(p3, window);


		// Collision with fish
		if (EatingCheck == 1)
		{
			// eating animation
			if (eT <= 6)
			{
				if (dix == -1)
				{
					p3.setTextureRect(IntRect(10 + (int)eT* 200, 1, pwi3, 180));
				}
				else if (dix == 1)
				{
					p3.setTextureRect(IntRect(188 + (int)eT * (3016 / 15), 1, -pwi3, 180));
				}
				eT += 0.3;
			}
			else
			{
				EatingCheck = 0;
				eT = 0;
			}
		}

		makeBubblesWhenEating(p3, playerP, EB, bubbsT, dix);


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
		EatStars(p3, count, EatingCheck, EB, dix, scoreNumber, OnFire1Score);


		//f1----------------------------------------------------------------------
		for (int i = 0; i < a.size(); i++)
		{
			// collision with player
			if (p3.getGlobalBounds().intersects(a[i].getGlobalBounds()))
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
				ScoreEffectCreate(dix, p3, OnFire1Score, scoreNumber);
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
		OnFire(OnFire1Score, OnFire1ScorePrev, c1, c2, p3, OnFire1Check, OnFire1Timer);

		OnFire1ScorePrev = OnFire1Score;

		// Score effect
		ScoreEffectControl(window);


		c = 1;

		// keep mouse in window
		KeepMouseInWindow(mousePosition, window, windowPo, c, mPyc, mPxc);

		//Vectory Effect
	   //if (1)
	   //{
	   //	winingTime++;
	   //	PerfectDisplay(music1);
	   //	PerfectTime++;
	   //}

	   // Losing Effect
	   //if (1)
	   //{
	   //	LosingTime++;
	   //	SorryDisplay(music1);
	   //	SorryTime++;
	   //}


	   // Final velocity of the player
		p3.move(vx + turboVelocity.x, vy + turboVelocity.y);


		mPxp = mPxc;
		mPyp = mPyc;

		window.clear();

		window.draw(b);
		window.draw(coral1);
		window.draw(coral2);
		window.draw(ro);
		window.draw(p3);
		for (int i = 0; i < a.size(); i++)
		{
			window.draw(a[i]);
		}
		for (int i = 0; i < T1.size(); i++)
		{
			window.draw(T1[i]);
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
		window.draw(OnFireText);

		for (int i = 0; i < stars.size(); i++)
			window.draw(stars[i]);

		for (int i = 0; i < smallStars.size(); i++)
			window.draw(smallStars[i]);

		for (int i = 0; i < sparks1.size(); i++)
			window.draw(sparks1[i]);

		for (int i = 0; i < 7; i++)
		{
			window.draw(Perfect[i]);
			window.draw(Bub[i]);

		}
		for (int i = 0; i < 5; i++)
		{
			window.draw(Sorry[i]);
			window.draw(Bub1[i]);

		}



		window.display();
	}

}