#include <iostream>
#include "MenuState.h"

int main(int argc, char* argv[]){
	GameInst::Instance()->Init("Bionic Girl", "./assets/icon.png", 640, 480, false);

	GameInst::Instance()->ChangeState(MenuState::Instance());

	while (GameInst::Instance()->Running()){
		GameInst::Instance()->HandleEvents();
		GameInst::Instance()->Update();
		GameInst::Instance()->Draw();
	}

	GameInst::Instance()->Clean();

	return 0;
}
