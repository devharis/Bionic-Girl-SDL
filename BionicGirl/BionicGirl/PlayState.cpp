#include <stdio.h>
#include "PlayState.h"
#include "Player.h"

PlayState PlayState::m_playState;

void PlayState::init() {
	// Read a scene with world, player and enemies.
	TextureMngInst::Instance()->load("./assets/annie.png", "annie");
	TextureMngInst::Instance()->load("./assets/liam.png", "liam");

	Vector2D vPlayer = Vector2D(100, 250);
	GameObject* m_pPlayer = new Player(vPlayer, 32, 32, "annie");
	//m_pPlayer->load(vPlayer, 42, 48, "blackmage");

	Vector2D vEnemy = Vector2D(250, 250);
	GameObject* m_pEnemy = new GameObject(vEnemy, 32, 32, "liam");

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
    if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        GameInst::Instance()->push_state(PauseState::Instance());
    }
    else if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_M))
    {
        GameInst::Instance()->pop_state();
        GameInst::Instance()->change_state(PauseState::Instance());
    }
    else
    {
        // Do nothing
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
