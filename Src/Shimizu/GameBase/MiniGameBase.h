#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../../Oda/Scene/Scene.h"

#define _1Frame 60
#define COUNT_NUM 4

const int LimitTime = 210.0f;

class MiniGameBase {
protected:
	bool  IsFin;					//�Q�[���I���t���O(�����l��false)
	bool  IsClear;					//�Q�[���N���A�t���O(�����l��false)
	float Startlimit;				//�J�n�܂ł̃J�E���g�_�E��
	int   GamePoint;				//���̃Q�[���̓��_
	int	  Handle[COUNT_NUM];		//�J�E���g�_�E���摜

	void  CountDown(float limit);	//�J�E���g�_�E���̊֐�(210���Œ�)

	//�͈͎w��ł��闐���̊֐�(����,���)
	float ScopingRand(float min, float max);

	//�w��͈͂����O�ł��闐���̊֐�(����,���,���O����������,���O���������)
	float OutRand(float min, float max,float out_min,float out_max);

	/*void ResetGame();*/

private:

public:
	void Init();
	void Play();
	void Draw();
	void Fin();
};