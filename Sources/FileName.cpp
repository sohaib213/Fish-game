//#include <SFML/Graphics.hpp>
//#include <cstdlib>
//#include <ctime>
//#include <vector>
//
//class Circle {
//public:
//    Circle(float x, float y, float radius) : x(x), y(y), radius(radius) {
//        shape.setRadius(radius);
//        shape.setFillColor(sf::Color::Red);
//        shape.setPosition(x, y);
//        velocity = sf::Vector2f((rand() % 3) - 1, (rand() % 3) - 1); // Random velocity
//    }
//
//    void move() {
//        x += velocity.x;
//        y += velocity.y;
//
//        //// Bounce off the walls
//        //if (x - radius < 0 || x + radius > WIDTH)
//        //    velocity.x = -velocity.x;
//        //if (y - radius < 0 || y + radius > HEIGHT)
//        //    velocity.y = -velocity.y;
//
//        shape.setPosition(x, y);
//    }
//
//    void draw(sf::RenderWindow& window) {
//        window.draw(shape);
//    }
//
//private:
//    float x, y, radius;
//    sf::Vector2f velocity;
//    sf::CircleShape shape;
//    static const int WIDTH = 800;
//    static const int HEIGHT = 600;
//};
//
//int main() {
//    srand(time(NULL)); // Seed random number generator
//
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circles");
//
//    std::vector<Circle> circles;
//    for (int i = 0; i < 10; ++i) {
//        float x = rand() % 800;
//        float y = rand() % 600;
//        float radius = rand() % 20 + 10; // Random radius between 10 and 30
//        circles.push_back(Circle(x, y, radius));
//    }
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear(sf::Color::White);
//
//        for (auto& circle : circles) {
//            circle.move();
//            circle.draw(window);
//        }
//
//        window.display();
//    }
//
//    return 0;
//}
