#ifndef POINT_H
#define POINT_H

#include <utility>

#include <SFML/Graphics.hpp>

#include "service.hpp"

const float point_mass = 0.1f;
const float point_radius = 5.f;

class Point
{
public:

  Point(sf::Vector2f  aPosition, float aRadius);
  Point(Point& other);
  ~Point();

  sf::Vector2f getPosition();
  sf::Vector2f  getVelocity();
  sf::Vector2f  getForce();
  float getMass();
  float getRadius();

  void setPosition(sf::Vector2f  aPosition);
  void setVelocity(sf::Vector2f  aVelocity);
  void setForce(sf::Vector2f  aForce);
  void setRadius(float aRadius);
  void setMass(float aMass);

  Projection getProjection();

  Point& operator= (const Point& other);

private:
  sf::Vector2f  mPosition;
  sf::Vector2f  mVelocity;
  sf::Vector2f  mForce;
  float mRadius;
  float mMass;
};

#endif // !POINT_H
