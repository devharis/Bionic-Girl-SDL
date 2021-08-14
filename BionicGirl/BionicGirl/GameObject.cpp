#include "GameObject.h"

GameObject::GameObject(const Vector2D position, const int width, const int height, const string textureId)
{
	m_position = position;  m_width = width;  m_height = height; m_textureId = textureId;
}

//void GameObject::load(Vector2D position, const int width, const int height, const string textureId) {
//	m_position = position;
//	m_width = width;
//	m_height = height;
//	m_textureId = textureId;
//}

void GameObject::update(const float deltaTime) {
	// Not impl yet.
    m_velocity += m_acceleration * deltaTime;
    m_position += m_velocity;
}

void GameObject::draw() {
	TextureMngInst::Instance()->draw(m_textureId, m_position, m_width, m_height, SDL_FLIP_HORIZONTAL);
}

void GameObject::clean() {
	delete this;
}
