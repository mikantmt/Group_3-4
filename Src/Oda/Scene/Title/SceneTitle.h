#pragma once
#include "../../Scene/Scene.h"
#include "../../Score/Score.h"

// �摜�p�X
constexpr char TITLE_BG_PATH[128] = "../Data/TitleScene/Titlekari.png";
constexpr char START_IMG_PATH[128] = "../Data/TitleScene/Start.png";
constexpr char QUIT_IMG_PATH[128] = "../Data/TitleScene/QuitGame.png";
constexpr char UPDATE_IMG_PATH[128] = "../Data/TitleScene/Update.png";

// �摜�̑傫��
const int START_IMG_SIZE_W = 350;
const int START_IMG_SIZE_H = 70;

const int QUIT_IMG_SIZE_W = 350;
const int QUIT_IMG_SIZE_H = 70;

enum TitleImgHandle {
	TITLE_BACKGROUND,
	TITLE_START,
	TITLE_QUIT,
	TITLE_UPDATE,

	TITLE_IMG_NUM,
};

enum TitleSelect {
	TITLE_SELECT_IMG,		// �摜
	TITLE_SELECT_SCENE,		// �V�[��

	TITLE_SELECT_NUM		// 2
};

enum TitleImgSelect {
	TITLE_IMG_SELECT_START,		// �͂���
	TITLE_IMG_SELECT_QUIT,		// �����
	TITLE_IMG_SELECT_NOTHING,	// �摜�Ȃ�

	TITLE_IMG_SELECT_NUM		// 3
};

enum TitleSceneSelect {
	TITLE_SCENE_SELECT_START,	// �͂���
	TITLE_SCENE_SELECT_QUIT,	// �����

	TITLE_SCENE_SELECT_NUM		// 2
};

class Title : public Scene {
private:
	// �^�C�g���摜�n���h��
	int TitleImgHandle[TITLE_IMG_NUM];

	// �Z���N�g�ϐ�
	int Select[TITLE_SELECT_NUM];

	// �p�x�ϐ�
	float Angle;

	// ��]����
	bool isRotate;

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

	// �n�C�X�R�A������
	void Updeta();
};

