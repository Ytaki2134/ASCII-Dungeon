#pragma once
#include "Vector2.h"
#include <string>

class Entity
{
protected:
	int Id;
	std::string name;
	int life;
	int maxLife;
	int damage;
	int energy;
	bool burn = false;
	bool freeze = false;
	Vector2 position;
	char lastTile;
	char token;

public: 
	int GetID() { return Id; };
	virtual std::string GetName() { return name; };
	virtual int GetLife() { return life; };
	virtual int GetMaxLife() { return maxLife; };
	virtual int GetDamage() { return damage; };
	virtual int GetEnergy() { return energy; };
	virtual bool GetBurn() { return burn; };
	virtual bool GetFreeze() { return freeze; };
	virtual char GetToken() { return token; };

	void SetId(int newId) { Id = newId; };
	virtual void SetName(std::string newName) { name = newName; };
	virtual void SetLife(int newlife) { life = newlife; };
	virtual void SetMaxLife(int newMaxLife) { maxLife = newMaxLife; };
	virtual void SetDamage(int newdamage) { damage = newdamage; };
	virtual void SetEnergy(int newenergy) { energy = newenergy; };
	virtual void Setburn(bool _burn) { burn = _burn; };
	virtual void SetFreeze(bool _freeze) { freeze = _freeze;};
	virtual Vector2 GetPosition() { return position; };
	virtual void SetPosition(Vector2 pos) { position = pos; };
	virtual void SetPosition(int x, int y) { Vector2 vector(x,y); position = vector; };
	virtual void SetLastTile(char tile) { lastTile = tile; } ;
	virtual void SetToken(char newToken) { token = newToken; }
};