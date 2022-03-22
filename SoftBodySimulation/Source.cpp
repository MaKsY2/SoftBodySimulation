#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Graphics.h"

#define GRAVITY float(-9.8)

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


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "GENETIC", sf::Style::Default, settings);

	Graphics graph;

	size_t timeStamper = 1 * 8 * 8 * 8 * 8 * 8 * 8 * 8;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		std::vector<Point>cube(4);

		cube[0] = new Point(std::make_pair(0, 0));
		cube[0] = new Point(std::make_pair(10, 0));
		cube[0] = new Point(std::make_pair(0, 10));
		cube[0] = new Point(std::make_pair(10, 10));

		//draw points
		
		window.display();
		timeStamp(event, timeStamper);
	}
}