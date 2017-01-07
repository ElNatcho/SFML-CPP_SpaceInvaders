#include"CGameStateMgr.hpp"

CGameStateMgr::CGameStateMgr()
{
	std::cout << ">>>CGameStateMgr: Konstruktor." << std::endl;
	
	window     = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Space_Invaders");
	running	   = new bool;
	deltaTime  = new sf::Time();
	score      = new int;
	_timeMgr   = new CTimeMgr();
	_tFrames   = new sf::Text(); 
	_frameTime = new sf::Time();
	_font      = new sf::Font();
	_iCurrentFrames = new int;

	*running = true;
	*score   = 0;

	_font->loadFromFile("assets\\fnt\\blurb.ttf");

	_tFrames->setFont(*_font);
	_tFrames->setCharacterSize(30.F);
	_tFrames->setString("FPS: 0");
	_tFrames->setPosition(10.F, 5.F);
	_tFrames->setColor(sf::Color::Yellow);


}

void CGameStateMgr::Run()
{
	while (window->isOpen())
	{
		//Handle Window Events
		_currentState->HandleEvents(*this);

		window->clear();

		_timeMgr->getElapsedTime(deltaTime);

		//Calc FPS
		*_iCurrentFrames += 1;
		*_frameTime += *deltaTime;
		if (_frameTime->asSeconds() >= 1.F) {
			_tFrames->setString("FPS: " + std::to_string(*_iCurrentFrames));
			*_iCurrentFrames = 0;
			*_frameTime = _frameTime->Zero;
		}
#if _DEBUG
		window->draw(*_tFrames);
#endif

		//Update and Render the states
		_currentState->Update(*this);
		_currentState->Render(*this);

		window->display();
	}

}

bool CGameStateMgr::isRunning()
{
	return *running;
}

void CGameStateMgr::changeState(GAME_STATE newState)
{
	switch (newState)
	{
	case GAME_STATE::MENU_STATE:
		_currentState = std::move(std::unique_ptr<CMainMenuState>(new CMainMenuState(*this)));
		break;

	case GAME_STATE::PLAY_STATE:
		_currentState = std::move(std::unique_ptr<CPlayState>(new CPlayState(*this)));
		break;

	case GAME_STATE::END_STATE:
		_currentState = std::move(std::unique_ptr<CEndState>(new CEndState(*this, *this->score)));
		break;
	}
}

CGameStateMgr::~CGameStateMgr()
{
	std::cout << ">>>CGameStateMgr: Destruktor." << std::endl;

	SAFE_DELETE(score);
	SAFE_DELETE(window);
	SAFE_DELETE(deltaTime);
	SAFE_DELETE(running);
	SAFE_DELETE(_timeMgr);
	SAFE_DELETE(_tFrames);
	SAFE_DELETE(_font);
	SAFE_DELETE(_frameTime);
	SAFE_DELETE(_iCurrentFrames);

}