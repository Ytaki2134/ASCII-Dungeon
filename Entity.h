#pragma once
#include <tuple>
class Entity
{
private:
	int life;
	int damage;
	int energy;
	bool burn	=	0;
	bool frezze = 0;
	int posx;
	int posy;
	//Map* map;

public: 
	
	virtual int  getLife()		{ return life;	}
	virtual int  getDamage()	{ return damage;}
	virtual int  getEnergy()	{ return energy;}
	virtual bool getBurn()		{ return burn;	}
	virtual bool getFreeze()	{ return frezze;}


	virtual void setLife(int newlife)		{ life = newlife;		}
	virtual void setDammage(int newdamage)	{ damage = newdamage;	}
	virtual void setEnergy(int newenergy)	{ energy = newenergy;	}
	virtual void setburn(bool _burn)		{ burn = _burn;			}
	virtual void setFreeze(bool _frezze)	{ frezze = -_frezze;	}
	virtual std::tuple<int,int> GetPosition()	{ return std::tuple<int,int>(posx, posy);	}
};