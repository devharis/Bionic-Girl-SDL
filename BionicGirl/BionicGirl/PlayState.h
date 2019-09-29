#pragma once

#include "PauseState.h"
#include "GameState.h"
#include "GameObject.h"
#include "Game.h"

class PlayState : public GameState {
public:
	void init() override;
	void clean() override;
	void pause() override;
	void resume() override;
	void handle_events() override;
	void update(const double deltaTime) override;
	void draw() override;

	static PlayState* Instance() {
		return &m_playState;
	}

private:
	static PlayState m_playState;
	vector<GameObject*> m_gameObjects;
};

