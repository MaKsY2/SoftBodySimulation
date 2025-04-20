#include <iostream>

#include <SFML/Graphics.hpp>

#include "graphics.hpp"
Graphics::Graphics(unsigned int weight,unsigned int height)
{
  mSettings.antiAliasingLevel = 8;
  mWindow = new sf::RenderWindow(sf::VideoMode({weight, height}), "Softbody Simulation", sf::State::Windowed);
  mWindow->setFramerateLimit(60);
}

void
Graphics::render(Point* pointToDraw)
{
  sf::CircleShape ppt(pointToDraw->getRadius());
  sf::Vector2f point = { pointToDraw->getPosition().x - pointToDraw->getRadius(), pointToDraw->getPosition().y - pointToDraw->getRadius() };
  std::cout << point.x << ' ' << point.y << std::endl;
  ppt.setPosition(point);
  mWindow->draw(ppt);
}

void Graphics::render(Block* blockToDraw)
{
  sf::RectangleShape ppt(sf::Vector2f(blockToDraw->getWidth(),blockToDraw->getHeight()));
  ppt.setPosition(blockToDraw->getPosition());
  ppt.setRotation(sf::degrees(blockToDraw->getRotation()));
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
