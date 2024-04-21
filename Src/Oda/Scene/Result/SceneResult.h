#pragma once
#include "../../Scene/Scene.h"
#include "../../Score/Score.h"

// �摜�p�X
constexpr char RESULT_BG_PATH[128] = "../Data/ResultScene/TentativeClearBG.png";
constexpr char RETURN_IMG_PATH[128] = "../Data/ResultScene/ReturnTitle.png";
constexpr char AGAIN_IMG_PATH[128] = "../Data/ResultScene/StartAgain.png";

// �摜�̑傫��
const int RETURN_IMG_SIZE_W = 350;
const int RETURN_IMG_SIZE_H = 70;

const int AGAIN_IMG_SIZE_W = 350;
const int AGAIN_IMG_SIZE_H = 70;

enum ResultImgHandle {
	RESULT_BACKGROUND,
	RESULT_RETURN,
	RESULT_AGAIN,

	RESULT_IMG_NUM,
};

enum ResultSelect {
	RESULT_SELECT_RETURN,
	RESULT_SELECT_AGAIN,
	RESULT_SELECT_NOTHING,

	RESULT_SELECT_NUM,
};

class Result : public Scene {
private:
	// ���U���g�摜�n���h��
	int ResultImgHandle[RESULT_IMG_NUM];

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

	// �^�C�g���ɖ߂鏈��
	void Return();

	// �Q�[���I������
	void Again();

	// �Z���N�g�ϐ�����
	void SelectProcessing();
};
