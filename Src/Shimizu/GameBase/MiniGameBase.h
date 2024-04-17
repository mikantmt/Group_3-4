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
	bool  IsFin;					//ゲーム終了フラグ(初期値はfalse)
	bool  IsClear;					//ゲームクリアフラグ(初期値はfalse)
	float Startlimit;				//開始までのカウントダウン
	int   GamePoint;				//そのゲームの得点
	int	  Handle[COUNT_NUM];		//カウントダウン画像

	void  CountDown(float limit);	//カウントダウンの関数(210を固定)

	//範囲指定できる乱数の関数(下限,上限)
	float ScopingRand(float min, float max);

	//指定範囲を除外できる乱数の関数(下限,上限,除外したい下限,除外したい上限)
	float OutRand(float min, float max,float out_min,float out_max);

	/*void ResetGame();*/

private:

public:
	void Init();
	void Play();
	void Draw();
	void Fin();
};