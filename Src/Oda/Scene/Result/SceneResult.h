#pragma once
#include "../../Scene/Scene.h"

// 画像パス
constexpr char RESULT_BG_PATH[128] = "../Data/ResultScene/TentativeClearBG.png";
constexpr char RETURN_IMG_PATH[128] = "../Data/ResultScene/ReturnTitle.png";
constexpr char AGAIN_IMG_PATH[128] = "../Data/ResultScene/StartAgain.png";

enum ResultImgHandle {
	RESULT_BACKGROUND,
	RESULT_RETURN,
	RESULT_AGAIN,

	RESULT_IMG_NUM,
};

class Result : public Scene {
private:
	int ResultImgHandle[RESULT_IMG_NUM];		// リザルト画像ハンドル

public:
	Collision collision;

	//PressEnter透過変数
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;


	// タイトル初期化
	void Init();
	// タイトル通常処理
	void Step();
	// タイトル描画処理
	void Draw();
	// タイトル終了処理
	void Fin();
};
