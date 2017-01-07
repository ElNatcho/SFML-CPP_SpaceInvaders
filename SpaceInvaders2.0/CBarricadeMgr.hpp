#ifndef CBARRICADEMGR_HPP
#define CBARRICADEMGR_HPP

#include"CBarricade.hpp"
#include<vector>

class CBarricadeMgr {
public:
	CBarricadeMgr();
	CBarricadeMgr(sf::RenderWindow *pWin);
	~CBarricadeMgr();

	void Update();
	void Render();

	std::vector<CBarricade*> *getBarricadeList();

private:
	sf::RenderWindow *_pMainWin;

	CBarricade *_tempBarricade;
	std::vector<CBarricade*> *_barricadeList;

	void _setup();

};

#endif