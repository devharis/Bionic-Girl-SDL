#include "Player.h"

const float SPEED = 0.2;

void Player::update(const float deltaTime) {
	m_y += deltaTime * SPEED;
	m_x += deltaTime * SPEED;
}

void Player::draw() {
	GameObject::draw();
}

void Player::clean() {
	delete this;
}