#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "Point.h"
#include "Graphics.h"
#include "Block.h"

#include <SFML/Graphics.hpp>

const sf::Vector2f gravity = { 0,9.8 };
const float k = 1.1f;
const float weight = 1600.0f;
const float height = 900.0f;

bool checkCollision(Point*& point, Block*& block)
{

  sf::Vector2f sideVector = block->getPoint(1) - block->getPoint(0);
  float dist;
  return true;
}

int main()
{
  Graphics graph(weight,height);

  std::vector<Point*> points(1);
  points[0] = new Point(sf::Vector2f(point_radius, point_radius), point_radius);

  std::vector<Block*> blocks(1);
  blocks[0] = new Block(sf::Vector2f(0.0f,250.0f),100.0f,10.0f);
  
  while (graph.getRenderWindow()->isOpen()) {
	graph.getRenderWindow()->clear();

	sf::Event event;
	while (graph.getRenderWindow()->pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
		graph.getRenderWindow()->close();
	}

	for (size_t j = 0;j < points.size();j++)
	{
	  for (size_t i = 0;i < blocks.size();i++)
	  {
		if (checkCollision(points[j],blocks[i]))
		{
		  sf::Vector2f norm(blocks[i]->getPoint(1));
		  sf::Vector2f antiNorm;
		  antiNorm = sf::Vector2f(norm.y, norm.x);
		  float dot = (points[j]->getVelocity().x * antiNorm.x + points[j]->getVelocity().y * antiNorm.y) / (antiNorm.x * antiNorm.x + antiNorm.y * antiNorm.y);
		  points[j]->setVelocity((points[j]->getVelocity() - float(2) * sf::Vector2f(antiNorm.x * dot, antiNorm.y * dot)) / k);
		  points[j]->setForce(sf::Vector2f(0, 0));
		}
		else
		{
		  points[j]->setForce(gravity * points[0]->getMass());
		}
		points[j]->setVelocity(points[j]->getVelocity() + points[j]->getForce());
		points[j]->setPosition(points[j]->getPosition() + points[j]->getVelocity());
	  }
	}

	for (size_t i = 0;i < points.size();i++)
	{
	  graph.render(points[i]);
	}
	for (size_t i = 0;i < blocks.size();i++) {
	  graph.render(blocks[i]);
	}
	graph.getRenderWindow()->display();

  }
}
