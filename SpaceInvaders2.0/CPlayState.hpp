#ifndef CPLAYSTATE_HPP
#define CPLAYSTATE_HPP

#pragma once

#include"CGameStateMgr.hpp"
#include"CBarricadeMgr.hpp"
#include"CCollisionMgr.hpp"
#include"CInvaderMgr.hpp"
#include"CBulletMgr.hpp"
#include"CPlayer.hpp"

class CPlayState : public CGameState {
public:
	CPlayState(CGameStateMgr &gameStateMgr);
	~CPlayState();

	void HandleEvents(CGameStateMgr &gameStateMgr) override;
	void Update		 (CGameStateMgr &gameStateMgr) override;
	void Render		 (CGameStateMgr &gameStateMgr) override;

private:
	sf::Event *_sfEvent;

	CBarricadeMgr *_pBarricadeMgr;
	CCollisionMgr *_pCollisionMgr;
	CInvaderMgr   *_pInvaderMgr;
	CBulletMgr    *_pBulletMgr;
	CPlayer		  *_pPlayer;

	sf::Font *_font;
	sf::Text *_tScore;
	int      *_iScore;

};

#endif