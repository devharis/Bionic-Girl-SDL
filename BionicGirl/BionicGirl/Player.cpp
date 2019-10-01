#include "Player.h"


void Player::update(const float deltaTime) {
	m_y += 1 * deltaTime;
	m_x += 1 * deltaTime;
}

void Player::draw() {
	GameObject::draw();
}

void Player::clean() {
}