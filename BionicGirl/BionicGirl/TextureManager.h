#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include <map>
#include <string>

using namespace std;

class TextureManager {
public:
	bool load(const char* fileName, string id);
	void draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw_frame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);

	map<string, SDL_Texture*> m_textureMap;

private:
	friend class Singleton<TextureManager>;
};

typedef Singleton<TextureManager> TextureMngInst;

