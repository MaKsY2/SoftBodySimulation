#ifndef POINT_H
#define POINT_H

#include <utility>
#include <SFML/Graphics.hpp>


#define POINT_MASS 0.1


class Point
{
public:
	Point(sf::Vector2f  aPosition);
	~Point();

	Point(Point& other);

	//set get 
	sf::Vector2f getPosition();
	sf::Vector2f  getVelocity();
	sf::Vector2f  getForce();
	float getMass();



	void setPosition(sf::Vector2f  aPosition);
	void setVelocity(sf::Vector2f  aVelocity);
	void setForce(sf::Vector2f  aForce);
	void setMass(float aMass);

	Point& operator= (const Point& other);

private:
	sf::Vector2f  mPosition;
	sf::Vector2f  mVelocity;
	sf::Vector2f  mForce;
	float mMass;
};

#endif // !POINT_H
