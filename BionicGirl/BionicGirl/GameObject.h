#pragma once

#include <SDL.h>
#include "Game.h"

class GameObject {

public:
	void load(const int x, const int y, const int width, const int height, const string textureId);

	virtual void update();
	virtual void draw();
	virtual void clean();
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	string m_textureId;
};

