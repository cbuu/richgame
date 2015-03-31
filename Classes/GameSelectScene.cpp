#include "GameSelectScene.h"

int GameSelectScene::items_count = 1;
const int ITEM_DIS = -50;


GameSelectScene::GameSelectScene()
{
	gameSelectMenu = NULL;
}

GameSelectScene::~GameSelectScene()
{
}

bool GameSelectScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();

	initView();

	return true;
}

void GameSelectScene::initView(){

	gameSelectMenu = Menu::create();

	gameSelectMenu->setPosition(visibleSize.width/2, visibleSize.height);

	gameSelectMenu->setAnchorPoint(Vec2(0.5,1.0));

	this->addChild(gameSelectMenu);
}

void GameSelectScene::addMenuItems(const char* name, const ccMenuCallback &callback)
{
	auto labelTTF = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 30);
	auto label = MenuItemLabel::create(labelTTF, callback);
	label->setPosition(0, ITEM_DIS * items_count++);
	gameSelectMenu->addChild(label);
}
