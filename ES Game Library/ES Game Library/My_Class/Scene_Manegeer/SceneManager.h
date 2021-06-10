#pragma once
#include "BaseScene.h"

class SceneManager
{
public:
	//staticはもともとあるもの（インスタンスする前からある）
	//staticは一つしかないもの（定数など）
	//static変数は絶対初期化必要
	static enum SCENE
	{
		TITLE,//タイトルシーン
		MAIN,//ゲームのメインシーン
		CLAER_SCENE,//クリアシーン
		OVER_SCENE,//ゲームオーバーシーン
		RESULT//リザルトシーン
	};
	
   static void ChangeScene(SCENE scene);
   static void Update();
   static void Draw();
   static void DrawEnd();

   static  BaseScene* m_pScene;

   static int index;

private:
	
};
