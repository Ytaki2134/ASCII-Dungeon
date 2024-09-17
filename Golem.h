#pragma once
#include "Mobs.h"

class Golem : public Mobs
{
private:

	



public :

	void Move()		override;
	void Chase()	override;
	void Attack()	override;
	void Death()	override;


};

