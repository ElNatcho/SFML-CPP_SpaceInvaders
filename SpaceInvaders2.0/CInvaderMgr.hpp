#ifndef CINVADERMGR_HPP
#define CINVADERMGR_HPP

#include<SFML\Graphics.hpp>
#include<iostream>
#include<vector>

#include"CInvader.hpp"
#include"CBulletMgr.hpp"

#define SAFE_DELETE(X){if(X!=nullptr){delete(X);}}

class CInvaderMgr {
public:
	CInvaderMgr ();
	CInvaderMgr (sf::Vector2f &leftUpperPos, sf::Vector2f &initScale, sf::RenderWindow *pMainWin);
	~CInvaderMgr();

	void Init  (sf::Vector2f &leftUpperPos, sf::Vector2f &initScale, sf::RenderWindow *pMainWin);
	bool Update(sf::Time &deltaTime);
	void Render();

	std::vector<std::vector<CInvader*>*> *getInvaderMatrix();

private:
	sf::Time	 *_invUpdateDelay;
	sf::Vector2f *_invInitScale;
	sf::Vector2f *_invLeftUpPos;
	sf::Vector2f *_invMoveVector;

	sf::RenderWindow *_pMainWin;

	CInvader *_tempInvader;
	std::vector<CInvader*> *_tempInvaderList;
	std::vector<std::vector<CInvader*>*> *_invaderMatrix;

	bool *_flipDirection;

	int *_randY;
	int *_randX;

	void _setup();

};

#endif