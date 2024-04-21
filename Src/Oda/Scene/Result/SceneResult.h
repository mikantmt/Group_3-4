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
	RESULT_BACKGROUND,		// ���U���g�w�i
	RESULT_RETURN,			// �^�C�g���ɖ߂�
	RESULT_AGAIN,			// ������x

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

	// ������x��鏈��
	void Again();

	// �Z���N�g�ϐ�����
	void SelectProcessing();
};
