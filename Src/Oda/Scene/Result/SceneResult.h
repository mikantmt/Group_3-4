#pragma once
#include "../../Scene/Scene.h"
#include "../../Score/Score.h"

// 画像パス
constexpr char RESULT_BG_PATH[128] = "../Data/ResultScene/TentativeClearBG.png";
constexpr char RETURN_IMG_PATH[128] = "../Data/ResultScene/ReturnTitle.png";
constexpr char AGAIN_IMG_PATH[128] = "../Data/ResultScene/StartAgain.png";

// 画像の大きさ
const int RETURN_IMG_SIZE_W = 350;
const int RETURN_IMG_SIZE_H = 70;

const int AGAIN_IMG_SIZE_W = 350;
const int AGAIN_IMG_SIZE_H = 70;

enum ResultImgHandle {
	RESULT_BACKGROUND,
	RESULT_RETURN,
	RESULT_AGAIN,

	RESULT_IMG_NUM,
};

enum ResultSelect {
	RESULT_SELECT_RETURN,
	RESULT_SELECT_AGAIN,
	RESULT_SELECT_NOTHING,

	RESULT_SELECT_NUM,
};

class Result : public Scene {
private:
	// リザルト画像ハンドル
	int ResultImgHandle[RESULT_IMG_NUM];

	// セレクト変数
	int Select;

	// 透明度変数
	int Transparency;

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

	// 選択描画処理
	void DrawSelect();

	// タイトルに戻る処理
	void Return();

	// ゲーム終了処理
	void Again();

	// セレクト変数処理
	void SelectProcessing();
};
