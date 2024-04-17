#pragma once
#include "DxLib.h"
#include "../Input/Input.h"

#define GRAVITY		0.15f //�d��
#define JUMPPOWER	3.6f  //�W�����v�p���[

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH  32

class Player {
private:
	float Player_X;		//�v���C���[X���W
	float Player_Y;		//�v���C���[Y���W
	float PlayerNext_X; //�v���C���[�����W
	float PlayerNext_Y; //�v���C���[�����W
	
public:

	float Yspeed;		//�v���C���[��Y�X�s�[�h

	bool  JumpFlg;		//�����l��false

	void Init();
	void Step();
	void Draw();


	//���W�̍X�V
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posX);
	void UpdatePos();

	// �ړ���̍��W���擾
	int GetNextPosX() { return (int)PlayerNext_X; }
	int GetNextPosY() { return (int)PlayerNext_Y; }

	// ���݂̍��W���擾
	int GetPosX() { return (int)Player_X; }
	int GetPosY() { return (int)Player_Y; }

	//�v���C���[�̐i��ł���������擾
	void GetMoveDirection(bool* _dirArray);
};