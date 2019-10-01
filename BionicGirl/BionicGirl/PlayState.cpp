#include <stdio.h>
#include "PlayState.h"
#include "Player.h"

PlayState PlayState::m_playState;

void PlayState::init() {
	// Read a scene with world, player and enemies.
	TextureMngInst::Instance()->load("./assets/black-mage.bmp", "blackmage");
	TextureMngInst::Instance()->load("./assets/icon.bmp", "icon");

	GameObject* m_pPlayer = new Player();
	m_pPlayer->load(0, 0, 42, 48, "blackmage");
	GameObject* m_pEnemy = new GameObject();
	m_pEnemy->load(50, 0, 42, 48, "icon");

	m_gameObjects.push_back(m_pPlayer);
	m_gameObjects.push_back(m_pEnemy);

	printf("PlayState Init Successful\n");
}

void PlayState::clean() {
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	// Free memory
	m_gameObjects.shrink_to_fit();

	SDL_RenderClear(GameInst::Instance()->get_renderer());
	printf("PlayState Clean Successful\n");
}

void PlayState::pause() {
	printf("PlayState Paused\n");
}

void PlayState::resume() {
	printf("PlayState Resumed\n");
}

void PlayState::handle_events() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameInst::Instance()->quit();
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE: // pause play
				GameInst::Instance()->push_state(PauseState::Instance());
				break;
			}
		}
	}
}

void PlayState::update(const float deltaTime) {
	// Not impl yet.
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update(deltaTime);
	}
}

void PlayState::draw() {
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}
