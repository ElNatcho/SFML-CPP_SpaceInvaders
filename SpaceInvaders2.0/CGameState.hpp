#ifndef CGAMESTATE_HPP
#define CGAMESTATE_HPP

#pragma once

#include<SFML\Graphics.hpp>
#include<iostream>
#include"CTimeMgr.hpp"

class CGameStateMgr;

class CGameState {
public:
	virtual void HandleEvents(CGameStateMgr &gameStateMgr) {};
	virtual void Update		 (CGameStateMgr &gameStateMgr) {};
	virtual void Render		 (CGameStateMgr &gameStateMgr) {};
	virtual    ~ CGameState  ()							   {};

};

#endif