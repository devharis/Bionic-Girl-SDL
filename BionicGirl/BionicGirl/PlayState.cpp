#include <stdio.h>

#include "PlayState.h"

PlayState PlayState::m_PlayState;

void PlayState::Init()
{
	testObject = new GameObject();
	testObject->Load("./assets/black-mage.png");
	printf("PlayState Init Successful\n");
}

void PlayState::Clean()
{
	testObject->Clean();
	printf("PlayState Clean Successful\n");
}

void PlayState::Pause()
{
	printf("PlayState Paused\n");
}

void PlayState::Resume()
{
	printf("PlayState Resumed\n");
}

void PlayState::HandleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
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


void PlayState::Update()
{
}

void PlayState::Draw()
{
	testObject->Draw();
	SDL_RenderPresent(GameInst::Instance()->GetRenderer());
}
