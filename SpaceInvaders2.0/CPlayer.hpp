#ifndef CPLAYER_HPP
#define CPLAYER_HPP

#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>
#include"cBulletMgr.hpp"

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X);}}

#define LIVES 3;
#define HEALTHBAR_HEIGHT 25.F
#define HEALTHBAR_WIDTH  75.F

class CPlayer : public sf::Sprite {
public:
	CPlayer ();
	CPlayer (sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath);
	~CPlayer();

	bool Update(sf::Time &deltaTime, sf::Vector2f &moveVector);
	void Render(sf::RenderWindow *pWin);
	void subHealth(int value);

private:
	sf::Texture  *_pPlayerTex;
	sf::Vector2f *_moveVector;
	sf::Time     *_bulletShootDelay;

	sf::RectangleShape *_healthBar;
	int *_currentHealth;

};

#endif