#include "ScenePlay.h"

// �v���C������
void Play::Init()
{
	player.Init();
	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �v���C�ʏ폈��
void Play::Step()
{
	player.Player_Move();

	if (IsKeyPush(KEY_INPUT_A)) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// �v���C�`�揈��
void Play::Draw()
{
	player.Draw();

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "�v���C");
}

// �v���C�I������
void Play::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}