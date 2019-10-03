#include "Player.h"

const float SPEED = 0.2f;

Player::Player(Vector2D position, const int width, const int height, const string textureId)
{
	m_position = position; 
	m_width = width;  
	m_height = height; 
	m_textureId = textureId;
}

void Player::update(const float deltaTime) {
	auto x_position = m_position.getX();
	auto new_position = x_position + (deltaTime * SPEED);
	m_position.setX(new_position);
	cout << new_position;
	cout << "\n";
}

void Player::draw() {
	GameObject::draw();
}

void Player::clean() {
	delete this;
}