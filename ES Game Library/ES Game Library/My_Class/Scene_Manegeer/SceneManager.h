#pragma once
#include "BaseScene.h"

class SceneManager
{
public:
	//staticはもともとあるもの（インスタンスする前からある）
	//staticは一つしかないもの（定数など）
	//static変数は絶対初期化必要
	enum SCENE
	{
		TITLE,//タイトルシーン
		MAIN,//ゲームのメインシーン
		CLEAR_SCENE,//クリアシーン
		OVER_SCENE,//ゲームオーバーシーン
		RESULT//リザルトシーン
	};
	
   void ChangeScene(SCENE scene);
   void Update();
   void Draw();
   void Draw3D();
   void DrawEnd();

   void SetScore(int num);
   int AddScore(int num);
   int GetScore() { return score; }

   static SceneManager& Instance() {
	   static SceneManager instance;
	   return instance;
   }

   static BaseScene* m_pScene;

private:
   static int index;
   int score;
};
