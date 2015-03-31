#include "cocos2d.h"

USING_NS_CC;

class GameSelectScene:public Layer
{
public:
	GameSelectScene();
	~GameSelectScene();

	CREATE_FUNC(GameSelectScene);

	virtual bool init();

	void initView();
	void addMenuItems(const char* name, Layer* layer);
	void addMenuItems(const char* name, const ccMenuCallback &callback);
private:
	Size visibleSize;

	static int items_count;

private:
	Menu* gameSelectMenu;
};

