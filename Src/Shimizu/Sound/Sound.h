#pragma once
#include "DxLib.h"

//�T�E���h�̎��
enum SOUND_TYPE
{
	SOUND_TYPE_1 = 0,	
	SOUND_TYPE_2,
	SOUND_TYPE_3,
	SOUND_TYPE_JUMP,

	SOUND_TYPE_NUM,
};

class cSound {
private:

	//csv�̃t�@�C���p�X
	const char SoundPath[SOUND_TYPE_NUM][256] =
	{
		"../Data/BGM/Stage1.mp3",	//Sound1
		"../Data/BGM/Stage2.mp3",
		"../Data/BGM/TitleBGM.mp3",
		"../Data/BGM/Jump.mp3",
	};

	int Sound[SOUND_TYPE_NUM];

public:
	//LOOP�̎���Init,Step�𓯎��ɌĂ�
	void Init();
	//�T�E���h�Đ�(�T�E���h�̎��,�Đ��^�C�v(�m�[�}��,�o�b�N�O���E���h,���[�v))
	void Step(SOUND_TYPE sound, int playtype);
	void Fin();
};