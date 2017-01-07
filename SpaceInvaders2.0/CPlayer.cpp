#include"CPlayer.hpp"

CPlayer::CPlayer()
{
	std::cout << ">CPlayer: Konstruktor." << std::endl;
	_pPlayerTex = new sf::Texture ();
	_moveVector = new sf::Vector2f();
	_healthBar  = new sf::RectangleShape();
	_bulletShootDelay = new sf::Time();
	_currentHealth    = new int;

	*_currentHealth = LIVES;

	_healthBar->setSize(sf::Vector2f(*_currentHealth * -HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT));
	//_healthBar->setPosition(sf::Vector2f(200.F, 10.F));
	_healthBar->setFillColor(sf::Color::Red);
}

CPlayer::CPlayer(sf::Vector2f &initPos, sf::Vector2f &initScale, std::string imagePath) : CPlayer()
{
	if (!_pPlayerTex->loadFromFile(imagePath))
		std::cout << ">CPlayer: _pPlayerTex konnte nicht geladen werden (" << imagePath << ")!" << std::endl;

	this->setTexture(*_pPlayerTex);
	this->setTextureRect(sf::IntRect(0, 0, 11, 6));	
	this->setPosition(initPos);
	this->setScale(initScale);

}

bool CPlayer::Update(sf::Time &deltaTime, sf::Vector2f &moveVector)
{
	*_bulletShootDelay += deltaTime;

	*_moveVector = moveVector;

	_moveVector->x *= deltaTime.asSeconds();
	_moveVector->y *= deltaTime.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->move(-_moveVector->x, _moveVector->y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->move( _moveVector->x, _moveVector->y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _bulletShootDelay->asSeconds() >= 1.F) {
		CBulletMgr::addBullet(sf::Vector2f(this->getPosition().x + this->getGlobalBounds().width / 2, this->getPosition().y), CBullet::TAG::PLAYER);
		*_bulletShootDelay = _bulletShootDelay->Zero;
	}
	
	if (*_currentHealth <= 0) {
		return false;
	} else {
		_healthBar->setSize(sf::Vector2f(*_currentHealth * -HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT));
		return true;
	}

}

void CPlayer::Render(sf::RenderWindow *pWin)
{
	pWin->draw(*this);
	pWin->draw(*_healthBar);
	_healthBar->setPosition(pWin->getSize().x - 10.F, 10.F);
}

void CPlayer::subHealth(int value)
{
	*_currentHealth -= value;
}

CPlayer::~CPlayer()
{
	std::cout << ">CPlayer: Destruktor." << std::endl;

	SAFE_DELETE(_pPlayerTex);
	SAFE_DELETE(_moveVector);
	SAFE_DELETE(_bulletShootDelay);
	SAFE_DELETE(_healthBar);
	SAFE_DELETE(_currentHealth);

}