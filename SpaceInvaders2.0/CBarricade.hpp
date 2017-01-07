#ifndef CBARRICADES_HPP
#define CBARRICADES_HPP

#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X);}}

#define TILE_HEIGHT 11
#define TILE_WIDHT  11

class CBarricade : public sf::Sprite {
public:
	CBarricade();
	CBarricade(sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath);
	~CBarricade();

	void subStatus(int value);
	int  getStatus();

private:
	sf::Texture *_barricadeTexture;

	int *_iStatus;


};

#endif