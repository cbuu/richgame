#include "Demo/Demo.h"

#include <sqlite3/include/sqlite3.h>
#include<iostream>
using namespace std;

//#pragma comment(lib,"C:/Users/CBUU/Desktop/project/richgame/cocos2d/external/sqlite3/libraries/win32/sqlite3.lib")

Demo::Demo()
{

}

Demo::~Demo()
{

}

bool Demo::init()
{
	if (!Layer::init())
	{
		return false;
	}
	testTMX();
	testMap();
	testSQLite();
	
	return true;
}

void Demo::testVector(){
	Vector<Sprite*> container;

	Sprite* A = Sprite::create();
	Sprite* B = Sprite::create();
	Sprite* C = Sprite::create();

	A->setTag(0);
	B->setTag(1);
	C->setTag(2);

	container.pushBack(A);
	container.pushBack(B);
	container.pushBack(C);

	Sprite* sp = container.back();
	log("the tag is %d", sp->getTag());

	sp = container.at(1);
	log("the tag is %d", sp->getTag());

	Vector<Sprite*>::iterator it = container.begin();

	for (; it != container.end();)
	{
		if ((*it)->getTag() == 1)
		{
			it = container.erase(it);
		}
		else
		{
			it++;
		}
	}

	sp = container.at(1);
	log("the tag is %d", sp->getTag());

}

void Demo::testTMX()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	TMXTiledMap* tmx = TMXTiledMap::create("PushBox/map.tmx");
	tmx->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	tmx->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(tmx);
}

void Demo::testUserDefault()
{
	if (!UserDefault::getInstance()->getBoolForKey("isExist"))
	{
		UserDefault::getInstance()->setBoolForKey("isExist", true);
	}

	UserDefault::getInstance()->setStringForKey("key", "value");
	string word = UserDefault::getInstance()->getStringForKey("key");
	log("the word is %s " , word);

	UserDefault::getInstance()->setIntegerForKey("value", 14);
	int value = UserDefault::getInstance()->getIntegerForKey("value");
	log("the value is %d ", value);
}

void Demo::testSQLite()
{
	sqlite3* pdb = NULL;
	
	string path = FileUtils::getInstance()->getWritablePath() + "save.db";

	int result = sqlite3_open(path.c_str(), &pdb);

	if (result==SQLITE_OK)
	{
		log("database init");
	}

	string sql = "create table hero(ID int primary key not null,name char(10));";

	result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);

	if (result==SQLITE_OK)
	{
		log("create table");
	}

	//插入数据
	sql = "insert into hero values(1,'iori');";
	sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);
	
	sql = "insert into hero values(2,'cbuu');";
	sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);

	sql = "insert into hero values(3,'hoho');";
	sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);

	//删除数据
	sql = "delete from hero where id=1;";
	sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);

	//更改数据
	sql = "update hero set name='hehe' where id=3;";
	sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);



	//查询数据
	char **re;
	int row, col;

	sqlite3_get_table(pdb, "select * from hero", &re, &row, &col,NULL);
	

	//由于第0行是表头，所以真正的数据从第1行开始；
	for (int i = 1; i <= row;i++)
	{
		for (int j = 0; j < col;j++)
		{
			log("%s", re[i*col + j]);
		}
	}

	//务必释放指针
	sqlite3_free_table(re);

	sqlite3_close(pdb);
}

void Demo::testMap()
{
	Map<string, Sprite*> map;

	Sprite* A = Sprite::create();
	Sprite* B = Sprite::create();
	Sprite* C = Sprite::create();

	A->setTag(0);
	B->setTag(1);
	C->setTag(2);

	map.insert("hero", A);
	map.insert("monster", B);
	map.insert("object", C);

	Sprite* sp = map.at("monster");
	log("the tag is %d", sp->getTag());

	Map<string, Sprite*>::iterator it = map.begin();

	for (; it != map.end();)
	{
		
		if ((*it).first == "monster")
		{
			it = map.erase(it);
		}
		else
		{
			it++;
		}
	}

	sp = map.at("monster");
	if (sp==NULL)
	{
		log("can not find the monster");
	}
	else
	{
		log("the tag is %d", sp->getTag());
	}
	
}
