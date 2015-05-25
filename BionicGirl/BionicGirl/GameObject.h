#pragma once
#include <SDL.h>
#include "Game.h"

class GameObject{

public:
	GameObject(){
	}

protected:
	~GameObject(){
	}

public:
	void Load(int x, int y, int width, int height, string textureId);

	virtual void Update();
	virtual void Draw();
	virtual void Clean();
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	string m_textureId;
};

