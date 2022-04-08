#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class Block
{
public:
	Block(sf::Vector2f aPosition, float aWidth, float aHeight);
	~Block();
	Block(Block& other);

	Block& operator=(const Block& other);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f aPosition);

	float getWidth();
	void setWidth(float aWidth);

	float getHeight();
	void setHeight(float aHeight);

private:
	sf::Vector2f mPosition;
	float		 mWidth;
	float		 mHeight;
};


#endif // !BLOCK_H
