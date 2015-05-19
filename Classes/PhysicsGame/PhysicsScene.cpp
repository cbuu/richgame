#include "PhysicsGame/PhysicsScene.h"

PhysicsScene::PhysicsScene()
{

}

PhysicsScene::~PhysicsScene()
{

}

bool PhysicsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	createEdgeBox();

	auto icon = Sprite::create("CloseNormal.png");
	auto body = PhysicsBody::createCircle(icon->getContentSize().width / 2);

	icon->setPhysicsBody(body);
	icon->setPosition(visibleSize / 2);

	this->addChild(icon);

	auto dispatcher = Director::getInstance()->getEventDispatcher();

	auto listener = EventListenerPhysicsContact::create();

	listener->onContactBegin = [](PhysicsContact& contact){
		log("hehe");
		return false;
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

Scene* PhysicsScene::createPhysicsScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto layer = PhysicsScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);

	return scene;
}

void PhysicsScene::createEdgeBox()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeNode->setPhysicsBody(body);
	addChild(edgeNode);
}

