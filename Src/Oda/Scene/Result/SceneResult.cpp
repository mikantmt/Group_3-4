#include "SceneResult.h"

// タイトル初期化
void Result::Init()
{
	// ハイスコアの更新
	Score::Update();

	// リザルト背景ハンドル
	ResultImgHandle[RESULT_BACKGROUND] = LoadGraph(RESULT_BG_PATH);
	ResultImgHandle[RESULT_RETURN] = LoadGraph(RETURN_IMG_PATH);
	ResultImgHandle[RESULT_AGAIN] = LoadGraph(AGAIN_IMG_PATH);

	// セレクト変数
	Select = RESULT_SELECT_NOTHING;

	// 透明度変数
	Transparency = TRANSPARENCY_HALF;

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

	SelectProcessing();
}

// タイトル描画処理
void Result::Draw()
{
	//透過処理
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// リザルト背景描画
	DrawGraph(0, 0, ResultImgHandle[RESULT_BACKGROUND], true);

	// 選択描画処理
	DrawSelect();
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

// 選択描画処理
void Result::DrawSelect()
{
	if (Select == RESULT_SELECT_RETURN)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == RESULT_SELECT_AGAIN)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == RESULT_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// スタート処理
void Result::Return() {
	// セレクトをStartに変更
	Select = RESULT_SELECT_RETURN;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// リザルト終了シーンへ
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}


// ゲーム終了処理
void Result::Again() {
	// セレクトをQuitに変更
	Select = RESULT_SELECT_AGAIN;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// ゲーム終了
		DxLib_End();
	}
}

// セレクト変数処理
void Result::SelectProcessing() {
	if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// スタート処理
		Return();
	}
	else if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// ゲーム終了処理
		Again();
	}
	else
	{
		Select = RESULT_SELECT_NOTHING;
	}
}
