#include "SceneTitle.h"
#include "../../Score/Score.h"

// タイトル初期化
void Title::Init()
{
	// スコアの初期化
	Score::Init();

	// タイトル背景ハンドル
	TitleBGHandle = LoadGraph(TITLE_BG_PATH);

	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

// タイトル通常処理
void Title::Step()
{

	if (m_blendfrag){
		m_BlendAlpha+=3;
	}
	else{
		m_BlendAlpha-=3;
	}

	if (m_BlendAlpha < 0){
		m_blendfrag = true;
	}
	if (m_BlendAlpha > 255){
		m_blendfrag = false;
	}

	if (IsKeyPush(KEY_INPUT_A)) {
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// タイトル描画処理
void Title::Draw()
{
	//透過処理
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// タイトル背景描画
	DrawGraph(0, 0, TitleBGHandle, true);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "タイトル");
}

// タイトル終了処理
void Title::Fin()
{
	// タイトル背景ハンドル
	DeleteGraph(TitleBGHandle);
	
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}