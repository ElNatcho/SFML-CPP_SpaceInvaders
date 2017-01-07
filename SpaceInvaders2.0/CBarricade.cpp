#include"CBarricade.hpp"

CBarricade::CBarricade()
{
	std::cout << ">CBarricade: Konstruktor." << std::endl;

	_barricadeTexture = new sf::Texture();
	_iStatus = new int;

	*_iStatus = 0;

}

CBarricade::CBarricade(sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath) : CBarricade()
{
	if(!_barricadeTexture->loadFromFile(imagePath))
		std::cout << ">CPlayer: _pPlayerTex konnte nicht geladen werden (" << imagePath << ")!" << std::endl;

	this->setTexture(*_barricadeTexture);
	this->setTextureRect(sf::IntRect(*_iStatus * TILE_WIDHT, 0, TILE_WIDHT, TILE_HEIGHT));
	this->setPosition(initPos);
	this->setScale(initScale);

}

void CBarricade::subStatus(int value)
{
	*_iStatus += value;
	this->setTextureRect(sf::IntRect(*_iStatus * TILE_WIDHT, 0, TILE_WIDHT, TILE_HEIGHT));
}

int CBarricade::getStatus()
{
	return *_iStatus;
}

CBarricade::~CBarricade()
{
	std::cout << ">CBarricade: Destruktor." << std::endl;

	SAFE_DELETE(_barricadeTexture);
	SAFE_DELETE(_iStatus);

}