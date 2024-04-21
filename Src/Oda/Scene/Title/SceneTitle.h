#pragma once
#include "../../Scene/Scene.h"

// �摜�p�X
constexpr char TITLE_BG_PATH[128] = "../Data/TitleScene/TentativeTitleBG.png";
constexpr char START_IMG_PATH[128] = "../Data/TitleScene/Start.png";
constexpr char QUIT_IMG_PATH[128] = "../Data/TitleScene/QuitGame.png";

// �摜�̑傫��
const int START_IMG_SIZE_W = 350;
const int START_IMG_SIZE_H = 70;

const int QUIT_IMG_SIZE_W = 350;
const int QUIT_IMG_SIZE_H = 70;

// �摜�`��T�C�Y
static const float IMG_SIZE_SMALL = 0.9f;
static const float IMG_SIZE_BIG = 1.1f;

// �����x
static const int TRANSPARENCY_MAX = 256;
static const int TRANSPARENCY_HALF = 128;
static const int TRANSPARENCY_MINIMUM = 0;

enum TitleImgHandle {
	TITLE_BACKGROUND,
	TITLE_START,
	TITLE_QUIT,

	TITLE_IMG_NUM,
};

enum TitleSelect {
	TITLE_SELECT_START,
	TITLE_SELECT_QUIT,
	TITLE_SELECT_NOTHING,

	TITLE_SELECT_NUM,
};

class Title : public Scene {
private:
	// �^�C�g���摜�n���h��
	int TitleImgHandle[TITLE_IMG_NUM];

	// �摜�T�C�Y
	float ImgSize[TITLE_SELECT_NUM];

	// �Z���N�g�ϐ�
	int Select;

	// �����x�ϐ�
	int Transparency;


public:
	Collision collision;

	//PressEnter���ߕϐ�
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;


	// �^�C�g��������
	void Init();
	// �^�C�g���ʏ폈��
	void Step();
	// �^�C�g���`�揈��
	void Draw();
	// �^�C�g���I������
	void Fin();

	// �I��`�揈��
	void DrawSelect();

	// �X�^�[�g����
	void Start();

	// �Q�[���I������
	void QuitGame();

	// �Z���N�g�ϐ�����
	void SelectProcessing();
};

