#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height, string textureId) {
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureId = textureId;
}

void GameObject::update(const float deltaTime) {
	// Not impl yet.
}

void GameObject::draw() {
	TextureMngInst::Instance()->draw(m_textureId, m_x, m_y, m_width, m_height, SDL_FLIP_HORIZONTAL);
}

void GameObject::clean() {
	delete this;
}