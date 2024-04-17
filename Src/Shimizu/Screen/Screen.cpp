#include "DxLib.h"
#include "Screen.h"

void Screen::StepScreen(float x, float y, int MAP_X_SIZE)
{
	//自機が中心になるように、
	//スクリーン座標を設定
	if (x < MAPCIP_X_SIZE * 4) {
		screenX = 0;
	}
	else if (x > MAP_X_SIZE - MAPCIP_X_SIZE * 16) {
		screenX = (float)MAP_X_SIZE - MAPCIP_X_SIZE * 20;
	}
	else {
		screenX = x - MAPCIP_X_SIZE * 4;
	}
}

float Screen::GetScreenX()
{
	return screenX;
}

float Screen::GetScreenY()
{
	return screenY;
}
