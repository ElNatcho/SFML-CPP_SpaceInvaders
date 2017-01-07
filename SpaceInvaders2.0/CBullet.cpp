#include"CBullet.hpp"

CBullet::CBullet()
{
	std::cout << ">CBullet: Konstruktor." << std::endl;
	 
	_moveVector    = new sf::Vector2f();
	_bulletTexture = new sf::Texture();
	_isActive      = new bool;
	_tag		   = new TAG();

	*_isActive = true;

}

CBullet::CBullet(sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath, TAG tag) : CBullet()
{
	*_tag = tag;

	_moveVector->x = 0.F;

	if (!_bulletTexture->loadFromFile(imagePath))
		std::cout << ">CPlayer: _pPlayerTex konnte nicht geladen werden (" << imagePath << ")!" << std::endl;

	this->setTexture(*_bulletTexture);
	if (*_tag == TAG::INVADER) {
		this->setTextureRect(sf::IntRect(1, 0, 1, 2));
		_moveVector->y = Y_MOVE_SPEED;
	} else {
		this->setTextureRect(sf::IntRect(0, 0, 1, 2));
		_moveVector->y = -Y_MOVE_SPEED;
	}
	this->setPosition(initPos);
	this->setScale(initScale);
}

void CBullet::Update(sf::Time &deltaTime)
{
	this->move(_moveVector->x, _moveVector->y * deltaTime.asSeconds());
}

void CBullet::setStatus(bool value)
{
	*_isActive = value;
}

bool CBullet::getStatus()
{
	return *_isActive;
}

CBullet::TAG CBullet::getTag()
{
	return *_tag;
}

CBullet::~CBullet()
{
	std::cout << ">CBullet: Destruktor." << std::endl;

	SAFE_DELETE(_moveVector);
	SAFE_DELETE(_bulletTexture);
	SAFE_DELETE(_isActive);
	SAFE_DELETE(_tag);

}