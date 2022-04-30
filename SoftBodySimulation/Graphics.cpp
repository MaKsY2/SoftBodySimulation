#include "Graphics.h"

#include <SFML/Graphics.hpp>

Graphics::Graphics(float weight,float height)
{
  mSettings.antialiasingLevel = 8;
  mWindow = new sf::RenderWindow(sf::VideoMode(weight, height), "SoftBodySimulation", sf::Style::Default, mSettings);
  mWindow->setFramerateLimit(60);
}

void
Graphics::render(Point* pointToDraw)
{
  sf::CircleShape ppt(pointToDraw->getRadius());
  ppt.setPosition(pointToDraw->getPosition());
  mWindow->draw(ppt);
}

void Graphics::render(Block* blockToDraw)
{
  sf::RectangleShape ppt(sf::Vector2f(blockToDraw->getWidth(),blockToDraw->getHeight()));
  ppt.setPosition(blockToDraw->getPosition());
  mWindow->draw(ppt);
}

sf::RenderWindow*
Graphics::getRenderWindow()
{
  return mWindow;
}

Graphics::~Graphics()
{
}
