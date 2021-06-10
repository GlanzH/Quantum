#pragma once
#include "BaseScene.h"

class SceneManager
{
public:
	//static�͂��Ƃ��Ƃ�����́i�C���X�^���X����O���炠��j
	//static�͈�����Ȃ����́i�萔�Ȃǁj
	//static�ϐ��͐�Ώ������K�v
	static enum SCENE
	{
		TITLE,//�^�C�g���V�[��
		MAIN,//�Q�[���̃��C���V�[��
		CLAER_SCENE,//�N���A�V�[��
		OVER_SCENE,//�Q�[���I�[�o�[�V�[��
		RESULT//���U���g�V�[��
	};
	
   static void ChangeScene(SCENE scene);
   static void Update();
   static void Draw();
   static void DrawEnd();

   static  BaseScene* m_pScene;

   static int index;

private:
	
};
