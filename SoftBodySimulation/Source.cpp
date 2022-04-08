#include <iostream>
#include <vector>
#include <chrono>

#include "Point.h"
#include "Graphics.h"
#include "Block.h"

#define GRAVITY sf::Vector2f(0,9.8)
#define KOEF float(1.1)

void timeStamp(sf::Event& event, size_t& timeStamper)
{
	for (long long i = 0; i < timeStamper; i++)
	{
		if (event.type == sf::Event::KeyReleased) {
			switch (event.key.code)
			{
			case sf::Keyboard::Key::Up:
				timeStamper *= 8;
				break;
			case sf::Keyboard::Key::Down:
				timeStamper /= 8;
				break;
			case sf::Keyboard::Key::Tab:
				timeStamper = 1;
				break;
			default:
				break;
			}
		}
	}
}

sf::Vector2f changeCoords(std::pair<int,int> pair)
{
	return sf::Vector2f(pair.first, pair.second);
}


double getSec(std::chrono::high_resolution_clock::time_point& start)
{
	if (start.time_since_epoch().count() != 0)
	{
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> sec = end - start;

		return sec.count()*float(10000);
	}
	else
	{
		return 0;
	}
}

bool checkCollision(Point& point, Block& rectangle)
{

	return true;
}

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "GENETIC", sf::Style::Default, settings);


	sf::Vector2f gravity = sf::Vector2f(0, 9.8);
	Graphics graph;
	sf::CircleShape point(5.f);

	size_t timeStamper = 1 * 8 * 8 * 8 * 8 * 8 * 8 * 8;

	std::vector<Point*>cube(1);

	cube[0] = new Point(sf::Vector2f(0, 0));
	/*
	cube[1] = new Point(sf::Vector2f(10, 0));
	cube[2] = new Point(sf::Vector2f(0, 10));
	cube[3] = new Point(sf::Vector2f(10, 10));
	*/
	std::chrono::high_resolution_clock::time_point startCollision;

	sf::RectangleShape rectangle1(sf::Vector2f(100,10));
	rectangle1.setPosition(0, 250);
	std::vector<sf::RectangleShape> rectangles;
	rectangles.push_back(rectangle1);
	std::cout << rectangle1.getPosition().x << ' ' << rectangle1.getPosition().y << std::endl;
	std::cout << rectangle1.getPoint(0).x << ' ' << rectangle1.getPoint(0).y << std::endl;
	std::cout << rectangle1.getPoint(1).x << ' ' << rectangle1.getPoint(1).y << std::endl;
	std::cout << rectangle1.getPoint(2).x << ' ' << rectangle1.getPoint(2).y << std::endl;
	std::cout << rectangle1.getPoint(3).x << ' ' << rectangle1.getPoint(3).y << std::endl;

	bool flag = false;
	while (window.isOpen()) {
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//point.move(cube[0]->getPosition());
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		//std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		/*
		for (int i = 0;i < cube.size();i++)
		{
			point.move(cube[i]->getPosition());
			window.draw(point);
		}
		*/

		float u = getSec(startCollision);
		//if pos ==240 
		for (int i = 0;i < rectangles.size();i++)
		{
			if (point.getGlobalBounds().intersects(rectangles[i].getGlobalBounds()) && (u >= 1 || !flag))
			{

				flag = !flag;
				startCollision = std::chrono::high_resolution_clock::now();
				sf::Vector2f norm(rectangles[i].getPoint(1));
				sf::Vector2f antiNorm;

				/*if (norm.y == 0.f) {
					antiNorm = sf::Vector2f(norm.y, -norm.x);
				}
				else
				{
					antiNorm = sf::Vector2f(-norm.y, norm.x);
				}*/

				antiNorm = sf::Vector2f(norm.y, norm.x);
				float dot = (cube[0]->getVelocity().x * antiNorm.x + cube[0]->getVelocity().y * antiNorm.y)/(antiNorm.x*antiNorm.x+antiNorm.y*antiNorm.y);
				cube[0]->setVelocity((cube[0]->getVelocity() -float(2) * sf::Vector2f(antiNorm.x * dot, antiNorm.y * dot))/KOEF);
			}
		}

		cube[0]->setForce(sf::Vector2f(0, 0));
		cube[0]->setForce(gravity * cube[0]->getMass());
		float ssec = getSec(start);
		std::cout << ssec << std::endl;
		cube[0]->setVelocity(cube[0]->getVelocity() + cube[0]->getForce() * ssec);
		cube[0]->setPosition(cube[0]->getPosition() + cube[0]->getVelocity() * ssec);

		if (point.getPosition().y >= 240)
		{
			int k = 0;
		}

		sf::Vector2f curPos = cube[0]->getPosition();
		sf::Vector2f curVel = cube[0]->getVelocity();
		std::cout << curVel.x << ' ' << curVel.y << std::endl;
		point.setPosition(curPos);
		window.draw(point);

		for (int i = 0;i < rectangles.size();i++) {
			window.draw(rectangles[i]);
		}

		//draw points
		
		window.display();
		//timeStamp(event, timeStamper);



	}
}