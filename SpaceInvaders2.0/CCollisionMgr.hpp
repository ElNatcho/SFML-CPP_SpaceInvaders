#ifndef CCOLLISIONMGR_HPP
#define CCOLLISIONMGR_HPP

#include"CInvaderMgr.hpp"
#include"CBulletMgr.hpp"
#include"CBarricade.hpp"
#include"CPlayer.hpp"

class CCollisionMgr {
public:
	CCollisionMgr();
	CCollisionMgr(std::vector<std::vector<CInvader*>*> *pInvaderList, std::vector<CBullet*> *pBulletList,
				  CPlayer *pPlayer, std::vector<CBarricade*> *pBarricadeList);
	~CCollisionMgr();

	int checkForCollision();

private:
	CPlayer *_pPlayer;
	std::vector<CBullet*>    *_pBulletList;
	std::vector<CBarricade*> *_pBarricadeList;
	std::vector<std::vector<CInvader*>*> *_pInvaderList;

	int *_iPoints;

};

#endif