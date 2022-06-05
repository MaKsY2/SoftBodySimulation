#include "Block.h"

Block::Block(sf::Vector2f aPosition, float aWidth, float aHeight):
	mPosition		(aPosition),
	mWidth			(aWidth),
	mHeight			(aHeight),
	mRatio          (0)
{

}

Block::Block(Block& other)
{
	mPosition = other.mPosition;
	mWidth = other.mWidth;
	mHeight = other.mHeight;
	mRatio = other.mRatio;
}

Block&
Block::operator=(const Block& other)
{
	mPosition = other.mPosition;
	mWidth = other.mWidth;
	mHeight = other.mHeight;
	mRatio = other.mRatio;
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

size_t Block::getRotation()
{
  return size_t();
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

void Block::setRotation(size_t ratio)
{
  ratio %= 360;
  mRatio = ratio;
}

void Block::rotate(size_t ratio)
{
  ratio %= 360;
  mRatio += ratio;
  mRatio %= 360;
  this->setRotation(mRatio);
}

Projection Block::getProjection()
{
  Projection proj = { 0,0,0,0 };
  float currentX, currentY;
  for (size_t i = 0;i < 4;i++)
  {
	currentX = this->getPoint(i).x;
	currentY = this->getPoint(i).y;
	if (currentX < proj.xMin) proj.xMin = currentX;
	if (currentX > proj.xMax) proj.xMax = currentX;
	if (currentY < proj.yMin) proj.yMin = currentY;
	if (currentY > proj.yMax) proj.yMax = currentY;
  }
  return proj;
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
