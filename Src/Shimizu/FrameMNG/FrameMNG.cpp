#include "DxLib.h"
#include "FrameMNG.h"


void FrameRateInfo::CalcFPS()
{
	// 前回のFPSを計算した時間からの経過時間を求める
	int difTime = currentTime - calcFpsTime;

	// 前回のFPSを計算した時間から
	// 1秒以上経過していたらFPSを計算する
	if (difTime > 1000) {
		// フレーム回数をミリ秒に合わせる
		// 小数まで出したいのでfloatにキャスト
		float frameCount = (float)(count * 1000.0f);

		// FPSを求める
		// 理想の数値は60000/1000で60となる
		fps = frameCount / difTime;

		// フレームレートカウントをクリア
		count = 0;

		// FPSを計算した時間を更新
		calcFpsTime = currentTime;
	}
}

void FrameRateInfo::DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(1180, 704, color, "FPS[%.2f]", fps);
}