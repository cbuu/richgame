#include "cocos2d.h"

USING_NS_CC;

class Demo :public Layer
{
public:
	Demo();
	~Demo();

	CREATE_FUNC(Demo);

	virtual bool init();

public:
	void addTMX();
	
private:

};