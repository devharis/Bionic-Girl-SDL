#include "GameObject.h"

SDL_Surface* m_pSurface;
SDL_Rect SrcR;
SDL_Rect DestR;

void GameObject::Load(char* filename){
	TextureMngInst::Instance()->Load(filename, "player");
}

void GameObject::Update(){
	// nothing for now
}

void GameObject::Draw(){
	TextureMngInst::Instance()->Draw("player", 0, 0, 42, 48, SDL_FLIP_HORIZONTAL);
}

void GameObject::Clean(){
	delete this;
}