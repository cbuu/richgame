#include "cocos2d.h"

USING_NS_CC;

class PushBoxScene :public Layer
{
public:
	PushBoxScene();
	~PushBoxScene();

	CREATE_FUNC(PushBoxScene);

	virtual bool init();
	//void update(float delta);

	void initKeyboardEvent();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	//void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	void parseTMX(TMXTiledMap* map);

public:

	bool judge(Vec2 nextPos);

	void moveTo(Sprite* sprite,int x,int y);
	Vec2 getPos(Sprite* sprite);
	bool haveBox(Vec2 pos);
	void moveBox(Vec2 nextPos,Vec2 nextBoxPos);
	bool canGo(Vec2 pos);
	bool isEnd();
	void showWin();

private:
	Sprite* player;
	Sprite* movingBox;
	Vector<Sprite*> boxes;
	Vector<Sprite*> goals;
	Vector<Sprite*> walls;
private:
	Size visibleSize;
};
