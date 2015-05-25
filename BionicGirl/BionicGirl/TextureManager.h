#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include <map>

using namespace std;

class TextureManager{
public:
	~TextureManager(){
	};

	bool Load(const char* fileName, string id);
	void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);

	map<string, SDL_Texture*> m_textureMap;

private:
	TextureManager(){
	};

	friend class Singleton<TextureManager>;
};

typedef Singleton<TextureManager> TextureMngInst;

