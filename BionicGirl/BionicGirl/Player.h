#pragma once

#include "GameObject.h"
#include "InputHandler.hpp"

class Player : public GameObject {
public:
    Player() {};
    Player(Vector2D position, const int width, const int height, const string textureId);

	void update(const float deltaTime) override;
	void draw() override;
	void clean() override;
private:
    void handleInput();
};

