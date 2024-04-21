#pragma once
#include "../../Scene/Scene.h"

// �摜�p�X
constexpr char RESULT_BG_PATH[128] = "../Data/ResultScene/TentativeClearBG.png";
constexpr char RETURN_IMG_PATH[128] = "../Data/ResultScene/ReturnTitle.png";
constexpr char AGAIN_IMG_PATH[128] = "../Data/ResultScene/StartAgain.png";

enum ResultImgHandle {
	RESULT_BACKGROUND,
	RESULT_RETURN,
	RESULT_AGAIN,

	RESULT_IMG_NUM,
};

class Result : public Scene {
private:
	int ResultImgHandle[RESULT_IMG_NUM];		// ���U���g�摜�n���h��

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
};
