#ifndef CMAINMENUSTATE_HPP
#define CMAINMENUSTATE_HPP

#include"CGameStateMgr.hpp"


class CMainMenuState : public CGameState {
public:
	CMainMenuState(CGameStateMgr &gameStateMgr);
	~CMainMenuState();

	void HandleEvents(CGameStateMgr &gameStateMgr) override;
	void Update		 (CGameStateMgr &gameStateMgr) override;
	void Render		 (CGameStateMgr &gameStateMgr) override;

private:
	sf::Event *_sfEvent;

	sf::Font *_font;
	sf::Text *_tTitle;
	sf::Text *_tStartGame;
	sf::Text *_tEndGame;
	sf::Text *_tVersion;
	sf::Text *_tMaker;

	bool *_bStartSelected;
	bool *_bEndSelected;

};

#endif