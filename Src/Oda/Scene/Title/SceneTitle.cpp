#include "SceneTitle.h"
#include "../../Score/Score.h"

// �^�C�g��������
void Title::Init()
{
	// �X�R�A�̏�����
	Score::Init();

	collision.Init();

	// �^�C�g���摜�n���h��
	TitleImgHandle[TITLE_BACKGROUND] = LoadGraph(TITLE_BG_PATH);
	TitleImgHandle[TITLE_START] = LoadGraph(START_IMG_PATH);
	TitleImgHandle[TITLE_QUIT] = LoadGraph(QUIT_IMG_PATH);

	// �摜�T�C�Y
	for (int SizeIndex = 0; SizeIndex < TITLE_SELECT_NUM; SizeIndex++)
	{
		ImgSize[SizeIndex] = IMG_SIZE_SMALL;
	}

	// �Z���N�g�ϐ�
	Select = TITLE_SELECT_NOTHING;

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

	if (IsKeyPush(KEY_INPUT_A)) {
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void Title::Draw()
{
	//���ߏ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �^�C�g���w�i�`��
	DrawGraph(0, 0, TitleImgHandle[TITLE_BACKGROUND], true);

	// �I��`�揈��
	DrawSelect();

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "�^�C�g��");
}

// �^�C�g���I������
void Title::Fin()
{
	// �^�C�g���摜�n���h��
	for (int ImgIndex = 0; ImgIndex < TITLE_IMG_NUM; ImgIndex++)
	{
		DeleteGraph(TitleImgHandle[ImgIndex]);
	}
	
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}

// �I��`�揈��
void Title::DrawSelect()
{
	if (Select == TITLE_SELECT_START)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_START], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == TITLE_SELECT_QUIT)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_QUIT], false, false);
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == TITLE_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], false, false);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// �X�^�[�g����
void Title::Start() {
	// �Z���N�g��Start�ɕύX
	Select = TITLE_SELECT_START;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (START_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (START_IMG_SIZE_H / 2), START_IMG_SIZE_W, START_IMG_SIZE_H))
	{
		// �^�C�g���I���V�[����
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}


// �Q�[���I������
void Title::QuitGame() {
	// �Z���N�g��Quit�ɕύX
	Select = TITLE_SELECT_QUIT;

	// �摜���N���b�N������
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (QUIT_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (QUIT_IMG_SIZE_H / 2), QUIT_IMG_SIZE_W, QUIT_IMG_SIZE_H))
	{
		// �Q�[���I��
		DxLib_End();
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
		Select = TITLE_SELECT_NOTHING;
	}
}
