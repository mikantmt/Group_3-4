#pragma once
#include "../../Scene/Scene.h"

// ���U���g�̔w�i�p�X
constexpr char RESULT_BG_PATH[128] = "../Data/ResultScene/TentativeClearBG.png";

class Result : public Scene {
private:
	int ResultBGHandle;		// ���U���g�w�i�n���h��

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
