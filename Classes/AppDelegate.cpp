
#include "AppDelegate.h"
#include "utils/SceneWrapper.h"
#include "GameSelectScene.h"
#include "Demo/Demo.h"
#include "TestGame/MainScene.h"
#include "PushBox/PushBoxScene.h"
#include "PhysicsGame/PhysicsScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);


	//创建游戏入口类
	GameSelectScene* layer = GameSelectScene::create();

	//为入口界面添加菜单项 lambda写法
	layer->addMenuItems("Demo", [](Ref* sender){
		auto director = Director::getInstance();
		director->replaceScene(SceneWrapper::wrap(Demo::create()));
	});

	layer->addMenuItems("PushBox", [](Ref* sender){
		auto director = Director::getInstance();
		director->replaceScene(SceneWrapper::wrap(PushBoxScene::create()));
	});

	layer->addMenuItems("PhysicsGame", [](Ref* sender){
		auto director = Director::getInstance();
		director->replaceScene(PhysicsScene::createPhysicsScene());
	});

	layer->addMenuItems("RichGame", [](Ref* sender){
		log("richgame");
	});


    // run
	director->runWithScene(SceneWrapper::wrap(layer));

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

