#include"CMainMenuState.hpp"

CMainMenuState::CMainMenuState(CGameStateMgr &gameStateMgr)
{
	std::cout << ">>CMainMenuState: Konstruktor." << std::endl;

	_font = new sf::Font();

	_sfEvent	= new sf::Event();
	_tTitle     = new sf::Text();
	_tStartGame = new sf::Text();
	_tEndGame   = new sf::Text();
	_tVersion   = new sf::Text();
	_tMaker		= new sf::Text();
	_bStartSelected = new bool;
	_bEndSelected   = new bool;

	*_bStartSelected = false;
	*_bEndSelected   = false;

	_font->loadFromFile("assets\\fnt\\blurb.ttf");

	_tTitle->setFont(*_font);
	_tTitle->setCharacterSize(60.F);
	_tTitle->setString("SPACE INVADERS");
	_tTitle->setColor(sf::Color::White);
	_tTitle->setPosition(sf::Vector2f(100.F, 100.F));

	_tVersion->setFont(*_font);
	_tVersion->setCharacterSize(30.F);
	_tVersion->setString("v0.1");
	_tVersion->setColor(sf::Color::White);
	_tVersion->setPosition(sf::Vector2f(150.F, gameStateMgr.window->getSize().y - 50.F));
	
	_tEndGame->setFont(*_font);
	_tEndGame->setCharacterSize(40.F);
	_tEndGame->setString("QUIT GAME");
	_tEndGame->setColor(sf::Color::White);
	_tEndGame->setPosition(sf::Vector2f(150.F, 270.F));

	_tStartGame->setFont(*_font);
	_tStartGame->setCharacterSize(40.F);
	_tStartGame->setString("START GAME");
	_tStartGame->setColor(sf::Color::White);
	_tStartGame->setPosition(sf::Vector2f(150.F, 220.F));

	_tMaker->setFont(*_font);
	_tMaker->setCharacterSize(20.F);
	_tMaker->setString("BY NATCHO");
	_tMaker->setColor(sf::Color::White);
	_tMaker->setPosition(100.F, 165.F);

}

void CMainMenuState::HandleEvents(CGameStateMgr &gameStateMgr)
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
		if (_sfEvent->type == sf::Event::MouseButtonReleased) {
			if (_sfEvent->mouseButton.button == sf::Mouse::Button::Left) {
				if (*_bStartSelected) {
					gameStateMgr.changeState(CGameStateMgr::GAME_STATE::PLAY_STATE);
					break;
				}
				if (*_bEndSelected) {
					*gameStateMgr.running = false;
					gameStateMgr.window->close();
					break;
				}
			}
		}
	}
}

void CMainMenuState::Update(CGameStateMgr &gameStateMgr)
{
	if (_tStartGame->getGlobalBounds().contains(
		sf::Mouse::getPosition(*gameStateMgr.window).x,
		sf::Mouse::getPosition(*gameStateMgr.window).y)) {
		_tStartGame->setColor(sf::Color::Green);
		*_bStartSelected = true;
	} else {
		_tStartGame->setColor(sf::Color::White);
		*_bStartSelected = false;
	}

	if (_tEndGame->getGlobalBounds().contains(
		sf::Mouse::getPosition(*gameStateMgr.window).x,
		sf::Mouse::getPosition(*gameStateMgr.window).y)) {
		_tEndGame->setColor(sf::Color::Red);
		*_bEndSelected = true;
	} else {
		_tEndGame->setColor(sf::Color::White);
		*_bEndSelected = false;
	}
}

void CMainMenuState::Render(CGameStateMgr &gameStateMgr)
{
	gameStateMgr.window->draw(*_tTitle);
	gameStateMgr.window->draw(*_tVersion);
	gameStateMgr.window->draw(*_tEndGame);
	gameStateMgr.window->draw(*_tStartGame);
	gameStateMgr.window->draw(*_tMaker);
}

CMainMenuState::~CMainMenuState()
{
	std::cout << ">>CMainMenuState: Destruktor." << std::endl;

	SAFE_DELETE(_font);
	SAFE_DELETE(_tTitle);
	SAFE_DELETE(_tMaker);
	SAFE_DELETE(_sfEvent);
	SAFE_DELETE(_tEndGame);
	SAFE_DELETE(_tVersion);
	SAFE_DELETE(_tStartGame);

}