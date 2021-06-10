//#include "Enemy_Base.h"
//#include"../Enemy_Class/Enemy_One/Enemy_One.h"
//#include"../Enemy_Class/Enemy_Second/Enemy_Second.h"
//#include"../Enemy_Class/Enemy_Third/Enemy_Third.h"
//
//bool Enemy_Base::Initialize(Vector3 pos,string name)
//{
//	if(name == "normal")
//	Enemy = GraphicsDevice.CreateSpriteFromFile(_T("Player_Enemy/Enemy.png"));
//	Enemies_x = pos.x;
//	Enemies_y = 505.0f;
//	Start_x = 1280.0f;
//    Move = 3.0f;
//	return true;
//}
//
//int Enemy_Base::Update()
//{
//	Enemies_x = Enemies_x - Move;
//	if (Enemies_x < -100.0f)
//	{
//		Enemies_x = Start_x;
//	}
//	return 0;
//}
//
//void Enemy_Base::Draw()
//{
//	SpriteBatch.Draw(*Enemy, Vector3(Enemies_x, Enemies_y, 0));
//}
//
//
