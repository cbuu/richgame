#pragma once

#include "cocos2d.h"

USING_NS_CC;

class SceneWrapper
{
public:
	SceneWrapper(void);
	~SceneWrapper(void);

	static Scene* wrap(CCNode* node);
};

