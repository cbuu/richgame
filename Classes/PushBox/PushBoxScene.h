#include "cocos2d.h"

USING_NS_CC;

class PushBoxScene :public Layer
{
public:
	PushBoxScene();
	~PushBoxScene();

	CREATE_FUNC(PushBoxScene);

	virtual bool init();
	void initKeyboardEvent();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	//void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

private:

};
