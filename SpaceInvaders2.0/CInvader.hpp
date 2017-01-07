#ifndef CINVADER_HPP
#define CINVADER_HPP

#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X);}}

const int TILE_WIDTH = 11;

class CInvader : public sf::Sprite {
public:

	enum TYP {INVADER, DESTROYER, GRUND, BOSS};

	CInvader ();
	CInvader (sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath, TYP typ);
	~CInvader();

	void Update(sf::Time &deltaTime, sf::Vector2f &moveVector);
	void setStatus(bool value);
	bool getStatus();
	TYP  getTyp();

public:
	sf::Texture  *_pInvaderTex;
	sf::Vector2f *_moveVector;

	sf::IntRect *_textureRegion;

	int *_iCurrentFrame;

	bool *_isActive;

	TYP *_typ;

};

#endif