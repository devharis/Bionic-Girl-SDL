#pragma once

#include "GameObject.h"

class Player : public GameObject {
public:
	void update(const float deltaTime) override;
	void draw() override;
	void clean() override;
};

