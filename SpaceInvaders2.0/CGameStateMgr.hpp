#ifndef CGAMESTATEMGR_HPP
#define CGAMESTATEMGR_HPP

#pragma once

#include<SFML\Graphics.hpp>
#include<iostream>
#include<memory>

#include"CGameState.hpp"
#include"CPlayState.hpp"
#include"CEndState.hpp"
#include"CMainMenuState.hpp"

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X);}}
#define WIN_WIDTH  1280
#define WIN_HEIGHT 720

class CGameStateMgr {
public:
	enum GAME_STATE { PLAY_STATE, MENU_STATE, END_STATE };

	CGameStateMgr ();
	~CGameStateMgr();

	void Run	    ();
	bool isRunning  ();
	void changeState(GAME_STATE newState);

	sf::RenderWindow *window;

	sf::Time *deltaTime;

	bool *running;

	int *score;

private:
	std::unique_ptr<CGameState> _currentState;

	CTimeMgr *_timeMgr;

	sf::Font *_font;
	sf::Text *_tFrames;
	sf::Time *_frameTime;
	int *_iCurrentFrames;


};

#endif