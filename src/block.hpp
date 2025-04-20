#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

#include "service.hpp"

class Block
{
public:
	Block(sf::Vector2f aPosition, float aWidth, float aHeight);
	Block(Block &other);
	~Block();

	sf::Vector2f getPosition();
	size_t getRotation();
	float getWidth();
	float getHeight();

	void setPosition(sf::Vector2f aPosition);
	void setWidth(float aWidth);
	void setHeight(float aHeight);
	void setRotation(size_t ratio);
	void rotate(size_t ratio);

	Projection getProjection();

	sf::Vector2f getPoint(size_t aPoint);

	Block &operator=(const Block &other);

private:
	sf::Vector2f mPosition;
	float mWidth;
	float mHeight;
	size_t mRatio;
};

#endif // !BLOCK_H
