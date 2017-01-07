#include "CTimeMgr.hpp"

CTimeMgr::CTimeMgr()
{
	std::cout << ">CTimeMgr: Konstruktor." << std::endl;

	_clock   = new sf::Clock();
	_elapsed = new sf::Time ();

}

void CTimeMgr::getElapsedTime(sf::Time *tempClock)
{
	*_elapsed  =  _clock->restart();
	*tempClock = *_elapsed;
}

CTimeMgr::~CTimeMgr()
{
	std::cout << ">CTimeMgr: Destruktor." << std::endl;

	SAFE_DELETE(_clock);
	SAFE_DELETE(_elapsed);

}