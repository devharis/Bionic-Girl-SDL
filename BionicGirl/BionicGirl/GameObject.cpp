#include "GameObject.h"

GameObject::GameObject(const Vector2D position, const int width, const int height, const string textureId)
{
	m_position = position;  m_width = width;  m_height = height; m_textureId = textureId;
    m_currentRow = 1;
    m_currentFrame = 1;
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
    if (m_velocity.getX() > 0)
    {
        m_flip = SDL_FLIP_HORIZONTAL;
    }
    if (m_velocity.getX() < 0)
    {
        m_flip = SDL_FLIP_NONE;
    }
    
    TextureMngInst::Instance()->draw(m_textureId, m_position, m_width, m_height, m_flip);
}

void GameObject::clean() {
	delete this;
}
