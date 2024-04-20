#pragma once
// フレームレート情報
class FrameRateInfo
{
public:
	int currentTime;	// 現在の時間
	int lastFrameTime;	// 前回のフレーム実行時間
	int count;			// フレームカウント用
	int calcFpsTime;	// FPSを計算した時間
	float fps;			// 計測したFPS(表示用)

	void CalcFPS();

	void DrawFPS();
};