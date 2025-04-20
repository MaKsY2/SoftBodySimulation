#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "point.hpp"
#include "graphics.hpp"
#include "block.hpp"

const sf::Vector2f gravity = {0, 0.05};
const float k = 1.2f;
const unsigned int weight = 1600;
const unsigned int height = 900;

bool checkCollision(Point *&point, Block *&block)
{

	sf::Vector2f sideVector = block->getPoint(1) - block->getPoint(0);
	// kx+b=y
	float k;
	float b;
	sf::Vector2f normVector;
	if (block->getPoint(1).x - block->getPoint(0).x == 0)
	{
		k = 0;
		b = block->getPoint(1).y - block->getPoint(0).y;
		normVector = {1, 0};
	}
	else if (block->getPoint(1).y - block->getPoint(0).y == 0)
	{
		k = 0;
		b = block->getPoint(1).x - block->getPoint(0).x;
		normVector = {0, 1};
	}
	else
	{
		k = std::fabs((block->getPoint(1).y - block->getPoint(0).y) / (block->getPoint(1).x - block->getPoint(0).x));
		b = block->getPoint(0).y - k * block->getPoint(0).x;
		normVector = {k, 1};
	}
	float x = (b + point->getPosition().x - point->getPosition().y * normVector.x) / (normVector.y - k);
	float y = k * x + b;
	sf::Vector2f pptOnVector = {x, y};
	sf::Vector2f distVector = {x - point->getPosition().x, y - point->getPosition().y};
	float dist = std::sqrt(distVector.x * distVector.x + distVector.y * distVector.y);
	if (dist <= point->getRadius())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkCollision2(Point *&point, Block *&block)
{
	if (
		block->getProjection().xMin > point->getProjection().xMin &&
			block->getProjection().xMin > point->getProjection().xMax ||
		block->getProjection().xMax < point->getProjection().xMin &&
			block->getProjection().xMax < point->getProjection().xMax ||
		block->getProjection().yMin > point->getProjection().yMin &&
			block->getProjection().yMin > point->getProjection().yMax ||
		block->getProjection().yMax < point->getProjection().yMin &&
			block->getProjection().yMax < point->getProjection().yMax)
	{
		return false;
	}
	float A = block->getPoint(0).y - block->getPoint(1).y;
	float B = block->getPoint(1).x - block->getPoint(0).x;
	float C = block->getPoint(0).x * block->getPoint(1).y - block->getPoint(1).x * block->getPoint(0).y;
	float dist = std::abs(A * point->getPosition().x + B * point->getPosition().y + C) / std::sqrt(A * A + B * B);
	if (dist <= point->getRadius())
	{
		return true;
	}
	return false;
}

int main()
{
	Graphics graph(weight, height);

	std::vector<Point *> points(3);
	points[0] = new Point(sf::Vector2f(point_radius, point_radius), point_radius);
	points[1] = new Point(sf::Vector2f(point_radius + 50.f, point_radius), point_radius);
	points[2] = new Point(sf::Vector2f(point_radius + 150.f, point_radius), point_radius);

	std::vector<Block *> blocks(1);
	blocks[0] = new Block(sf::Vector2f(0.0f, 250.0f), 100.0f, 10.0f);

	while (graph.getRenderWindow()->isOpen())
	{
		graph.getRenderWindow()->clear();

		while (const std::optional event = graph.getRenderWindow()->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				graph.getRenderWindow()->close();
		}

		for (size_t j = 0; j < points.size(); j++)
		{
			for (size_t i = 0; i < blocks.size(); i++)
			{
				if (checkCollision2(points[j], blocks[i]))
				{
					sf::Vector2f norm(blocks[i]->getPoint(1) - blocks[i]->getPoint(0));
					sf::Vector2f antiNorm;
					antiNorm = sf::Vector2f(norm.y, norm.x);
					float dot = (points[j]->getVelocity().x * antiNorm.x + points[j]->getVelocity().y * antiNorm.y) / (antiNorm.x * antiNorm.x + antiNorm.y * antiNorm.y);
					points[j]->setVelocity((points[j]->getVelocity() - float(2) * sf::Vector2f(antiNorm.x * dot, antiNorm.y * dot)) / k);
					points[j]->setForce(sf::Vector2f(0, 0));
				}
				else
				{
					points[j]->setForce(gravity * points[j]->getMass());
				}
				points[j]->setVelocity(points[j]->getVelocity() + points[j]->getForce());
				points[j]->setPosition(points[j]->getPosition() + points[j]->getVelocity());
			}
		}

		for (size_t i = 0; i < points.size(); i++)
		{
			graph.render(points[i]);
		}
		for (size_t i = 0; i < blocks.size(); i++)
		{
			graph.render(blocks[i]);
		}
		graph.getRenderWindow()->display();
	}
}
