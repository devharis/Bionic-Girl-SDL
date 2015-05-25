#pragma once
#include "GameObject.h"

class Player : public GameObject{
public:
	void Update() override;
	void Draw() override;
	void Clean() override;
public:
	Player();
protected:
	~Player();
};

