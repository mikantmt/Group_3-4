#pragma once
#include <DxLib.h>
#include "../Input/Input.h"

const float FRAME_RATE = 60;
const float CHANGE_ANIME_TIME = 0.1f;
const int   ANIME_IMG_MAX = 6;			//アニメの枚数

//アニメの種類
enum EAnimeKind
{
	EAnimeKindWait, //待機アニメ
	EAnimeKindWalk,	//歩きアニメ
	EAnimeKindJump,	//ジャンプアニメ

	EAnimeKindNum,	//アニメ数
};

class cAnimation {
private:
	int	  Handle[EAnimeKindNum][ANIME_IMG_MAX];

	float AnimeTime;	//アニメ時間
	int   AnimeIndex;	//アニメ番号

	//各アニメの画像使用数
	int animeUsedNum[EAnimeKindNum];
public:
	//現在のアニメの種類
	EAnimeKind currentAnimeKind;

	void Init();
	void Set(EAnimeKind Anime);

	//左右移動とジャンプのある場合
	void Step(int Key1,int Key2,int Key3);
	//ジャンプのみの場合
	void Step(int Key1);
	void Draw(float X,float Y,float dif);
	void Fin();

	
};