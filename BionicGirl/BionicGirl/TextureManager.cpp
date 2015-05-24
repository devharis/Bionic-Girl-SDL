#include "TextureManager.h"

bool TextureManager::Load(const char* fileName, string id){
	SDL_Surface* pTempSurface = IMG_Load(fileName);

	if (!pTempSurface){
		IMG_GetError();
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(GameInst::Instance()->GetRenderer(), pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture)
	{
		m_textureMap[id] = pTexture;
		return true;
	}
	// reaching here means something went wrong
	return false;
}

void TextureManager::Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip){
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(GameInst::Instance()->GetRenderer(), m_textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_RendererFlip flip){
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentFrame - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(GameInst::Instance()->GetRenderer(), m_textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}