#pragma once
#include "../../Scene/Scene.h"

class Title : public Scene {
private:

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

