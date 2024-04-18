#pragma once
#include "../../Shimizu/Screen/Screen.h"
#include "../../Common.h"

class Screen {
private:
	//スクリーンのワールド座標
	float screenX = 0.0f;
	float screenY = 0.0f;

public:
	// スクリーンのステップ
	// 引数プレイヤーX座標、Y座標
	void StepScreen(float x, float y);

	//スクリーンのＸ座標を取得
	float GetScreenX();

	//スクリーンのＹ座標を取得
	float GetScreenY();
};