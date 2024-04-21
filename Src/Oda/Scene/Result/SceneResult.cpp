#include "SceneResult.h"
#include "../../Score/Score.h"

// タイトル初期化
void Result::Init()
{
	// ハイスコアの更新
	Score::Update();

	// リザルト背景ハンドル
	ResultImgHandle[RESULT_BACKGROUND] = LoadGraph(RESULT_BG_PATH);

	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

// タイトル通常処理
void Result::Step()
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
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

// タイトル描画処理
void Result::Draw()
{
	//透過処理
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// リザルト背景描画
	DrawGraph(0, 0, ResultImgHandle[RESULT_BACKGROUND], true);

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "リザルト");
}

// タイトル終了処理
void Result::Fin()
{
	// リザルト画像ハンドル
	for (int ImgIndex = 0; ImgIndex < RESULT_IMG_NUM; ImgIndex++)
	{
		DeleteGraph(ResultImgHandle[ImgIndex]);
	}

	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
}