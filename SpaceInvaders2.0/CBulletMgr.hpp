#ifndef CBULLETMGR_HPP
#define CBULLETMGR_HPP

#include<SFML\Graphics.hpp>
#include<exception>
#include<iostream>
#include<vector>
#include"CBullet.hpp"

class CBulletMgr {
public:
	CBulletMgr();
	CBulletMgr(sf::RenderWindow *pMainWin);
	~CBulletMgr();

	static void addBullet(sf::Vector2f initPos, CBullet::TAG tag);

	void Update(sf::Time &deltaTime);
	void Render();

	static std::vector<CBullet*> *getBulletList();

private:
	static CBullet *_tempBullet;
	static std::vector<CBullet*> *_bulletList;

	static sf::RenderWindow *_pMainWin;

};

#endif