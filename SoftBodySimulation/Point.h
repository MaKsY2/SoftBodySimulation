#ifndef POINT_H
#define POINT_H

#include <utility>


#define POINT_MASS 0.1


class Point
{
public:
	Point(std::pair<int, int> aPosition);
	~Point();

	Point(Point& other);

	//set get 

private:
	std::pair<int, int> mPosition;
	std::pair<int, int> mVelocity;
	std::pair<int, int> mForce;
	float mMass;
};

#endif // !POINT_H
