#include"CEndState.hpp"

CEndState::CEndState(CGameStateMgr &gameStateMgr, int score)
{
	std::cout << ">>CEndState: Konstruktor." << std::endl;

	_sfEvent = new sf::Event();
	_iScore = new int;
	_font = new sf::Font;
	_tScore = new sf::Text();
	_tBackToMenuState = new sf::Text();
	_tBackToPlayState = new sf::Text();
	_bBTMenuSelected = new bool;
	_bBTPlaySelected = new bool;

	*_iScore = score;
	*_bBTMenuSelected = true;
	*_bBTPlaySelected = true;

	_font->loadFromFile("assets\\fnt\\blurb.ttf");

	_tScore->setFont(*_font);
	_tScore->setCharacterSize(50.F);
	_tScore->setString("YOUR SCORE: " + std::to_string(*_iScore));
	_tScore->setColor(sf::Color::White);
	_tScore->setPosition(100.F, 100.F);

	_tBackToMenuState->setFont(*_font);
	_tBackToMenuState->setCharacterSize(35.F);
	_tBackToMenuState->setString("BACK TO MENU");
	_tBackToMenuState->setColor(sf::Color::White);
	_tBackToMenuState->setPosition(125.F, 200.F);
	
	_tBackToPlayState->setFont(*_font);
	_tBackToPlayState->setCharacterSize(35.F);
	_tBackToPlayState->setString("BACK TO GAME");
	_tBackToPlayState->setColor(sf::Color::White);
	_tBackToPlayState->setPosition(125.F, 240.F);

}

void CEndState::HandleEvents(CGameStateMgr &gameStateMgr)
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
				if (*_bBTMenuSelected) {
					gameStateMgr.changeState(CGameStateMgr::GAME_STATE::MENU_STATE);
					break;
				} else if (*_bBTPlaySelected) {
					gameStateMgr.changeState(CGameStateMgr::GAME_STATE::PLAY_STATE);
					break;
				}
			}
		}
	}
}

void CEndState::Update(CGameStateMgr &gameStateMgr)
{
	if (_tBackToMenuState->getGlobalBounds().contains(
		sf::Mouse::getPosition(*gameStateMgr.window).x,
		sf::Mouse::getPosition(*gameStateMgr.window).y)){
		*_bBTMenuSelected = true;
		_tBackToMenuState->setColor(sf::Color::Green);
	} else {
		*_bBTMenuSelected = false;
		_tBackToMenuState->setColor(sf::Color::White);
	}

	if (_tBackToPlayState->getGlobalBounds().contains(
		sf::Mouse::getPosition(*gameStateMgr.window).x,
		sf::Mouse::getPosition(*gameStateMgr.window).y)) {
		*_bBTPlaySelected = true;
		_tBackToPlayState->setColor(sf::Color::Red);
	} else {
		*_bBTPlaySelected = false;
		_tBackToPlayState->setColor(sf::Color::White);
	}
}

void CEndState::Render(CGameStateMgr &gameStateMgr)
{
	gameStateMgr.window->draw(*_tScore);
	gameStateMgr.window->draw(*_tBackToMenuState);
	gameStateMgr.window->draw(*_tBackToPlayState);
}

CEndState::~CEndState()
{
	std::cout << ">>CEndState: Destruktor." << std::endl;

	SAFE_DELETE(_font);
	SAFE_DELETE(_iScore);
	SAFE_DELETE(_tScore);
	SAFE_DELETE(_sfEvent);
	SAFE_DELETE(_bBTMenuSelected);
	SAFE_DELETE(_bBTPlaySelected);
	SAFE_DELETE(_tBackToMenuState);
	SAFE_DELETE(_tBackToPlayState);
}