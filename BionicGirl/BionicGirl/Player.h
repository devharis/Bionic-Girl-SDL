#pragma once

#include "GameObject.h"

class Player : public GameObject {
public:
	Player::Player() {};
	Player::Player(Vector2D position, const int width, const int height, const string textureId);

	void update(const float deltaTime) override;
	void draw() override;
	void clean() override;
};

