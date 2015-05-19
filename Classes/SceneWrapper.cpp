#include "utils/SceneWrapper.h"


SceneWrapper::SceneWrapper(void)
{
}


SceneWrapper::~SceneWrapper(void)
{
}

CCScene* SceneWrapper::wrap(CCNode* node)
{
	CCScene* pScene = CCScene::create();
	pScene->addChild(node);
	return pScene;
}
