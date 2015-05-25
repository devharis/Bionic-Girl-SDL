#include "GameObject.h"

void GameObject::Load(int x, int y, int width, int height, string textureId){
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureId = textureId;
}

void GameObject::Update(){
	// Not used yet.
}

void GameObject::Draw(){
	TextureMngInst::Instance()->Draw(m_textureId, m_x, m_y, m_width, m_height, SDL_FLIP_HORIZONTAL);
}

void GameObject::Clean(){
	delete this;
}