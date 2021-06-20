#include"SceneManager.h"
#include"../Game_Scene/Title_Scene/Title_Scene.h"
#include"../Game_Scene/Main_Scene/Main_Scene.h"
#include"../Game_Scene/Game_Clear/Game_Clear.h"
#include"../Game_Scene/Game_Over/Game_Over.h"
#include"../Game_Scene/Result_Scene/Result_Scene.h"
BaseScene* SceneManager::m_pScene = nullptr;

void SceneManager::ChangeScene(SCENE scene)
{
	if (m_pScene != nullptr)
	{
		delete m_pScene;
	}
	switch (scene)
	{
	case SCENE::TITLE:
		m_pScene = new Title_Scene;
		break;
	case SCENE::MAIN:
		m_pScene = new Main_Scene;
		break;
	case SCENE::CLEAR_SCENE:
		m_pScene = new Game_Clear;
		break;
	case SCENE::OVER_SCENE:
		m_pScene = new Game_Over;
		break;
	case SCENE::RESULT:
		m_pScene = new Result_Scene;
	default:
		break;
	}
	m_pScene->Initialize();
}
void SceneManager::Update()
{
	m_pScene->Update();
}
void SceneManager::Draw()
{
	m_pScene->Draw();
}
void SceneManager::Draw3D() {
	m_pScene->Draw3D();
}
void SceneManager::DrawEnd()
{
	m_pScene->DrawEnd();
}

void SceneManager::SetScore(int num) {
	score = num;
}

int SceneManager::AddScore(int num) {
	score += num;
	return score;
}