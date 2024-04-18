#pragma once
#include "../../Scene/Scene.h"

// タイトルの背景パス
constexpr char TITLE_BG_PATH[128] = "../Data/TitleScene/TentativeTitleBG.png";

class Title : public Scene {
private:
	int TitleBGHandle;		// タイトル背景ハンドル

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

