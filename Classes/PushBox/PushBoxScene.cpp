#include "PushBox/PushBoxScene.h"

const float SIZE_BLOCK = 64.0;
const int SIZE_MAP_WIDTH = 10;
const int SIZE_MAP_HEIGHT = 10;

const int TAG_WALL = 100;

PushBoxScene::PushBoxScene() :movingBox(NULL)
{

}

PushBoxScene::~PushBoxScene()
{

}

bool PushBoxScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();

	

	TMXTiledMap* tmx = TMXTiledMap::create("PushBox/map.tmx");
	tmx->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	tmx->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(tmx,0);


	player = Sprite::create("PushBox/player.png");
	player->setAnchorPoint(Vec2(0, 0));
	moveTo(player, 1, 8);
	this->addChild(player,10);


	parseTMX(tmx);

	initKeyboardEvent();

	scheduleUpdate();

	return true;
}



void PushBoxScene::initKeyboardEvent(){
	//获取事件分发器
	auto dispatcher = Director::getInstance()->getEventDispatcher();

	//创建键盘按键事件监听器
	auto listener = EventListenerKeyboard::create();

	//绑定事件响应函数
	listener->onKeyPressed = CC_CALLBACK_2(PushBoxScene::onKeyPressed, this);

	//添加监听器
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

//事件响应函数
void PushBoxScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	Vec2 pos = getPos(player);
	Vec2 nextPos;
	Vec2 nextBoxPos;
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
	{
		//按下按键w的事件实现
		nextPos = Vec2(pos.x, pos.y + 1);
		if (canGo(nextPos)){
			if (haveBox(nextPos)){
				nextBoxPos = Vec2(nextPos.x, nextPos.y + 1);
				moveBox(nextPos, nextBoxPos);
			}
			else{
				moveTo(player, nextPos.x, nextPos.y);
			}
		}
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:
	{
		//按下按键s的事件实现
		nextPos = Vec2(pos.x, pos.y -1);
		if (canGo(nextPos)){
			if (haveBox(nextPos)){
				nextBoxPos = Vec2(nextPos.x, nextPos.y - 1);
				moveBox(nextPos, nextBoxPos);
			}
			else{
				moveTo(player, nextPos.x, nextPos.y);
			}
		}
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
	{
		//按下按键a的事件实现
		nextPos = Vec2(pos.x-1, pos.y);
		if (canGo(nextPos)){
			if (haveBox(nextPos)){
				nextBoxPos = Vec2(nextPos.x -1 , nextPos.y);
				moveBox(nextPos, nextBoxPos);
			}
			else{
				moveTo(player, nextPos.x, nextPos.y);
			}
		}
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_D:
	{
		//按下按键d的事件实现
		nextPos = Vec2(pos.x+1, pos.y);
		if (canGo(nextPos)){
			if (haveBox(nextPos)){
				nextBoxPos = Vec2(nextPos.x+1, nextPos.y);
				moveBox(nextPos, nextBoxPos);
			}
			else{
				moveTo(player, nextPos.x, nextPos.y);
			}
		}
	}
	default:
		break;
	}
}

void PushBoxScene::parseTMX(TMXTiledMap* map)
{
	TMXObjectGroup* objects = map->getObjectGroup("box");
	ValueVector container = objects->getObjects();

	for (auto obj:container)
	{
		ValueMap values = obj.asValueMap();
		Sprite* box = Sprite::create("PushBox/box.png");
		box->setAnchorPoint(Vec2(0, 0));
		box->setPosition(values.at("x").asInt(), values.at("y").asInt());
		this->addChild(box,2);
		boxes.pushBack(box);
	}

	objects = map->getObjectGroup("goal");
	container = objects->getObjects();

	for (auto obj:container)
	{
		ValueMap values = obj.asValueMap();
		Sprite* goal = Sprite::create("PushBox/goal.png");
		goal->setAnchorPoint(Vec2(0, 0));
		goal->setPosition(values.at("x").asInt(), values.at("y").asInt());
		this->addChild(goal,1);
		goals.pushBack(goal);
	}

	objects = map->getObjectGroup("wall");
	container = objects->getObjects();

	for (auto obj:container)
	{
		ValueMap values = obj.asValueMap();
		Sprite* wall = Sprite::create("PushBox/wall.png");
		wall->setAnchorPoint(Vec2(0, 0));
		wall->setPosition(values.at("x").asInt(), values.at("y").asInt());
		wall->setTag(TAG_WALL);
		this->addChild(wall, 1);
		walls.pushBack(wall);
	}
}

void PushBoxScene::moveTo(Sprite* sprite, int x, int y)
{
	if (sprite){
			sprite->setPosition(SIZE_BLOCK*x, SIZE_BLOCK*y);
	}
}

cocos2d::Vec2 PushBoxScene::getPos(Sprite* sprite)
{
	if (sprite)
	{
		return Vec2(sprite->getPositionX() / SIZE_BLOCK, sprite->getPositionY() / SIZE_BLOCK);
	}

	return Vec2(0,0);
}


bool PushBoxScene::isEnd()
{

	int count = 0;

	for (auto b:boxes)
	{
		Vec2 bp = getPos(b);
		for (auto g:goals)
		{

			Vec2 gp = getPos(g);
			if (bp.x == gp.x&&bp.y == gp.y)
			{
				count++;
			}
		}
	}
	
	return count == goals.size();
}



bool PushBoxScene::canGo(Vec2 pos)
{
	for (auto obj:walls)
	{
		Vec2 wp = getPos(obj);
		
		if (wp == pos)
		{
			return false;
		}
	}
	return true;
}

bool PushBoxScene::haveBox(Vec2 pos)
{
	for (auto sp : boxes){
		Vec2 p = getPos(sp);
		//log("%d %d", p.x, p.y);
		if (p.x == pos.x&&p.y == pos.y)
		{
			movingBox = sp;
			return true;
		}
	}
	return false;
}

bool PushBoxScene::judge(Vec2 nextPos)
{
	if (canGo(nextPos)){
		if (haveBox(nextPos)){
			return true;
		}
	}
	return false;
}

void PushBoxScene::moveBox(Vec2 nextPos, Vec2 nextBoxPos)
{
	if (!movingBox)
	{
		return;
	}
	if (canGo(nextBoxPos)&&!haveBox(nextBoxPos))
	{
		moveTo(player, nextPos.x, nextPos.y);
		moveTo(movingBox, nextBoxPos.x, nextBoxPos.y);
		if (isEnd())
		{
			showWin();
		}
	}
}

void PushBoxScene::showWin()
{
	Label* winLabel = Label::createWithTTF("YOU WIN!", "fonts/arial.ttf", 100);
	winLabel->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(winLabel, 11);
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();


	//winLabel->setEventDispatcher()
}




