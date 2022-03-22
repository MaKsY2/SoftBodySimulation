#include "Point.h"

Point::Point(std::pair<int,int> aPosition) :
	mPosition		(aPosition),
	mVelocity		(std::make_pair(0,0)),
	mForce			(std::make_pair(0,0)),
	mMass			(POINT_MASS)
{

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
