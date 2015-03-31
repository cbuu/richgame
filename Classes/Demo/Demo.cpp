#include "Demo/Demo.h"


Demo::Demo()
{

}

Demo::~Demo()
{

}

bool Demo::init()
{
	if (!Layer::init())
	{
		return false;
	}


	return true;
}