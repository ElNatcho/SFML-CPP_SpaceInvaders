#ifndef CTIMEMGR_HPP
#define CTIMEMGR_HPP

#pragma once

#include<SFML\Graphics.hpp>
#include<iostream>

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X);}}

class CTimeMgr {
public:
	CTimeMgr ();
	~CTimeMgr();

	void getElapsedTime(sf::Time *tempClock);

private:
	sf::Clock *_clock;
	sf::Time  *_elapsed;


};

#endif