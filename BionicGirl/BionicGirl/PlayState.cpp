#include <stdio.h>
#include "PlayState.h"

PlayState PlayState::m_PlayState;

void PlayState::Init(){
	// Read a scene with world, player and enemies.
	TextureMngInst::Instance()->Load("./assets/black-mage.bmp", "blackmage");
	TextureMngInst::Instance()->Load("./assets/icon.bmp", "icon");

	GameObject* m_pPlayer = new GameObject();
	m_pPlayer->Load(0, 0, 42, 48, "blackmage");
	GameObject* m_pEnemy = new GameObject();
	m_pEnemy->Load(50, 0, 42, 48, "icon");

	m_gameObjects.push_back(m_pPlayer);
	m_gameObjects.push_back(m_pEnemy);

	printf("PlayState Init Successful\n");
}

void PlayState::Clean(){
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->Clean();
	}
	m_gameObjects.clear();
	// Free memory
	m_gameObjects.shrink_to_fit();
	printf("PlayState Clean Successful\n");
}

void PlayState::Pause(){
	printf("PlayState Paused\n");
}

void PlayState::Resume(){
	printf("PlayState Resumed\n");
}

void PlayState::HandleEvents(){
	SDL_Event event;

	if (SDL_PollEvent(&event)){
		switch (event.type){
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
			case SDLK_SPACE:
				GameInst::Instance()->PushState(PauseState::Instance());
				break;
			}
		}
	}
}

void PlayState::Update(double deltaTime){
	// Not used yet.
}

void PlayState::Draw(){
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->Draw();
}
