#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "point.hpp"
#include "block.hpp"

class Graphics
{
public:
	Graphics(unsigned int weight, unsigned int height);
	~Graphics();

	void render(Point *pointToDraw);
	void render(Block *pointToDraw);

	sf::RenderWindow *getRenderWindow();

private:
	sf::RenderWindow *mWindow;
	sf::ContextSettings mSettings;
};

#endif // !GRAPHICS_H
