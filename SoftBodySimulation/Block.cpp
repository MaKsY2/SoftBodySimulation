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
