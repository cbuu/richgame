#pragma once

#include "cocos2d.h"

USING_NS_CC;

class SceneWrapper
{
public:
	SceneWrapper(void){}
	~SceneWrapper(void){}

	static Scene* wrap(Layer* node){
		auto pScene = Scene::create();
		pScene->addChild(node);
		return pScene;
	}
};

