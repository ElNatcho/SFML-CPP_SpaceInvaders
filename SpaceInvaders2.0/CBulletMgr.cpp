#include"CBulletMgr.hpp"

CBullet				  *CBulletMgr::_tempBullet = nullptr;
sf::RenderWindow      *CBulletMgr::_pMainWin   = nullptr;
std::vector<CBullet*> *CBulletMgr::_bulletList = new std::vector<CBullet*>();

CBulletMgr::CBulletMgr()
{
	std::cout << ">CBulletMgr: Konstruktor." << std::endl;

	_tempBullet = nullptr;
	_pMainWin   = nullptr;
	_bulletList = new std::vector<CBullet*>();

}

CBulletMgr::CBulletMgr(sf::RenderWindow *pMainWin)
{
	_pMainWin = pMainWin;
}

void CBulletMgr::addBullet(sf::Vector2f initPos, CBullet::TAG tag)
{
	_tempBullet = new CBullet(initPos, sf::Vector2f(4.5F, 4.5F), "assets\\gfx\\BulletTiles.png", tag);
	_bulletList->push_back(_tempBullet);
}

void CBulletMgr::Update(sf::Time &deltaTime)
{
	for (int i = 0; i < _bulletList->size(); i++) {
		if (_bulletList->at(i)->getPosition().y >= _pMainWin->getSize().y ||
			_bulletList->at(i)->getPosition().y <= 0.F ||
			_bulletList->at(i)->getStatus() == false) {
			SAFE_DELETE(_bulletList->at(i));
			_bulletList->erase(_bulletList->begin() + i);
		} else {
			_bulletList->at(i)->Update(deltaTime);
		}
	}
}

void CBulletMgr::Render()
{
	for (int i = 0; i < _bulletList->size(); i++) {
		_pMainWin->draw(*_bulletList->at(i));
	}
}

std::vector<CBullet*> *CBulletMgr::getBulletList()
{
	return _bulletList;
}

CBulletMgr::~CBulletMgr()
{
	std::cout << ">CBulletMgr: Destruktor." << std::endl;

	for (int i = 0; i < _bulletList->size(); i++) {
		SAFE_DELETE(_bulletList->at(i));
	}
	_bulletList->clear();
	//SAFE_DELETE(_bulletList);

}