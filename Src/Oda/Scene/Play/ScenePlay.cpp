#include "ScenePlay.h"

// タイトル初期化
void Play::Init()
{
	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// タイトル通常処理
void Play::Step()
{

	if (m_blendfrag) {
		m_BlendAlpha += 3;
	}
	else {
		m_BlendAlpha -= 3;
	}

	if (m_BlendAlpha < 0) {
		m_blendfrag = true;
	}
	if (m_BlendAlpha > 255) {
		m_blendfrag = false;
	}

	if (IsKeyPush(KEY_INPUT_A)) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// タイトル描画処理
void Play::Draw()
{
	//透過処理
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "プレイ");
}

// タイトル終了処理
void Play::Fin()
{
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}