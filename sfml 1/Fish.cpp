


#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <vector>

using namespace sf;

Texture player;
Sprite p;

void eat(double T, int di)
{
	if (di == -1)
	{
		p.setTextureRect(IntRect(2 + (int)T * 126, 2, 122, 104));
	}
	else if (di == 1)
	{
		p.setTextureRect(IntRect(125 + (int)T * 126, 2, -122, 104));
	}
}

int main()
{
	RenderWindow window(VideoMode(1000, 750), "13");
	window.setFramerateLimit(60);

	// BackGround
	Texture back;
	back.loadFromFile("sea.png");
	Sprite b;
	b.setTexture(back);

	// Player
	player.loadFromFile("p.png");
	p.setTexture(player);
	float pwi = 122, phe = 104;
	p.setTextureRect(IntRect(1, 425 / 2, 125, 105));
	float x = 0;
	p.setScale(0.75, 0.75);
	p.setPosition(window.getSize().x / 2 - p.getGlobalBounds().width / 2, 0);
	Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);




	// Mouse Position Declaration (current , previous)
	double mPxc, mPxp = 0;
	double mPyc, mPyp = 0;
	// check if the mouse is out of window
	bool c = 1;


	// Direction of moving
	int dix = 0, diy = 0;

	// velocity
	double vx = 0, vy = 0,vm = 8;

	//Return
	double xr = 0, xl = 0;
	bool Tr = 0, Tl = 0;

	// frame counter
	long long f = 0;

	// Fish 1
	std::vector<CircleShape> a;
	for (int i = 0; i < 10; ++i) 
	{
		    sf::CircleShape circle(20); // Radius of 20
		    circle.setFillColor(sf::Color::Red); // Set color
		    circle.setPosition(std::rand() % 800, std::rand() % 600); // Random position
		    a.push_back(circle);
    }
	double Vx = rand() % 3;
	double Vy = rand() % 3;
	double dx = rand() % 3 - 1, dy = rand() % 3 - 1;
	double diT = 0;
	double mT = 0;

	// score effect
	RectangleShape s;
	s.setSize(Vector2f(10, 10));
	s.setFillColor(Color::Cyan);
	std::vector<RectangleShape> ss;
	float length;
	Vector2f dir;


	Font font;
	font.loadFromFile("Texts/Metropolis-ExtraBold.otf");

	Text plus_20;
	plus_20.setFont(font);
	plus_20.setCharacterSize(25);
	plus_20.setFillColor(Color::White);
	plus_20.setString("+20");
	std::vector<Text> T1;




	SoundBuffer buffer;
	buffer.loadFromFile("bite1.wav");
	Sound b1;
	b1.setBuffer(buffer);

	// Music
	Music music;
	music.openFromFile("Feeding-Frenzy-Track-1.ogg");
	music.play();
	double mt = 0;

	// Time
	Clock clock, clo;
	double dt = 0;

	// check eating
	bool E = 0;

	// Position of window
	Vector2f windowPo (window.getPosition().x, window.getPosition().y);

	// Bubbles effect when eating fish
	Texture bub1T;
	bub1T.loadFromFile("bubble1.png");

	Sprite bubble;
	bubble.setTexture(bub1T);
	Sprite bubbles[5];
	for (int i = 0; i < 5; i++)
	{
		bubbles[i] = bubble;
	}


	double eT = 0;
	double bubbsT = 0;  // Bubbles Time
	bool EB = 0;        // Bubbles when eating check

	// player position
	Vector2f playerP;

	// rock
	Texture Back1T;
	Back1T.loadFromFile("back 1 t.png");
	Sprite ro;
	ro.setTexture(Back1T);
	ro.setTextureRect(IntRect(0, 0, 390, 108));
	ro.setPosition(402, window.getSize().y - 108);

	// Coral reefs
	Sprite coral1;
	coral1.setTexture(Back1T);
	coral1.setTextureRect(IntRect(138, 111, 182, 115));
	coral1.setPosition(560, 595);

	Sprite coral2;
	coral2.setTexture(Back1T);
	coral2.setTextureRect(IntRect(322, 117, -180, 110));
	coral2.setPosition(450, 595);







	// Game loop
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
			music.play();
			mt = 0;
		}


		f++;

		x += 0.09;
		if (x >= 15)
			x = 0;

		Vector2f mousePosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

		

		mPxc = mousePosition.x;
		mPyc = mousePosition.y;

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


		// Moving
		// X
		if (dix == 1)
		{
			if ( c == 1)
			{
				if (vx + (mPxc - mPxp) / 10 < vm)   // limit the velocity
					vx += (mPxc - mPxp) / 10;
			}

				p.setTextureRect(IntRect(125 + (int)x * 126, 214, -pwi, phe));

		}
		if (dix == -1)
		{
			if (c == 1)
			{
				if(vx + (mPxc - mPxp) / 10 > -vm)    // limit the velocity
					vx += (mPxc - mPxp) / 10;
			}

			p.setTextureRect(IntRect(3 + (int)x * 126, 214, pwi, phe));
		}
		// Reduce the velocity.x
		if (vx > 0)
			vx -= 0.1;
		else if (vx < 0)
			vx += 0.1;


		// Y
		if (diy == 1)
		{
			if (c == 1)
			{
				if(vy + (mPyc - mPyp) / 10 < vm)
				vy += (mPyc - mPyp) / 10;
			}
		}
		else if (diy == -1)
		{
			if (c == 1)
			{
				if(vy + (mPyc - mPyp) / 10 > -vm)
				vy += (mPyc - mPyp) / 10;
			}
		}

		// Reduce the velocity.y
		if (vy > 0)
			vy -= 0.1;
		else if (vy < 0)
			vy += 0.1;



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
				p.setTextureRect(IntRect(3 + (int)xr * 126, 320, pwi, phe));
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
				p.setTextureRect(IntRect(124 + (int)xl * 126, 320, -pwi, phe));
			}

		}




		// Collision with window
		if (p.getPosition().x < 0)
			p.setPosition(0, p.getPosition().y);

		if (p.getPosition().y < 0)
			p.setPosition(p.getPosition().x, 0);

		if (p.getPosition().x > window.getSize().x - p.getGlobalBounds().width)
			p.setPosition(window.getSize().x - p.getGlobalBounds().width, p.getPosition().y);

		if (p.getPosition().y > window.getSize().y - p.getGlobalBounds().height)
			p.setPosition(p.getPosition().x, window.getSize().y - p.getGlobalBounds().height);



		// Collision with fish
		if (E == 1)
		{
			// eating animation
			if (eT <= 6)
			{
				eat(eT, dix);
				eT += 0.3;
			}
			else
			{
				E = 0;
				eT = 0;
			}
		}

		// bubbels
		if(EB == 1) 
		{
			if (bubbsT <= 10)
			{
				if (bubbsT == 0)
				{
					bubbles[0].setScale(0.4f, 0.4f);
					playerP = p.getPosition();
					if(dix == 1)
						bubbles[0].setPosition(playerP.x + p.getGlobalBounds().width - 15, playerP.y + p.getGlobalBounds().height / 2);
					else
						bubbles[0].setPosition(playerP.x -15 , playerP.y + p.getGlobalBounds().height / 2);
				}
				if (bubbsT >= 0.9 && bubbsT <= 1.2)
				{
					bubbles[1].setScale(0.4f, 0.4f);
					if (dix == 1)
						bubbles[1].setPosition(playerP.x + p.getGlobalBounds().width, playerP.y + p.getGlobalBounds().height / 2);
					else
						bubbles[1].setPosition(playerP.x  , playerP.y + p.getGlobalBounds().height / 2);
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
						bubbles[4].setPosition(playerP.x + p.getGlobalBounds().width - 5, playerP.y  + p.getGlobalBounds().height / 2);
					else
						bubbles[4].setPosition(playerP.x -5, playerP.y + p.getGlobalBounds().height / 2);
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




		//f1
		for(int i = 0; i < a.size();i++)
		{
			srand(f);
			// collision with player
			if (p.getGlobalBounds().intersects(a[i].getGlobalBounds()))
			{
				E = 1;

				if (EB == 1)
					bubbsT = 0;

				EB = 1;

				a[i].setScale(0, 0);
				b1.play();

				//if(dix == -1)
				//	s.setPosition(p.getPosition().x, p.getPosition().y + p.getGlobalBounds().height / 2);
				//else
				//	s.setPosition(p.getPosition().x + p.getGlobalBounds().width, p.getPosition().y + p.getGlobalBounds().height / 2);
				//ss.push_back(s);

				if (dix == -1)
					plus_20.setPosition(p.getPosition().x, p.getPosition().y + p.getGlobalBounds().height / 2);
				else
					plus_20.setPosition(p.getPosition().x + p.getGlobalBounds().width, p.getPosition().y + p.getGlobalBounds().height / 2);
				T1.push_back(plus_20);
			}

			diT += dt;
			mT += dt;
			if (diT >= 2)
			{
				dx = rand() % 3 - 1;
				dy = rand() % 3 - 1;

				diT = 0;
			}
			if (dx == 0)
				dx= 0.4;

			if (dy == 0)
				dy = 0.4;
			if (mT >= 1)
			{
				Vx = (rand() % 9) / 6.0 + 0.1;
				Vy = (rand() % 9) / 6.0 + 0.1;
				mT = 0;
			}
			a[i].move(Vx * dx, Vy * dy);
			f++;
		}

		for(int i = 0; i < T1.size(); i++)
		{
			Vector2f dir = Vector2f(window.getSize().x - 10, 0) - Vector2f(T1[i].getPosition().x, T1[i].getPosition().y);
			length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
			dir /= length;

			T1[i].move(5 * dir.x, 5 * dir.y);
			if (T1[i].getPosition().x >= window.getSize().x - 10 && T1[i].getPosition().y <= 0)
			{
				T1.erase(T1.begin() + i);
			}
		}

		c = 1;
		// keep mouse in window
		if (mousePosition.x > window.getSize().x)
		{
			Mouse::setPosition(Vector2i(0 + windowPo.x + 10, mousePosition.y + windowPo.y + 30));
			c = 0;
		}
		if (mousePosition.x < 0)
		{
			Mouse::setPosition(Vector2i(window.getSize().x + windowPo.x, mousePosition.y + windowPo.y + 30));
			c = 0;
			mPxc = Mouse::getPosition().x;
		}
		if (mousePosition.y > window.getSize().y)
		{
			Mouse::setPosition(Vector2i(mousePosition.x + windowPo.x + 8, 0 + windowPo.y + 40));
			c = 0;

			mPyc = Mouse::getPosition().y;
		}
		if (mousePosition.y < 0)
		{
			Mouse::setPosition(Vector2i(mousePosition.x + windowPo.x + 8, window.getSize().y + windowPo.y));
			c = 0;

			mPyc = Mouse::getPosition().y;
		}
		

		// Final velocity of the player
		if (sqrt(vx * vx + vy * vy) >= 6)
		{
			p.move(vx / sqrt(2), vy / sqrt(2));
		}
		else
			p.move(vx, vy);


		mPxp = mPxc;
		mPyp = mPyc;

		window.clear();

		window.draw(b);
		window.draw(coral1);
		window.draw(coral2);
		window.draw(ro);
		window.draw(p);
		for (int i = 0; i < a.size(); i++)
		{
			window.draw(a[i]);
		}
		for (int i = 0; i < T1.size(); i++)
		{
			window.draw(T1[i]);
		}
		if(EB == 1)
		for(int i = 0; i < 5; i++)
			window.draw(bubbles[i]);


		window.display();
	}

	return 0;
}