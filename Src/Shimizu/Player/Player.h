#pragma once
#include "DxLib.h"
#include "../Input/Input.h"

#define GRAVITY		0.15f //重力
#define JUMPPOWER	3.6f  //ジャンプパワー

class Player {
private:
	float Player_X;		//プレイヤーX座標
	float Player_Y;		//プレイヤーY座標
	float PlayerNext_X; //プレイヤー次座標
	float PlayerNext_Y; //プレイヤー次座標
	float Yspeed;		//プレイヤーのYスピード

	bool  JumpFlg;		//初期値はfalse
public:

	void Init();
	void Player_Move();
	void Draw();
};