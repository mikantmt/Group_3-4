#include "SceneTitle.h"

// �^�C�g��������
void Title::Init()
{
	collision.Init();

	sound.Init();
	sound.Step(SOUND_TYPE_3, DX_PLAYTYPE_LOOP);

	Score::Read();

	// �^�C�g���摜�n���h��
	TitleImgHandle[TITLE_BACKGROUND] = LoadGraph(TITLE_BG_PATH);
	TitleImgHandle[TITLE_START] = LoadGraph(START_IMG_PATH);
	TitleImgHandle[TITLE_QUIT] = LoadGraph(QUIT_IMG_PATH);
	TitleImgHandle[TITLE_UPDATE] = LoadGraph(UPDATE_IMG_PATH);

	// �Z���N�g�ϐ�
	for (int SelectIndex = 0; SelectIndex < TITLE_SELECT_NUM; SelectIndex++)
	{
		Select[SelectIndex] = 0;
	}

	// �p�x�ϐ�
	Angle = ANGLE_MINIMUM;

	// ��]����
	isRotate = false;

	// �����x�ϐ�
	Transparency = TRANSPARENCY_HALF;

	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// �^�C�g���ʏ폈��
void Title::Step()
{

	if (m_blendfrag){
		m_BlendAlpha+=3;
	}
	else{
		m_BlendAlpha-=3;
	}

	if (m_BlendAlpha < 0){
		m_blendfrag = true;
	}
	if (m_BlendAlpha > 255){
		m_blendfrag = false;
	}

	// �Z���N�g�ϐ�����
	SelectProcessing();

	// �n�C�X�R�A������
	Reset();
}

// �^�C�g���`�揈��
void Title::Draw()
{
	//���ߏ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �^�C�g���w�i�`��
	DrawGraph(0, 0, TitleImgHandle[TITLE_BACKGROUND], true);

	// �X�V�摜�`��
	DrawRotaGraph(SCREEN_SIZE_X - 40, 40, 0.05f, Angle, TitleImgHandle[TITLE_UPDATE], true, false);

	// �I��`�揈��
	DrawSelect();
}

// �^�C�g���I������
void Title::Fin()
{
	// �^�C�g���摜�n���h��
	for (int ImgIndex = 0; ImgIndex < TITLE_IMG_NUM; ImgIndex++)
	{
		DeleteGraph(TitleImgHandle[ImgIndex]);
	}

	sound.Fin();

	// �����x�ϐ�
	Transparency = TRANSPARENCY_MINIMUM;

	// �p�x�ϐ�
	Angle = ANGLE_MINIMUM;

	// ��]����
	isRotate = false;
	
	// �V�[���Z���N�g��[�͂���]�ł����
	if (Select[TITLE_SELECT_SCENE] == TITLE_SCENE_SELECT_START)
	{
		// �Z���N�g�ϐ�
		for (int SelectIndex = 0; SelectIndex < TITLE_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// �v���C�V�[���ɑJ��
		g_CurrentSceneId = SCENE_ID_INIT_PLAY;
	}
	// �V�[���Z���N�g��[�����]�ł����
	else if (Select[TITLE_SELECT_SCENE] == TITLE_SCENE_SELECT_QUIT)
	{
		// �Z���N�g�ϐ�
		for (int SelectIndex = 0; SelectIndex < TITLE_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// �Q�[���I��
		DxLib_End();
	}
}

// �I��`�揈��
void Title::DrawSelect()
{
	// �摜�Z���N�g��[�͂���]�ł����
	if (Select[TITLE_SELECT_IMG] == TITLE_IMG_SELECT_START)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_START], true, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_CHANGE);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// �摜�Z���N�g��[�����]�ł����
	else if (Select[TITLE_SELECT_IMG] == TITLE_IMG_SELECT_QUIT)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_QUIT], true, false);
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_CHANGE);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// �摜�Z���N�g��[�摜�Ȃ�]�ł����
	else if (Select[TITLE_SELECT_IMG] == TITLE_IMG_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_CHANGE);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], true, false);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// �X�^�[�g����
void Title::Start() {
	// �摜�Z���N�g��[�͂���]�ɕύX
	Select[TITLE_SELECT_IMG] = TITLE_IMG_SELECT_START;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (START_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (START_IMG_SIZE_H / 2), START_IMG_SIZE_W, START_IMG_SIZE_H))
	{
		// �V�[���Z���N�g��[�͂���]�ɕύX
		Select[TITLE_SELECT_SCENE] = TITLE_SCENE_SELECT_START;

		// �^�C�g���I���V�[����
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}


// �Q�[���I������
void Title::QuitGame() {
	// �摜�Z���N�g��[�����]�ɕύX
	Select[TITLE_SELECT_IMG] = TITLE_IMG_SELECT_QUIT;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (QUIT_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (QUIT_IMG_SIZE_H / 2), QUIT_IMG_SIZE_W, QUIT_IMG_SIZE_H))
	{
		// �V�[���Z���N�g��[�����]�ɕύX
		Select[TITLE_SELECT_SCENE] = TITLE_SCENE_SELECT_QUIT;

		// �^�C�g���I���V�[����
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �Z���N�g�ϐ�����
void Title::SelectProcessing() {
	if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (START_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (START_IMG_SIZE_H / 2), START_IMG_SIZE_W, START_IMG_SIZE_H))
	{
		// �X�^�[�g����
		Start();
	}
	else if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (QUIT_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (QUIT_IMG_SIZE_H / 2), QUIT_IMG_SIZE_W, QUIT_IMG_SIZE_H))
	{
		// �Q�[���I������
		QuitGame();
	}
	else
	{
		// �摜�Z���N�g��[�摜�Ȃ�]�ɕύX
		Select[TITLE_SELECT_IMG] = TITLE_IMG_SELECT_NOTHING;
	}
}

// �n�C�X�R�A������
void Title::Reset()
{
	// �摜���N���b�N������
	if (collision.IsClickOnRect(SCREEN_SIZE_X - 70, 10, 60, 60))
	{
		// �n�C�X�R�A��������
		Score::Reset();

		// ��]�����true
		isRotate = true;
	}

	// ��]���肪true�ł����
	if (isRotate == true) {
		// �摜����]������
		Angle -= 0.1f;
	}

	// �p�x���}�b�N�X�܂ōs������
	if (Angle < -ANGLE_MAX)
	{
		// �p�x�Ɖ�]�����������
		isRotate = false;
		Angle = 0;
	}
}
