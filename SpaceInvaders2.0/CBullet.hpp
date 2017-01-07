#ifndef CBULLET_HPP
#define CBULLET_HPP

#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>

#define SAFE_DELETE(X) {if(X!=nullptr){delete(X);}}

#define Y_MOVE_SPEED 150.F

class CBullet : public sf::Sprite {
public:

	enum TAG{PLAYER, INVADER};

	CBullet ();
	CBullet (sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath, TAG tag);
	~CBullet();

	void Update(sf::Time &deltTime);
	void setStatus(bool value);
	bool getStatus();
	TAG  getTag();

private:
	sf::Texture  *_bulletTexture;
	sf::Vector2f *_moveVector;
	
	bool *_isActive;

	TAG *_tag;

};

#endif