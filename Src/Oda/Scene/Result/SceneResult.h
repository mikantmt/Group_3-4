#pragma once
#include "../../Scene/Scene.h"
#include "../../Score/Score.h"

// 画像パス
constexpr char RESULT_BG_PATH[128] = "../Data/ResultScene/ResultBG.png";
constexpr char RETURN_IMG_PATH[128] = "../Data/ResultScene/ReturnTitle.png";
constexpr char AGAIN_IMG_PATH[128] = "../Data/ResultScene/StartAgain.png";
constexpr char TROPHY_IMG_PATH[128] = "../Data/ResultScene/Trophy.png";

// 画像の大きさ
const int RETURN_IMG_SIZE_W = 350;
const int RETURN_IMG_SIZE_H = 70;

const int AGAIN_IMG_SIZE_W = 350;
const int AGAIN_IMG_SIZE_H = 70;

// フォントパス
constexpr char FONT_PATH[128] = "../Data/Font/Qarmic_sans_Abridged.ttf";

enum ResultImgHandle {
	RESULT_BACKGROUND,		// リザルト背景
	RESULT_RETURN,			// タイトルに戻る
	RESULT_AGAIN,			// もう一度
	RESULT_TROPHY,			// トロフィー

	RESULT_IMG_NUM			// 3
};

enum ResultSelect {
	RESULT_SELECT_IMG,		// 画像
	RESULT_SELECT_SCENE,	// シーン

	RESULT_SELECT_NUM		// 2
};

enum ResultImgSelect {
	RESULT_IMG_SELECT_RETURN,	// タイトルに戻る画像
	RESULT_IMG_SELECT_AGAIN,	// もう一度画像
	RESULT_IMG_SELECT_NOTHING,	// 画像なし

	RESULT_IMG_SELECT_NUM		// 3
};

enum ResultSceneSelect {
	RESULT_SCENE_SELECT_RETURN,	// タイトルに戻る
	RESULT_SCENE_SELECT_AGAIN,	// もう一度

	RESULT_SCENE_SELECT_NUM		// 2
};


class Result : public Scene {
private:
	// リザルト画像ハンドル
	int ResultImgHandle[RESULT_IMG_NUM];

	// セレクト変数
	int Select[RESULT_SELECT_NUM];

	// 透明度変数
	int Transparency;

	// フォントハンドル
	LPCSTR FontPath;

	//スコアフォント
	int FontScore;
	int FontHighScore;

	// 文字列の描画幅を取得
	int DrawScoreWidth;
	int DrawHighScoreWidth;

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

	// スコア描画処理
	void DrawScore();

	// タイトルに戻る処理
	void Return();

	// もう一度やる処理
	void Again();

	// セレクト変数処理
	void SelectProcessing();
};
