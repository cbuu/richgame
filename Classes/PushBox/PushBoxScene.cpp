#include "PushBox/PushBoxScene.h"


PushBoxScene::PushBoxScene()
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

	Size visibleSize = Director::getInstance()->getVisibleSize();

	initKeyboardEvent();

	TMXTiledMap* tmx = TMXTiledMap::create("PushBox/map.tmx");
	tmx->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	tmx->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(tmx);

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
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
	{
		//按下按键w的事件实现
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:
	{
		//按下按键s的事件实现
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
	{
		//按下按键a的事件实现
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_D:
	{
		//按下按键d的事件实现
	}
	default:
		break;
	}
}


