#pragma once
#include "../../Scene/Scene.h"
#include "../../Score/Score.h"

// �摜�p�X
constexpr char RESULT_BG_PATH[128] = "../Data/ResultScene/ResultBG.png";
constexpr char RETURN_IMG_PATH[128] = "../Data/ResultScene/ReturnTitle.png";
constexpr char AGAIN_IMG_PATH[128] = "../Data/ResultScene/StartAgain.png";
constexpr char TROPHY_IMG_PATH[128] = "../Data/ResultScene/Trophy.png";

// �摜�̑傫��
const int RETURN_IMG_SIZE_W = 350;
const int RETURN_IMG_SIZE_H = 70;

const int AGAIN_IMG_SIZE_W = 350;
const int AGAIN_IMG_SIZE_H = 70;

// �t�H���g�p�X
constexpr char FONT_PATH[128] = "../Data/Font/Qarmic_sans_Abridged.ttf";

enum ResultImgHandle {
	RESULT_BACKGROUND,		// ���U���g�w�i
	RESULT_RETURN,			// �^�C�g���ɖ߂�
	RESULT_AGAIN,			// ������x
	RESULT_TROPHY,			// �g���t�B�[

	RESULT_IMG_NUM			// 3
};

enum ResultSelect {
	RESULT_SELECT_IMG,		// �摜
	RESULT_SELECT_SCENE,	// �V�[��

	RESULT_SELECT_NUM		// 2
};

enum ResultImgSelect {
	RESULT_IMG_SELECT_RETURN,	// �^�C�g���ɖ߂�摜
	RESULT_IMG_SELECT_AGAIN,	// ������x�摜
	RESULT_IMG_SELECT_NOTHING,	// �摜�Ȃ�

	RESULT_IMG_SELECT_NUM		// 3
};

enum ResultSceneSelect {
	RESULT_SCENE_SELECT_RETURN,	// �^�C�g���ɖ߂�
	RESULT_SCENE_SELECT_AGAIN,	// ������x

	RESULT_SCENE_SELECT_NUM		// 2
};


class Result : public Scene {
private:
	// ���U���g�摜�n���h��
	int ResultImgHandle[RESULT_IMG_NUM];

	// �Z���N�g�ϐ�
	int Select[RESULT_SELECT_NUM];

	// �����x�ϐ�
	int Transparency;

	// �t�H���g�n���h��
	LPCSTR FontPath;

	//�X�R�A�t�H���g
	int FontScore;
	int FontHighScore;

	// ������̕`�敝���擾
	int DrawScoreWidth;
	int DrawHighScoreWidth;

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

	// �X�R�A�`�揈��
	void DrawScore();

	// �^�C�g���ɖ߂鏈��
	void Return();

	// ������x��鏈��
	void Again();

	// �Z���N�g�ϐ�����
	void SelectProcessing();
};
