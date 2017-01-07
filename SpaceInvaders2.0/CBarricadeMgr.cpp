#include"CBarricadeMgr.hpp"

CBarricadeMgr::CBarricadeMgr()
{
	std::cout << ">CBarricadeMgr: Konstruktor." << std::endl;

	_pMainWin      = nullptr;
	_tempBarricade = nullptr;
	_barricadeList = new std::vector<CBarricade*>();

}

CBarricadeMgr::CBarricadeMgr(sf::RenderWindow *pWin) : CBarricadeMgr()
{
	_pMainWin = pWin;
	_setup();
}

void CBarricadeMgr::Update()
{
	for (int i = 0; i < _barricadeList->size(); i++) {
		if (_barricadeList->at(i)->getStatus() >= 3) {
			SAFE_DELETE(_barricadeList->at(i));
			_barricadeList->erase(_barricadeList->begin() + i);
		}
	}
}

void CBarricadeMgr::Render()
{
	for (int i = 0; i < _barricadeList->size(); i++)
		_pMainWin->draw(*_barricadeList->at(i));
}

std::vector<CBarricade*> *CBarricadeMgr::getBarricadeList()
{
	return _barricadeList;
}

void CBarricadeMgr::_setup()
{
	float *_offset = new float;
	*_offset = _pMainWin->getSize().x * (1.F / 5.F);

	for (int i = 1; i <= 4; i++) {
		for (int x = 0; x < 8; x++) {
			if (x <= 3) {
				_tempBarricade = new CBarricade(sf::Vector2f( x      * (11.F * 2.25F) + (*_offset * i), _pMainWin->getSize().y - 200.F               ), sf::Vector2f(2.25F, 2.25F), "assets\\gfx\\Barricades.png");
			} else {
				_tempBarricade = new CBarricade(sf::Vector2f((x - 4) * (11.F * 2.25F) + (*_offset * i), _pMainWin->getSize().y - 200.F + 2.25F * 11.F), sf::Vector2f(2.25F, 2.25F), "assets\\gfx\\Barricades.png");
			}
			_barricadeList->push_back(_tempBarricade);
		}
	}

	SAFE_DELETE(_offset);
}

CBarricadeMgr::~CBarricadeMgr()
{
	std::cout << ">CBarricadeMgr: Destruktor." << std::endl;

	for (int i = 0; i < _barricadeList->size(); i++)
		SAFE_DELETE(_barricadeList->at(i));
	_barricadeList->clear();
	SAFE_DELETE(_barricadeList);

}