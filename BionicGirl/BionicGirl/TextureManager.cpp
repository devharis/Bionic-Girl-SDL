#include "TextureManager.h"

bool TextureManager::load(const char* fileName, string id) {
	SDL_Surface* p_tempSurface = IMG_Load(fileName);

	if (!p_tempSurface) {
		auto error = IMG_GetError();
		cout << error;
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(GameInst::Instance()->get_renderer(), p_tempSurface);
	SDL_FreeSurface(p_tempSurface);

	if (pTexture) {
		m_textureMap[id] = pTexture;
		return true;
	}
	// reaching here means something went wrong
	return false;
}

void TextureManager::draw(const string id, Vector2D position, const int width, const int height, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = (int)position.getX();
	destRect.y = (int)position.getY();
	SDL_RenderCopyEx(GameInst::Instance()->get_renderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::draw_frame(string id, Vector2D position, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentFrame - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = (int)position.getX();
	destRect.y = (int)position.getY();

	SDL_RenderCopyEx(GameInst::Instance()->get_renderer(), m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}