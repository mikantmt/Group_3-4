#pragma once
#include "DxLib.h"
#include "../Input/Input.h"
#include "../GameBase/MiniGameBase.h"

#define GRAVITY		0.15f //�d��
#define JUMPPOWER	5.0f  //�W�����v�p���[

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH  32

class Player {
private:
	float Player_X;		//�v���C���[X���W
	float Player_Y;		//�v���C���[Y���W
	float PlayerNext_X; //�v���C���[�����W
	float PlayerNext_Y; //�v���C���[�����W

	MiniGameBase gamebase;
	
public:
	float Yspeed;		//�v���C���[��Y�X�s�[�h
	bool  JumpFlg;		//�����l��false

	void Init();
	void Step();
	void Draw(float X);


	//���W�̍X�V
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posX);
	void UpdatePos();

	// �ړ���̍��W���擾
	int GetNextPosX() { return (int)PlayerNext_X; }
	int GetNextPosY() { return (int)PlayerNext_Y; }

	// ���݂̍��W���擾
	float GetPosX() { return Player_X; }
	float GetPosY() { return Player_Y; }

	//�v���C���[�̐i��ł���������擾
	void GetMoveDirection(bool* _dirArray);
};