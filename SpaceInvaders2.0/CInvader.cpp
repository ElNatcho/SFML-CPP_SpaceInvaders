#include"CInvader.hpp"

CInvader::CInvader()
{
	std::cout << ">CInvader: Konstruktor." << std::endl;

	_moveVector    = new sf::Vector2f();
	_pInvaderTex   = new sf::Texture ();
	_textureRegion = new sf::IntRect();
	_typ		   = new     TYP     ();
	_iCurrentFrame = new int;
	_isActive	   = new bool;

	*_iCurrentFrame = 0;
	*_isActive      = true;
}

CInvader::CInvader(sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath, TYP typ) : CInvader()
{
	if (!_pInvaderTex->loadFromFile(imagePath))
		std::cout << ">CPlayer: _pPlayerTex konnte nicht geladen werden (" << imagePath << ")!" << std::endl;

	*_typ = typ;

	_textureRegion->width  = 11;
	_textureRegion->height = 8;
	_textureRegion->top    = 0;
	_textureRegion->left   = 0;

	switch (*_typ) {
	case CInvader::TYP::GRUND:
		_textureRegion->left = 22;
		break;
	case CInvader::TYP::INVADER:
		break;
	case::CInvader::TYP::DESTROYER:
		_textureRegion->left  = 44;
		_textureRegion->width = 8;
		break;
	case CInvader::TYP::BOSS:
		break;
	}

	this->setTexture(*_pInvaderTex);
	this->setTextureRect(*_textureRegion);
	this->setPosition(initPos);
	this->setScale(initScale);

}

void CInvader::Update(sf::Time &deltaTime, sf::Vector2f &moveVector)
{
	*_moveVector   = moveVector;
	this->move(*_moveVector);

	if (*_iCurrentFrame >= 1) {
		_textureRegion->left -= TILE_WIDTH;
		*_iCurrentFrame = 0;
	} else {
		_textureRegion->left += TILE_WIDTH;
		*_iCurrentFrame = *_iCurrentFrame + 1;
	}

	this->setTextureRect(*_textureRegion);

}

void CInvader::setStatus(bool value)
{
	*_isActive = value;
}

bool CInvader::getStatus()
{
	return *_isActive;
}

CInvader::TYP CInvader::getTyp()
{
	return *_typ;
}

CInvader::~CInvader()
{
	std::cout << ">CInvader: Destruktor." << std::endl;

	SAFE_DELETE(_iCurrentFrame);
	SAFE_DELETE(_pInvaderTex);
	SAFE_DELETE(_moveVector);
}