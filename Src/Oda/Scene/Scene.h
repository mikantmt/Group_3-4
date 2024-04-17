#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "../../Shimizu/Input/Input.h"
#include "../../Shimizu/Collision/Collision.h"


class Scene {
	public:
		virtual void Init() = 0;
		virtual void Step() = 0;
		virtual void Draw() = 0;
		virtual void Fin()  = 0;

};

enum SCENE_ID
{
	// �^�C�g���V�[����ID
	SCENE_ID_INIT_TITLE = 100,	// ������
	SCENE_ID_LOOP_TITLE,		// ���[�v
	SCENE_ID_FIN_TITLE,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_SELECT = 200,	// ������
	SCENE_ID_LOOP_SELECT,			// ���[�v
	SCENE_ID_FIN_SELECT,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_PLAY = 300,	// ������
	SCENE_ID_LOOP_PLAY,			// ���[�v
	SCENE_ID_FIN_PLAY,			// �I��

	// �V�[���̏��
	SCENE_ID_INIT_RESULT = 400,	// ������
	SCENE_ID_LOOP_RESULT,		// ���[�v
	SCENE_ID_FIN_RESULT,		// �I��
};

//�@���݂̃V�[��ID
extern SCENE_ID g_CurrentSceneId;