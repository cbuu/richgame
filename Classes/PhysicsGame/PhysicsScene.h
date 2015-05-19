#include "cocos2d.h"

USING_NS_CC;

class PhysicsScene:public Layer
{
public:
	PhysicsScene();
	~PhysicsScene();

	static Scene* createPhysicsScene();

	CREATE_FUNC(PhysicsScene);

	virtual bool init();

	void setPhysicsWorld(PhysicsWorld* world){ m_world = world; }


	void createEdgeBox();

private:
	PhysicsWorld* m_world;
};
