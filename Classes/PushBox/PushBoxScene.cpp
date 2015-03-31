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
	//��ȡ�¼��ַ���
	auto dispatcher = Director::getInstance()->getEventDispatcher();

	//�������̰����¼�������
	auto listener = EventListenerKeyboard::create();

	//���¼���Ӧ����
	listener->onKeyPressed = CC_CALLBACK_2(PushBoxScene::onKeyPressed, this);

	//��Ӽ�����
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

//�¼���Ӧ����
void PushBoxScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
	{
		//���°���w���¼�ʵ��
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:
	{
		//���°���s���¼�ʵ��
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
	{
		//���°���a���¼�ʵ��
	}
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_D:
	{
		//���°���d���¼�ʵ��
	}
	default:
		break;
	}
}


