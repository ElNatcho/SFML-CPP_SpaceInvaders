#include"CPlayState.hpp"

CPlayState::CPlayState(CGameStateMgr &gameStateMgr)
{
	std::cout << ">>CPlayState: Konstruktor." << std::endl;

	_sfEvent = new sf::Event  ();
	_pPlayer = new CPlayer    (sf::Vector2f(100.F, 650.F), sf::Vector2f(4.5F, 4.5F), "assets\\gfx\\PlayerTiles.png");
	_pBulletMgr  = new CBulletMgr(gameStateMgr.window);
	_pInvaderMgr = new CInvaderMgr(sf::Vector2f(75.F , 100.F), sf::Vector2f(4.5F, 4.5F), gameStateMgr.window);
	_pBarricadeMgr = new CBarricadeMgr(gameStateMgr.window);
	_pCollisionMgr = new CCollisionMgr(_pInvaderMgr->getInvaderMatrix(),
									   _pBulletMgr->getBulletList(),
									   _pPlayer,
									   _pBarricadeMgr->getBarricadeList());
	_font   = new sf::Font();
	_iScore = new int;
	_tScore = new sf::Text();

	_font->loadFromFile("assets\\fnt\\blurb.ttf");

	_tScore->setFont(*_font);
	_tScore->setCharacterSize(35.F);
	_tScore->setString("0");
	_tScore->setColor(sf::Color::Red);
	_tScore->setPosition(sf::Vector2f(gameStateMgr.window->getSize().x * 3/5, 0.F));

	*_iScore = 0;
}

void CPlayState::HandleEvents(CGameStateMgr &gameStateMgr)
{
	while (gameStateMgr.window->pollEvent(*_sfEvent)) {
		if (_sfEvent->type == sf::Event::Closed) {
			*gameStateMgr.running = false;
			 gameStateMgr.window->close();
		}
		if (_sfEvent->type == sf::Event::KeyPressed) {
			if (_sfEvent->key.code == sf::Keyboard::Escape) {
				*gameStateMgr.running = false;
				 gameStateMgr.window->close();
			}
		}
	}
}

void CPlayState::Update(CGameStateMgr &gameStateMgr)
{
	*_iScore += _pCollisionMgr->checkForCollision();
	_tScore->setString("SCORE: " + std::to_string(*_iScore));

	_pBulletMgr->Update(*gameStateMgr.deltaTime);
	_pBarricadeMgr->Update();

	if (!_pPlayer->Update(*gameStateMgr.deltaTime, sf::Vector2f(200.F, 0.F)) || !_pInvaderMgr->Update(*gameStateMgr.deltaTime)) {
		*gameStateMgr.score = *_iScore;
		gameStateMgr.changeState(CGameStateMgr::GAME_STATE::END_STATE);
	}
}

void CPlayState::Render(CGameStateMgr &gameStateMgr)
{
	_pBarricadeMgr->Render();
	_pInvaderMgr->Render();
	_pBulletMgr->Render();
	_pPlayer->Render(gameStateMgr.window);
	gameStateMgr.window->draw(*_tScore);
}

CPlayState::~CPlayState()
{
	std::cout << ">>CPlayState: Destruktor." << std::endl;
	SAFE_DELETE(_sfEvent);
	SAFE_DELETE(_pPlayer);
	SAFE_DELETE(_pBulletMgr);
	SAFE_DELETE(_pInvaderMgr);
	SAFE_DELETE(_pCollisionMgr);
	SAFE_DELETE(_pBarricadeMgr);
}