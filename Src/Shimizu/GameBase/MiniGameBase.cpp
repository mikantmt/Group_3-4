#include "MiniGameBase.h"

void MiniGameBase::Init() {
	IsFin = false;
	IsClear = false;
	GamePoint = 0;
	Handle[0] = LoadGraph("../Data/PlayScene/start/one.png");
	Handle[1] = LoadGraph("../Data/PlayScene/start/two.png");
	Handle[2] = LoadGraph("../Data/PlayScene/start/three.png");
	Handle[3] = LoadGraph("../Data/PlayScene/start/start.png");
}

void MiniGameBase::Play() {
	
}

void MiniGameBase::Draw() {

}

void MiniGameBase::Fin() {

}

void MiniGameBase::CountDown(float limit) {
	//3,2,1のカウントダウン
	if (limit <= LimitTime && limit > LimitTime - _1Frame) {							//3
		DrawGraph(SCREEN_SIZE_X / 2 - 50, SCREEN_SIZE_Y / 2 - 50, Handle[2], true);
	}
	if (limit <= LimitTime - _1Frame && limit > LimitTime - (_1Frame * 2)) {			//2
		DrawGraph(SCREEN_SIZE_X / 2 - 50, SCREEN_SIZE_Y / 2 - 50, Handle[1], true);
	}
	if (limit <= LimitTime - (_1Frame * 2) && limit > LimitTime - (_1Frame * 3)) {		//1
		DrawGraph(SCREEN_SIZE_X / 2 - 50, SCREEN_SIZE_Y / 2 - 50, Handle[0], true);
	}
	if (limit <= LimitTime - (_1Frame * 3) && limit > 0) {								//start
		DrawGraph(SCREEN_SIZE_X / 2 - 250, SCREEN_SIZE_Y / 2 - 250, Handle[3], true);
	}
}

float MiniGameBase::ScopingRand(float min, float max) {
	float rand;

	rand = GetRand((float)max);

	if (rand < min) {
		return ScopingRand(min, max);
	}
	else
		return rand;
}

float MiniGameBase::OutRand(float min, float max, float out_min, float out_max) {
	float rand;

	rand = ScopingRand(min, max);

	if (rand > out_min && rand < out_max) {
		return OutRand(min, max,out_min,out_max);
	}
	else
		return rand;

}