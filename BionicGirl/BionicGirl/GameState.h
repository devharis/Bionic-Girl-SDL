#pragma once

#include "Game.h"

class GameState {
public:
	virtual void init() = 0;
	virtual void clean() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
	virtual void handle_events() = 0;
	virtual void update(double deltaTime) = 0;
	virtual void draw() = 0;

	void change_state(GameState* state) {
		GameInst::Instance()->change_state(state);
	}
};

