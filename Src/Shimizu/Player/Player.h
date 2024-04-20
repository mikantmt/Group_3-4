#pragma once
#include "DxLib.h"
#include "../Input/Input.h"
#include "../GameBase/MiniGameBase.h"

const float FRAME_RATE = 60;
const float CHANGE_ANIME_TIME = 0.1f;
const int   ANIME_IMG_MAX = 6;

#define GRAVITY		0.18f //重力
#define JUMPPOWER	1.0f  //ジャンプパワー

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH  32

//アニメの種類
enum EAnimeKind
{
	EAnimeKindWalk,	//歩きアニメ 0
	EAnimeKindJump,	//ジャンプアニメ 1

	EAnimeKindNum,		//アニメ数 2
};

class Player {
private:
	float Player_X;		//プレイヤーX座標
	float Player_Y;		//プレイヤーY座標
	float PlayerNext_X; //プレイヤー次座標
	float PlayerNext_Y; //プレイヤー次座標

	int	  Handle[EAnimeKindNum][ANIME_IMG_MAX];

	//現在のアニメの種類
	EAnimeKind currentAnimeKind;

	float AnimeTime;	//アニメ時間
	int   AnimeIndex;	//アニメ番号

	//各アニメの画像使用数
	int animeUsedNum[EAnimeKindNum];

	MiniGameBase gamebase;
	
public:
	float Yspeed;		//プレイヤーのYスピード
	float JumpCount;	//ジャンプしてからのフレーム
	bool  JumpFlg;		//初期値はfalse
	bool  ActiveFlg;	//生存フラグ
	bool  AirFlg;		//空中判定

	void Init();
	void Step();
	void Draw(float X);


	//座標の更新
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posX);
	void UpdatePos();

	// 移動後の座標を取得
	int GetNextPosX() { return (int)PlayerNext_X; }
	int GetNextPosY() { return (int)PlayerNext_Y; }

	// 現在の座標を取得
	float GetPosX() { return Player_X; }
	float GetPosY() { return Player_Y; }

	//プレイヤーの進んでいる方向を取得
	void GetMoveDirection(bool* _dirArray);
};