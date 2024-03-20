////#include <iostream>
//#include "SFML/Graphics.hpp"
//#include <SFML/Audio.hpp>
//#include <vector>
//
//using namespace sf;
//
//Texture player;
//Sprite p;
//
//void eat(double T, int di)
//{
//	if(di == -1)
//	{
//		p.setTextureRect(IntRect(2 + (int)T * 126, 2, 122, 104));
//	}
//	else if (di == 1)
//	{
//		p.setTextureRect(IntRect(125 + (int)T * 126, 2, -122, 104));
//	}
//}
//
//int main()
//{
//	RenderWindow window(VideoMode(1000, 750), "13");
//	window.setFramerateLimit(60);
//
//	// BackGround
//	Texture back;
//	back.loadFromFile("sea.png");
//	Sprite b;
//	b.setTexture(back);
//
//	// Player
//	player.loadFromFile("p.png");
//	p.setTexture(player);
//	float pwi = 122, phe = 104;
//	p.setTextureRect(IntRect(1, 425 / 2, 125, 105));
//	float x = 0;
//	p.setScale(0.75, 0.75);
//	p.setPosition(window.getSize().x /2 - p.getGlobalBounds().width /2 , 0);
//
//
//
//	// Mouse Position Declaration
//	std::vector<int>mPx;
//	std::vector<int>mPy;
//	Vector2i mop = Mouse::getPosition(window);
//	mPx.push_back(mop.x);
//	mPy.push_back(mop.y);
//
//	// Direction of moving
//	int dix = 0, diy = 0;
//
//	// velocity
//	double vx = 0, vy = 0, vm = 5;
//
//	//Return
//	double xr = 0, xl = 0;
//	bool Tr = 0, Tl = 0;
//
//	// frame counter
//	long long f = 0;
//
//	// Fish 1
//	CircleShape f1(10);
//	f1.setPosition(300, 300);
//	f1.setFillColor(Color::Magenta);
//	double Vx = rand() % 3;
//	double Vy = rand() % 3;
//	double d = rand() % 3 - 1;
//	double diT = 0;
//	double mT = 0;
//
//	SoundBuffer buffer;
//	buffer.loadFromFile("bite1.wav");
//	Sound b1;
//	b1.setBuffer(buffer);
//
//	// Music
//	Music music;
//	music.openFromFile("Feeding-Frenzy-Track-1.ogg");
//	music.play();
//	double mt = 0;
//
//	// Time
//	Clock clock;
//	double dt = 0;
//	// check eating
//	bool E = 0;
//
//
//
//	double eT = 0;
//
//	while (window.isOpen())
//	{
//
//
//		Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed())
//				window.close();
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
//				window.close();
//		}
//		// Make mouse unvisible
//		window.setMouseCursorVisible(false);
//
//		dt = clock.restart().asSeconds();
//
//
//		// Music
//		mt += dt;
//		if (mt >= 72)
//		{
//			music.play();
//			mt = 0;
//		}
//
//
//		x += 0.09;
//		if (x >= 15)
//			x = 0;
//
//		f++;
//		mPx.push_back(Mouse::getPosition().x);
//		mPy.push_back(Mouse::getPosition().y);
//
//		// Determine the direction
//		if (mPx[f] > mPx[f - 1])
//		{
//			if (dix == -1)
//			{
//				Tr = 1;
//			}
//			dix = 1;
//		}
//		else if (mPx[f] < mPx[f - 1])
//		{
//			if (dix == 1)
//			{
//				Tl = 1;
//			}
//			dix = -1;
//		}
//
//		if (mPy[f] > mPy[f - 1])
//		{
//			diy = 1;
//		}
//		else if (mPy[f] < mPy[f - 1])
//		{
//			diy = -1;
//		}
//
//		
//		// Moving
//		// X
//		if (dix == 1)
//		{
//			vx += (mPx[f] - mPx[f - 1] ) / 4;
//
//			p.setTextureRect(IntRect(125 + (int)x * 126, 214, -pwi, phe));
//
//		}
//		if (dix == -1)
//		{
//			 vx += (mPx[f] - mPx[f - 1]) / 4 ;
//
//			p.setTextureRect(IntRect(3 + (int)x * 126, 214, pwi, phe));
//		}
//		// Reduce the velocity.x
//		if (vx > 0)
//			vx -= 0.1;
//		else if(vx < 0)
//			vx += 0.1;
//
//		// Limit the velocity
//
//		if (vx > vm)
//			vx = vm;
//		else if (vx < -vm)
//			vx = -vm;
//
//		// Y
//		if (diy == 1)
//		{
//			vy += (mPy[f] - mPy[f - 1]) / 4;
//		}
//		else if (diy == -1)
//		{
//			vy += (mPy[f] - mPy[f - 1]) / 4;
//		}
//
//		// Limit the velocity
//		if (vy > vm)
//		vy = vm;
//		else if (vy < -vm)
//			vy = -vm;
//
//		// Reduce the velocity.x
//		if (vy > 0)
//			vy -= 0.1;
//		else if (vy < 0)
//			vy += 0.1;
//
//
//		// Perform a Turn
//		if (Tr == 1)
//		{
//			if (xr > 4)
//			{
//				xr = 0;
//				Tr = 0;
//			}
//			else
//			{
//				xr += 0.3;
//				p.setTextureRect(IntRect(3 + (int)xr * 126, 320, pwi, phe));
//			}
//			
//		}
//		if (Tl == 1)
//		{
//			if (xl > 4)
//			{
//				xl = 0;
//				Tl = 0;
//			}
//			else
//			{
//				xl += 0.3;
//				p.setTextureRect(IntRect(124 + (int)xl * 126, 320, -pwi, phe));
//			}
//
//		}
//		
//		
//
//
//		// Collision with window
//		if (p.getPosition().x < 0)
//			p.setPosition(0, p.getPosition().y);
//
//		if (p.getPosition().y < 0)
//			p.setPosition(p.getPosition().x, 0);
//
//		if (p.getPosition().x > window.getSize().x - p.getGlobalBounds().width)
//			p.setPosition(window.getSize().x - p.getGlobalBounds().width, p.getPosition().y);
//
//		if (p.getPosition().y > window.getSize().y - p.getGlobalBounds().height)
//			p.setPosition(p.getPosition().x, window.getSize().y - p.getGlobalBounds().height);
//
//		
//		
//		// Collision with fish
//		if(E == 1)
//		{
//			if (eT <= 6)
//			{
//				eat(eT, dix);
//				eT += 0.3;
//			}
//			else
//			{
//				E = 0;
//				eT = 0;
//			}
//		}
//		//f1
//		if (p.getGlobalBounds().intersects(f1.getGlobalBounds()))
//		{
//			E = 1;
//			f1.setScale(0, 0);
//			b1.play();
//		}
//
//		diT += dt;
//		mT += dt;
//		if(diT >= 2)
//		{
//			d = rand() % 3 - 1;
//
//			diT = 0;
//		}
//		if (d == 0)
//			d = 0.4;
//		std::cout << d << std::endl;
//		if (mT >= 1)
//		{
//			Vx = (rand() % 9) / 6.0 + 0.1;
//			Vy = (rand() % 9) / 6.0 + 0.1;
//			mT = 0;
//		}
//		f1.move(Vx * d, Vy * d);
//		std::cout << Vx << ' ' << Vy << std::endl;
//
//
//
//
//		// Final velocity
//		p.move(vx, vy);
//
//
//		window.clear();
//
//		window.draw(b);
//		window.draw(p);
//		window.draw(f1);
//
//		window.display();
//	}
//
//	return 0;
//}
//
//
//