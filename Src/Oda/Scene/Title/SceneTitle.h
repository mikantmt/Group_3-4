#pragma once
#include "../../Scene/Scene.h"

// 画像パス
constexpr char TITLE_BG_PATH[128] = "../Data/TitleScene/TentativeTitleBG.png";
constexpr char START_IMG_PATH[128] = "../Data/TitleScene/Start.png";
constexpr char QUIT_IMG_PATH[128] = "../Data/TitleScene/QuitGame.png";

// 画像の大きさ
const int START_IMG_SIZE_W = 350;
const int START_IMG_SIZE_H = 70;

const int QUIT_IMG_SIZE_W = 350;
const int QUIT_IMG_SIZE_H = 70;

// 画像描画サイズ
static const float IMG_SIZE_SMALL = 0.9f;
static const float IMG_SIZE_BIG = 1.1f;

// 透明度
static const int TRANSPARENCY_MAX = 256;
static const int TRANSPARENCY_HALF = 128;
static const int TRANSPARENCY_MINIMUM = 0;

enum TitleImgHandle {
	TITLE_BACKGROUND,
	TITLE_START,
	TITLE_QUIT,

	TITLE_IMG_NUM,
};

enum TitleSelect {
	TITLE_SELECT_START,
	TITLE_SELECT_QUIT,
	TITLE_SELECT_NOTHING,

	TITLE_SELECT_NUM,
};

class Title : public Scene {
private:
	// タイトル画像ハンドル
	int TitleImgHandle[TITLE_IMG_NUM];

	// 画像サイズ
	float ImgSize[TITLE_SELECT_NUM];

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

	// スタート処理
	void Start();

	// ゲーム終了処理
	void QuitGame();

	// セレクト変数処理
	void SelectProcessing();
};

