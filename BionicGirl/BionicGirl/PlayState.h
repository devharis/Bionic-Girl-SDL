#pragma once

#include "PauseState.h"
#include "GameState.h"
#include "GameObject.h"
#include "Game.h"

class PlayState : public GameState{
public:
	void Init() override;
	void Clean() override;
	void Pause() override;
	void Resume() override;
	void HandleEvents() override;
	void Update(double deltaTime) override;
	void Draw() override;

	static PlayState* Instance(){
		return &m_PlayState;
	}

protected:
	~PlayState(){
	}

	PlayState(){
	}

private:
	static PlayState m_PlayState;
	vector<GameObject*> m_gameObjects;
};

