#ifndef CENDSTATE_HPP
#define CENDSTATE_HPP

#include"CGameStateMgr.hpp"

class CEndState : public CGameState {
public:
	CEndState(CGameStateMgr &gameStateMgr, int score);
	~CEndState();

	void HandleEvents(CGameStateMgr &gameStateMgr) override;
	void Update      (CGameStateMgr &gameStateMgr) override;
	void Render      (CGameStateMgr &gameStateMgr) override;

private:
	sf::Event *_sfEvent;
		
	int		 *_iScore;
	sf::Font *_font;
	sf::Text *_tScore;
	
	sf::Text *_tBackToPlayState;
	sf::Text *_tBackToMenuState;
	bool *_bBTMenuSelected;
	bool *_bBTPlaySelected;

};

#endif