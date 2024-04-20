#pragma once
#include <DxLib.h>
#include "../Input/Input.h"

const float FRAME_RATE = 60;
const float CHANGE_ANIME_TIME = 0.1f;
const int   ANIME_IMG_MAX = 6;			//�A�j���̖���

//�A�j���̎��
enum EAnimeKind
{
	EAnimeKindWait, //�ҋ@�A�j��
	EAnimeKindWalk,	//�����A�j��
	EAnimeKindJump,	//�W�����v�A�j��

	EAnimeKindNum,	//�A�j����
};

class cAnimation {
private:
	int	  Handle[EAnimeKindNum][ANIME_IMG_MAX];

	float AnimeTime;	//�A�j������
	int   AnimeIndex;	//�A�j���ԍ�

	//�e�A�j���̉摜�g�p��
	int animeUsedNum[EAnimeKindNum];
public:
	//���݂̃A�j���̎��
	EAnimeKind currentAnimeKind;

	void Init();
	void Set(EAnimeKind Anime);

	//���E�ړ��ƃW�����v�̂���ꍇ
	void Step(int Key1,int Key2,int Key3);
	//�W�����v�݂̂̏ꍇ
	void Step(int Key1);
	void Draw(float X,float Y,float dif);
	void Fin();

	
};