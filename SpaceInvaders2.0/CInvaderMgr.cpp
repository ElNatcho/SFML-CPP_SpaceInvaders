#include"CInvaderMgr.hpp"

CInvaderMgr::CInvaderMgr()
{
	std::cout << ">CInvaderMgr: Konstruktor." << std::endl;

	_invUpdateDelay  = new sf::Time;
	_invLeftUpPos    = new sf::Vector2f();
	_invInitScale    = new sf::Vector2f();
	_invMoveVector   = new sf::Vector2f();
	_tempInvader     = nullptr;
	_tempInvaderList = nullptr;
	_invaderMatrix   = new std::vector<std::vector<CInvader*>*>();
	_flipDirection   = new bool;
	_pMainWin = nullptr;
	_randX	  = new int;
	_randY    = new int;

	*_flipDirection = false;

	_invMoveVector->x = 50.F;
	_invMoveVector->y = 0.F;

}

CInvaderMgr::CInvaderMgr(sf::Vector2f &leftUpperPos, sf::Vector2f &initScale, sf::RenderWindow *pMainWin) : CInvaderMgr()
{
	*_invLeftUpPos = leftUpperPos;
	*_invInitScale = initScale;

	_pMainWin = pMainWin;

	this->_setup();
}

void CInvaderMgr::Init(sf::Vector2f &leftUpperPos, sf::Vector2f &initScale, sf::RenderWindow *pMainWin)
{
	*_invLeftUpPos = leftUpperPos;
	*_invInitScale = initScale;

	_pMainWin = pMainWin;

	this->_setup();
}

bool CInvaderMgr::Update(sf::Time &deltaTime)
{
	*_invUpdateDelay += deltaTime;

	if (_invaderMatrix->size() > 0) {
		for (int y = 0; y < _invaderMatrix->size(); y++) {
			for (int x = 0; x < _invaderMatrix->at(y)->size(); x++) {
				if (_invaderMatrix->at(y)->at(x)->getStatus() == false) {
					SAFE_DELETE(_invaderMatrix->at(y)->at(x));
					_invaderMatrix->at(y)->erase(_invaderMatrix->at(y)->begin() + x);
				}
			}
			if (_invaderMatrix->at(y)->size() <= 0)
				_invaderMatrix->erase(_invaderMatrix->begin() + y);
		}

		if (_invUpdateDelay->asSeconds() >= 1.5F) {
			if (*_flipDirection) {
				_invMoveVector->x = -_invMoveVector->x;
				*_flipDirection = false;
			}

			for (int y = 0; y < _invaderMatrix->size(); y++) {
				for (int x = 0; x < _invaderMatrix->at(y)->size(); x++) {
					_invaderMatrix->at(y)->at(x)->Update(deltaTime, *_invMoveVector);


					if (_invaderMatrix->at(y)->at(x)->getPosition().x >= _pMainWin->getSize().x - 150.F ||
						_invaderMatrix->at(y)->at(x)->getPosition().x <= 100.F) {
						*_flipDirection = true;
					}
				}
			}

			*_randY = rand() % _invaderMatrix->size();
			*_randX = rand() % _invaderMatrix->at(*_randY)->size();
			CBulletMgr::addBullet(_invaderMatrix->at(*_randY)->at(*_randX)->getPosition(), CBullet::TAG::INVADER);		

			*_invUpdateDelay = _invUpdateDelay->Zero;
		}

		return true;
	} else {
		return false;
	}

}

void CInvaderMgr::Render()
{
	for (int y = 0; y < _invaderMatrix->size(); y++) {
		for (int x = 0; x < _invaderMatrix->at(y)->size(); x++) {
			_pMainWin->draw(*_invaderMatrix->at(y)->at(x));
		}
	}
}

std::vector<std::vector<CInvader*>*> *CInvaderMgr::getInvaderMatrix()
{
	return _invaderMatrix;
}

void CInvaderMgr::_setup()
{
	CInvader::TYP _tempTyp;

	for (int y = 0; y < 5; y++) {
		_tempInvaderList = new std::vector<CInvader*>();
		for (int x = 0; x < 10; x++) {
			if (y == 0) {
				_tempTyp = CInvader::TYP::DESTROYER;
			} else if (y >= 1 && y <= 2) {
				_tempTyp = CInvader::TYP::INVADER;
			} else if (y >= 3) {
				_tempTyp = CInvader::TYP::GRUND;
			}
			_tempInvader = new CInvader(sf::Vector2f((11 * _invInitScale->x + 10.F)*x + _invLeftUpPos->x, 
													  (8 * _invInitScale->y + 10.F)*y + _invLeftUpPos->y), 
													  *_invInitScale, "assets\\gfx\\InvaderTiles.png", 
													 _tempTyp);
			_tempInvaderList->push_back(_tempInvader);
		}
		_invaderMatrix->push_back(_tempInvaderList);
	}
}

CInvaderMgr::~CInvaderMgr()
{
	std::cout << ">CInvaderMgr: Destruktor." << std::endl;
	 
	SAFE_DELETE(_randX);
	SAFE_DELETE(_randY);
	SAFE_DELETE(_flipDirection);
	SAFE_DELETE(_invUpdateDelay);
	SAFE_DELETE(_invLeftUpPos);
	SAFE_DELETE(_invInitScale);
	//SAFE_DELETE(_tempInvaderList);
	for (int y = 0; y < _invaderMatrix->size(); y++) {
		for (int x = 0; x < _invaderMatrix->at(y)->size(); x++) {
			SAFE_DELETE(_invaderMatrix->at(y)->at(x));
			_invaderMatrix->at(y)->erase(_invaderMatrix->at(y)->begin() + x);
		}
	}
	for (int y = 0; y < _invaderMatrix->size(); y++) {
		if (_invaderMatrix->at(y)->size() != 0) {
			SAFE_DELETE(_invaderMatrix->at(y));
		}
	}
	SAFE_DELETE(_invaderMatrix);


}