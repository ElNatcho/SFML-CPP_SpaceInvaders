#include"CCollisionMgr.hpp"

CCollisionMgr::CCollisionMgr()
{
	std::cout << ">CCollisionMgr: Konstruktor." << std::endl;

	_pPlayer	    = nullptr;
	_pBulletList    = nullptr;
	_pInvaderList   = nullptr;
	_pBarricadeList = nullptr;
	_iPoints        = new int;

	*_iPoints = 0;
}

CCollisionMgr::CCollisionMgr(std::vector<std::vector<CInvader*>*> *pInvaderList, std::vector<CBullet*> *pBulletList,
					         CPlayer *pPlayer, std::vector<CBarricade*> *pBarricadeList) : CCollisionMgr()
{
	_pPlayer	    = pPlayer;
	_pBulletList    = pBulletList;
	_pInvaderList   = pInvaderList;
	_pBarricadeList = pBarricadeList;
}

int CCollisionMgr::checkForCollision()
{
	*_iPoints = 0;

	for (int i = 0; i < _pBulletList->size(); i++) {
		for (int y = 0; y < _pInvaderList->size(); y++) {
			for (int x = 0; x < _pInvaderList->at(y)->size(); x++) {
				if (_pBulletList->at(i)->getTag() == CBullet::TAG::PLAYER && 
					_pInvaderList->at(y)->at(x)->getGlobalBounds().intersects(_pBulletList->at(i)->getGlobalBounds())) {
					switch (_pInvaderList->at(y)->at(x)->getTyp()) {
					case CInvader::TYP::INVADER:
						*_iPoints += 50.F;
						break;

					case CInvader::TYP::GRUND:
						*_iPoints += 25.F;
						break;

					case CInvader::TYP::DESTROYER:
						*_iPoints += 75.F;
						break;
					}
					_pInvaderList->at(y)->at(x)->setStatus(false);
					_pBulletList->at(i)->setStatus(false);
				}
			}
		}

		if (_pBulletList->at(i)->getGlobalBounds().intersects(_pPlayer->getGlobalBounds()) &&
			_pBulletList->at(i)->getTag() == CBullet::TAG::INVADER) {
			_pBulletList->at(i)->setStatus(false);
			_pPlayer->subHealth(1);
			std::cout << ">CCollisionMgr: Player hit by Bullet." << std::endl;
		}

		for (int x = 0; x < _pBarricadeList->size(); x++) {
			if (_pBulletList->at(i)->getGlobalBounds().intersects(_pBarricadeList->at(x)->getGlobalBounds())) {
				_pBulletList->at(i)->setStatus(false);
				_pBarricadeList->at(x)->subStatus(1);
			}
		}

	}

	return *_iPoints;
}

CCollisionMgr::~CCollisionMgr()
{
	std::cout << ">CCollisionMgr: Destruktor." << std::endl;

}