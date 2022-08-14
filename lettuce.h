#ifndef LETTUCE_H
#define LETTUCE_H
#include "crop.h"

class Lettuce : public Crop
{
	public:
	Lettuce(int,int,int,int,bool,bool,int = 0,int = 0);

	void plantMenu();
	void checkPlant();


	static int nextLettuceID;

	private:
	int lettuceID = 0;

};


#endif