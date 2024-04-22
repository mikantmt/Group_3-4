#pragma once

#define SCREEN_SIZE_X 1280	//画面サイズ 横
#define SCREEN_SIZE_Y 800	//画面サイズ 縦

// 画像描画サイズ
static const float IMG_SIZE_SMALL = 1.0f;
static const float IMG_SIZE_BIG = 1.2f;

// 透明度
static const int TRANSPARENCY_MAX = 256;
static const int TRANSPARENCY_HALF = 128;
static const int TRANSPARENCY_MINIMUM = 0;

// 角度
static const double PI = 3.1415926535897;
static const float ANGLE_MAX = 180.0f * (float)PI / 180.0f;
static const float ANGLE_HALF = 90.0f * (float)PI / 180.0f;
static const float ANGLE_MINIMUM = 0.0f * (float)PI / 180.0f;
