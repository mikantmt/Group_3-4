#pragma once
#include "../../Scene/Scene.h"

// �^�C�g���̔w�i�p�X
constexpr char TITLE_BG_PATH[128] = "../Data/TitleScene/TentativeTitleBG.png";

class Title : public Scene {
private:
	int TitleBGHandle;		// �^�C�g���w�i�n���h��

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

