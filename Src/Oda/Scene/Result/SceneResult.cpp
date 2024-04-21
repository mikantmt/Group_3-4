#include "SceneResult.h"

// �^�C�g��������
void Result::Init()
{
	// �n�C�X�R�A�̍X�V
	Score::Update();

	// ���U���g�w�i�n���h��
	ResultImgHandle[RESULT_BACKGROUND] = LoadGraph(RESULT_BG_PATH);
	ResultImgHandle[RESULT_RETURN] = LoadGraph(RETURN_IMG_PATH);
	ResultImgHandle[RESULT_AGAIN] = LoadGraph(AGAIN_IMG_PATH);

	// �Z���N�g�ϐ�
	Select = RESULT_SELECT_NOTHING;

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

	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}

// �I��`�揈��
void Result::DrawSelect()
{
	if (Select == RESULT_SELECT_RETURN)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == RESULT_SELECT_AGAIN)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == RESULT_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// �X�^�[�g����
void Result::Return() {
	// �Z���N�g��Start�ɕύX
	Select = RESULT_SELECT_RETURN;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// ���U���g�I���V�[����
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}


// �Q�[���I������
void Result::Again() {
	// �Z���N�g��Quit�ɕύX
	Select = RESULT_SELECT_AGAIN;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// �Q�[���I��
		DxLib_End();
	}
}

// �Z���N�g�ϐ�����
void Result::SelectProcessing() {
	if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// �X�^�[�g����
		Return();
	}
	else if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// �Q�[���I������
		Again();
	}
	else
	{
		Select = RESULT_SELECT_NOTHING;
	}
}
