#pragma once
#include "DxLib.h"
#include "../Input/Input.h"
#include "../GameBase/MiniGameBase.h"

const float FRAME_RATE = 60;
const float CHANGE_ANIME_TIME = 0.1f;
const int   ANIME_IMG_MAX = 6;

#define GRAVITY		0.18f //�d��
#define JUMPPOWER	1.0f  //�W�����v�p���[

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH  32

//�A�j���̎��
enum EAnimeKind
{
	EAnimeKindWalk,	//�����A�j�� 0
	EAnimeKindJump,	//�W�����v�A�j�� 1

	EAnimeKindNum,		//�A�j���� 2
};

class Player {
private:
	float Player_X;		//�v���C���[X���W
	float Player_Y;		//�v���C���[Y���W
	float PlayerNext_X; //�v���C���[�����W
	float PlayerNext_Y; //�v���C���[�����W

	int	  Handle[EAnimeKindNum][ANIME_IMG_MAX];

	//���݂̃A�j���̎��
	EAnimeKind currentAnimeKind;

	float AnimeTime;	//�A�j������
	int   AnimeIndex;	//�A�j���ԍ�

	//�e�A�j���̉摜�g�p��
	int animeUsedNum[EAnimeKindNum];

	MiniGameBase gamebase;
	
public:
	float Yspeed;		//�v���C���[��Y�X�s�[�h
	float JumpCount;	//�W�����v���Ă���̃t���[��
	bool  JumpFlg;		//�����l��false
	bool  ActiveFlg;	//�����t���O
	bool  AirFlg;		//�󒆔���

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