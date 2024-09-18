#pragma once
#include <tuple>
class Entity
{
protected:
	int Id;
	int life;
	int damage;
	int energy;
	bool burn	= 0;
	bool freeze = 0;
	std::tuple<int,int> position;

public: 
	int GetID() {return Id;};
	void SetId(int newId) { Id = newId; };
	virtual int  getLife() { return life; };
	virtual int  getDamage() { return damage; };
	virtual int  getEnergy() { return energy; };
	virtual bool getBurn() { return burn; };
	virtual bool getFreeze() { return freeze; };


	virtual void setLife(int newlife) { life = newlife; };
	virtual void setDammage(int newdamage) { damage = newdamage; };
	virtual void setEnergy(int newenergy) { energy = newenergy; };
	virtual void setburn(bool _burn) { burn = _burn; };
	virtual void setFreeze(bool _frezze) { freeze = _frezze;};
	virtual std::tuple<int,int> GetPosition() { return position; };
	virtual void SetPosition(std::tuple<int, int> pos) { position = pos; };
};