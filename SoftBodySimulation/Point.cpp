#include "Point.h"

Point::Point(sf::Vector2f aPosition, float aRadius) :
  mPosition			  (aPosition),
  mVelocity			  (sf::Vector2f(0, 0)),
  mForce			  (sf::Vector2f(0, 0)),
  mRadius			  (aRadius),
  mMass				  (point_mass)
{

}

Point& 
Point::operator= (const Point& other)
{
	mPosition = other.mPosition;
	mVelocity = other.mVelocity;
	mForce = other.mForce;
	mRadius = other.mRadius;
	mMass = other.mMass;
	return *this;
}

float
Point::getRadius()
{
  return mRadius;
}

void
Point::setRadius(float aRadius)
{
  mRadius = aRadius;
}

sf::Vector2f
Point::getPosition()
{
	return mPosition;
}

sf::Vector2f
Point::getVelocity()
{
	return mVelocity;
}

sf::Vector2f
Point::getForce()
{
	return mForce;
}

float
Point::getMass()
{
	return mMass;
}

void
Point::setPosition(sf::Vector2f aPosition)
{
	mPosition = aPosition;
}

void
Point::setVelocity(sf::Vector2f aVelocity)
{
	mVelocity = aVelocity;
}

void
Point::setForce(sf::Vector2f aForce)
{
	mForce = aForce;
}

void 
Point::setMass(float aMass)
{
	mMass = aMass;
}


Point::~Point()
{

}

Point::Point(Point& other)
{
	mPosition = other.mPosition;
	mVelocity = other.mVelocity;
	mForce = other.mForce;
	mMass = other.mMass;
}
