#include "Block.h"

Block::Block(sf::Vector2f aPosition, float aWidth, float aHeight):
	mPosition		(aPosition),
	mWidth			(aWidth),
	mHeight			(aHeight)

{

}

Block::Block(Block& other)
{
	mPosition = other.mPosition;
	mWidth = other.mWidth;
	mHeight = other.mHeight;
}

Block&
Block::operator=(const Block& other)
{
	mPosition = other.mPosition;
	mWidth = other.mWidth;
	mHeight = other.mHeight;
	return *this;
}



Block::~Block()
{
}

sf::Vector2f 
Block::getPosition()
{
	return mPosition;
}

void 
Block::setPosition(sf::Vector2f aPosition)
{
	mPosition = aPosition;
}

float 
Block::getWidth()
{
	return mWidth;
}

void Block::setWidth(float aWidth)
{
	mWidth = aWidth;
}

float Block::getHeight()
{
	return mHeight;
}

void Block::setHeight(float aHeight)
{
	mHeight = aHeight;
}

sf::Vector2f Block::getPoint(size_t aPoint)
{
  if (aPoint == 0)
  {
	return mPosition;
  }
  if (aPoint == 1)
  {
	return mPosition + sf::Vector2f(mWidth, 0.0f);
  }
  if (aPoint == 2)
  {
	return mPosition + sf::Vector2f(mWidth, mHeight);
  }
  if (aPoint == 3)
  {
	return mPosition + sf::Vector2f(0.0f, mHeight);
  }
  return sf::Vector2f(0.0f, 0.0f);
}
