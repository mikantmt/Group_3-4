#pragma once
#include "DxLib.h"
#include "../Input/Input.h"

#define GRAVITY		0.15f //重力
#define JUMPPOWER	3.6f  //ジャンプパワー

#define PLAYER_HEIGHT 64
#define PLAYER_WIDTH  32

class Player {
private:
	float Player_X;		//プレイヤーX座標
	float Player_Y;		//プレイヤーY座標
	float PlayerNext_X; //プレイヤー次座標
	float PlayerNext_Y; //プレイヤー次座標
	
public:

	float Yspeed;		//プレイヤーのYスピード

	bool  JumpFlg;		//初期値はfalse

	void Init();
	void Step();
	void Draw();


	//座標の更新
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posX);
	void UpdatePos();

	// 移動後の座標を取得
	int GetNextPosX() { return (int)PlayerNext_X; }
	int GetNextPosY() { return (int)PlayerNext_Y; }

	// 現在の座標を取得
	int GetPosX() { return (int)Player_X; }
	int GetPosY() { return (int)Player_Y; }

	//プレイヤーの進んでいる方向を取得
	void GetMoveDirection(bool* _dirArray);
};