#pragma once
#include <SDL.h>
#include "Game.h"

class GameObject
{
public:
	GameObject() {}
	~GameObject() {}

	void Load(char* filename);
	void Update();
	void Draw();
	void Clean();
private: 
	SDL_Texture* m_pSprite;
};

