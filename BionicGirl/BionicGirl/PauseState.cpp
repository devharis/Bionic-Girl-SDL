#include <stdio.h>

#include "SDL.h"
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

void PauseState::Init()
{
	pauseSprite = NULL;

	/*pauseSprite = Sprite::Load("paused.bmp");*/

	printf("PauseState Init Successful\n");
}

void PauseState::Clean()
{
	printf("PauseState Clean Successful\n");
}

void PauseState::Resume(){}

void PauseState::Pause() {}

void PauseState::HandleEvents()
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
				GameInst::Instance()->PopState();
				break;
			}
		}
	}
}


void PauseState::Update()
{
}

void PauseState::Draw()
{
	//Sprite::Draw(game->GetScreen(), pauseSprite, 0, 0);
	//SDL_Flip(game->GetScreen());
}
