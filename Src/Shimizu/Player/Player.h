#pragma once
#include "DxLib.h"
#include "../Input/Input.h"

#define GRAVITY		0.15f //�d��
#define JUMPPOWER	3.6f  //�W�����v�p���[

class Player {
private:
	float Player_X;		//�v���C���[X���W
	float Player_Y;		//�v���C���[Y���W
	float PlayerNext_X; //�v���C���[�����W
	float PlayerNext_Y; //�v���C���[�����W
	float Yspeed;		//�v���C���[��Y�X�s�[�h

	bool  JumpFlg;		//�����l��false
public:

	void Init();
	void Player_Move();
	void Draw();
};