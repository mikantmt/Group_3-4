#pragma once
#include "../../Scene/Scene.h"
#include "../../../Shimizu/Player/Player.h"

class Play : public Scene {
private:
	Player player;
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