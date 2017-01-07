#include"CGameStateMgr.hpp"

int main()
{
	CGameStateMgr game;
	game.changeState(CGameStateMgr::GAME_STATE::MENU_STATE);

	while (game.isRunning()) {
		game.Run();
	}

	return 0;
}