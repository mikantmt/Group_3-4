#include "ScenePlay.h"

// �^�C�g��������
void Play::Init()
{
	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �^�C�g���ʏ폈��
void Play::Step()
{

	if (m_blendfrag) {
		m_BlendAlpha += 3;
	}
	else {
		m_BlendAlpha -= 3;
	}

	if (m_BlendAlpha < 0) {
		m_blendfrag = true;
	}
	if (m_BlendAlpha > 255) {
		m_blendfrag = false;
	}

	if (IsKeyPush(KEY_INPUT_A)) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// �^�C�g���`�揈��
void Play::Draw()
{
	//���ߏ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "�v���C");
}

// �^�C�g���I������
void Play::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}