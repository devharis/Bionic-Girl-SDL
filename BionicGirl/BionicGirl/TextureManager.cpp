#include "TextureManager.h"

bool TextureManager::load(const char* fileName, string id) {
	SDL_Surface* pTempSurface = IMG_Load(fileName);

	if (!pTempSurface) {
		IMG_GetError();
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(GameInst::Instance()->get_renderer(), pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture) {
		m_textureMap[id] = pTexture;
		return true;
	}
	// reaching here means something went wrong
	return false;
}

void TextureManager::draw(const string id, const int x, const int y, const int width, const int height, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(GameInst::Instance()->get_renderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::draw_frame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentFrame - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(GameInst::Instance()->get_renderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}