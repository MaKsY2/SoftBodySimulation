#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Point.h"
#include "Block.h"

class Graphics
{
public:
	Graphics(float weight, float height);
	~Graphics();

	void render(Point* pointToDraw);
	void render(Block* pointToDraw);

	sf::RenderWindow* getRenderWindow();

private:
  sf::RenderWindow* mWindow;
  sf::ContextSettings mSettings;
};

#endif // !GRAPHICS_H
