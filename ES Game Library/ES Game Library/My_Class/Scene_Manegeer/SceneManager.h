#pragma once
#include "BaseScene.h"

class SceneManager
{
public:
	//static�͂��Ƃ��Ƃ�����́i�C���X�^���X����O���炠��j
	//static�͈�����Ȃ����́i�萔�Ȃǁj
	//static�ϐ��͐�Ώ������K�v
	enum SCENE
	{
		TITLE,//�^�C�g���V�[��
		MAIN,//�Q�[���̃��C���V�[��
		CLEAR_SCENE,//�N���A�V�[��
		OVER_SCENE,//�Q�[���I�[�o�[�V�[��
		RESULT//���U���g�V�[��
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
