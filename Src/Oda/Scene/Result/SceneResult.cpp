#include "SceneResult.h"

// �^�C�g��������
void Result::Init()
{
	// �n�C�X�R�A�̍X�V
	Score::Update();

	sound.Init();
	sound.Step(SOUND_TYPE_1, DX_PLAYTYPE_LOOP);

	// ���U���g�w�i�n���h��
	ResultImgHandle[RESULT_BACKGROUND] = LoadGraph(RESULT_BG_PATH);
	ResultImgHandle[RESULT_RETURN] = LoadGraph(RETURN_IMG_PATH);
	ResultImgHandle[RESULT_AGAIN] = LoadGraph(AGAIN_IMG_PATH);

	// �Z���N�g�ϐ�
	for (int SelectIndex = 0; SelectIndex < RESULT_SELECT_NUM; SelectIndex++)
	{
		Select[SelectIndex] = 0;
	}

	// �����x�ϐ�
	Transparency = TRANSPARENCY_HALF;

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

	SelectProcessing();
}

// �^�C�g���`�揈��
void Result::Draw()
{
	//���ߏ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// ���U���g�w�i�`��
	DrawGraph(0, 0, ResultImgHandle[RESULT_BACKGROUND], true);

	// �I��`�揈��
	DrawSelect();
}

// �^�C�g���I������
void Result::Fin()
{
	// ���U���g�摜�n���h��
	for (int ImgIndex = 0; ImgIndex < RESULT_IMG_NUM; ImgIndex++)
	{
		DeleteGraph(ResultImgHandle[ImgIndex]);
	}

	sound.Fin();

	// �����x�ϐ�
	Transparency = 0;

	// �V�[���Z���N�g��[�^�C�g���ɖ߂�]�ł����
	if (Select[RESULT_SELECT_SCENE] == RESULT_SCENE_SELECT_RETURN)
	{
		// �Z���N�g�ϐ�
		for (int SelectIndex = 0; SelectIndex < RESULT_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// �v���C�V�[���ɑJ��
		g_CurrentSceneId = SCENE_ID_INIT_TITLE;
	}
	// �V�[���Z���N�g��[������x]�ł����
	else if (Select[RESULT_SELECT_SCENE] == RESULT_SCENE_SELECT_AGAIN)
	{
		// �Z���N�g�ϐ�
		for (int SelectIndex = 0; SelectIndex < RESULT_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// �v���C�V�[���ɑJ��
		g_CurrentSceneId = SCENE_ID_INIT_PLAY;
	}
}

// �I��`�揈��
void Result::DrawSelect()
{
	// �摜�Z���N�g��[�^�C�g���ɖ߂�]�ł����
	if (Select[RESULT_SELECT_IMG] == RESULT_IMG_SELECT_RETURN)
	{
		DrawRotaGraph(SCREEN_SIZE_X * 3 / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// �摜�Z���N�g��[������x]�ł����
	else if (Select[RESULT_SELECT_IMG] == RESULT_IMG_SELECT_AGAIN)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X * 3 / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// �摜�Z���N�g��[�摜�Ȃ�]�ł����
	else if (Select[RESULT_SELECT_IMG] == RESULT_IMG_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X * 3 / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		DrawRotaGraph(SCREEN_SIZE_X / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// �^�C�g���ɖ߂鏈��
void Result::Return() {
	// �摜�Z���N�g��[�^�C�g���ɖ߂�摜]�ɕύX
	Select[RESULT_SELECT_IMG] = RESULT_IMG_SELECT_RETURN;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X * 3 / 4) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// �V�[���Z���N�g��[�^�C�g���ɖ߂�]�ɕύX
		Select[RESULT_SELECT_SCENE] = RESULT_SCENE_SELECT_RETURN;

		// ���U���g�I���V�[����
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}


// ������x��鏈��
void Result::Again() {
	// �摜�Z���N�g��[������x�摜]�ɕύX
	Select[RESULT_SELECT_IMG] = RESULT_IMG_SELECT_AGAIN;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 4) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// �V�[���Z���N�g��[������x]�ɕύX
		Select[RESULT_SELECT_SCENE] = RESULT_SCENE_SELECT_AGAIN;

		// ���U���g�I���V�[����
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

// �Z���N�g�ϐ�����
void Result::SelectProcessing() {
	if (collision.RectToMousePointa((SCREEN_SIZE_X * 3 / 4) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// �^�C�g���ɖ߂鏈��
		Return();
	}
	else if (collision.RectToMousePointa((SCREEN_SIZE_X / 4) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// ������x��鏈��
		Again();
	}
	else
	{
		// �摜�Z���N�g��[�摜�Ȃ�]�ɕύX
		Select[RESULT_SELECT_IMG] = RESULT_IMG_SELECT_NOTHING;
	}
}
