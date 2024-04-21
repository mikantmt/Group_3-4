#include "SceneResult.h"
#include "../../Score/Score.h"

// �^�C�g��������
void Result::Init()
{
	// �n�C�X�R�A�̍X�V
	Score::Update();

	// ���U���g�w�i�n���h��
	ResultImgHandle[RESULT_BACKGROUND] = LoadGraph(RESULT_BG_PATH);

	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

// �^�C�g���ʏ폈��
void Result::Step()
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
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

// �^�C�g���`�揈��
void Result::Draw()
{
	//���ߏ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// ���U���g�w�i�`��
	DrawGraph(0, 0, ResultImgHandle[RESULT_BACKGROUND], true);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "���U���g");
}

// �^�C�g���I������
void Result::Fin()
{
	// ���U���g�摜�n���h��
	for (int ImgIndex = 0; ImgIndex < RESULT_IMG_NUM; ImgIndex++)
	{
		DeleteGraph(ResultImgHandle[ImgIndex]);
	}

	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}