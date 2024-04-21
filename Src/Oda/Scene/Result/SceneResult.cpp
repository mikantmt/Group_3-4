#include "SceneResult.h"

// タイトル初期化
void Result::Init()
{
	// ハイスコアの更新
	Score::Update();

	sound.Init();
	sound.Step(SOUND_TYPE_1, DX_PLAYTYPE_LOOP);

	// リザルト背景ハンドル
	ResultImgHandle[RESULT_BACKGROUND] = LoadGraph(RESULT_BG_PATH);
	ResultImgHandle[RESULT_RETURN] = LoadGraph(RETURN_IMG_PATH);
	ResultImgHandle[RESULT_AGAIN] = LoadGraph(AGAIN_IMG_PATH);

	// セレクト変数
	for (int SelectIndex = 0; SelectIndex < RESULT_SELECT_NUM; SelectIndex++)
	{
		Select[SelectIndex] = 0;
	}

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

	sound.Fin();

	// 透明度変数
	Transparency = 0;

	// シーンセレクトが[タイトルに戻る]であれば
	if (Select[RESULT_SELECT_SCENE] == RESULT_SCENE_SELECT_RETURN)
	{
		// セレクト変数
		for (int SelectIndex = 0; SelectIndex < RESULT_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// プレイシーンに遷移
		g_CurrentSceneId = SCENE_ID_INIT_TITLE;
	}
	// シーンセレクトが[もう一度]であれば
	else if (Select[RESULT_SELECT_SCENE] == RESULT_SCENE_SELECT_AGAIN)
	{
		// セレクト変数
		for (int SelectIndex = 0; SelectIndex < RESULT_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// プレイシーンに遷移
		g_CurrentSceneId = SCENE_ID_INIT_PLAY;
	}
}

// 選択描画処理
void Result::DrawSelect()
{
	// 画像セレクトが[タイトルに戻る]であれば
	if (Select[RESULT_SELECT_IMG] == RESULT_IMG_SELECT_RETURN)
	{
		DrawRotaGraph(SCREEN_SIZE_X * 3 / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// 画像セレクトが[もう一度]であれば
	else if (Select[RESULT_SELECT_IMG] == RESULT_IMG_SELECT_AGAIN)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_BIG, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X * 3 / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// 画像セレクトが[画像なし]であれば
	else if (Select[RESULT_SELECT_IMG] == RESULT_IMG_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X * 3 / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_RETURN], false, false);
		DrawRotaGraph(SCREEN_SIZE_X / 4, (SCREEN_SIZE_Y / 2) + 200, IMG_SIZE_SMALL, 0.0f, ResultImgHandle[RESULT_AGAIN], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// タイトルに戻る処理
void Result::Return() {
	// 画像セレクトを[タイトルに戻る画像]に変更
	Select[RESULT_SELECT_IMG] = RESULT_IMG_SELECT_RETURN;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X * 3 / 4) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// シーンセレクトを[タイトルに戻る]に変更
		Select[RESULT_SELECT_SCENE] = RESULT_SCENE_SELECT_RETURN;

		// リザルト終了シーンへ
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}


// もう一度やる処理
void Result::Again() {
	// 画像セレクトを[もう一度画像]に変更
	Select[RESULT_SELECT_IMG] = RESULT_IMG_SELECT_AGAIN;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 4) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// シーンセレクトを[もう一度]に変更
		Select[RESULT_SELECT_SCENE] = RESULT_SCENE_SELECT_AGAIN;

		// リザルト終了シーンへ
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

// セレクト変数処理
void Result::SelectProcessing() {
	if (collision.RectToMousePointa((SCREEN_SIZE_X * 3 / 4) - (RETURN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (RETURN_IMG_SIZE_H / 2), RETURN_IMG_SIZE_W, RETURN_IMG_SIZE_H))
	{
		// タイトルに戻る処理
		Return();
	}
	else if (collision.RectToMousePointa((SCREEN_SIZE_X / 4) - (AGAIN_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 200) - (AGAIN_IMG_SIZE_H / 2), AGAIN_IMG_SIZE_W, AGAIN_IMG_SIZE_H))
	{
		// もう一度やる処理
		Again();
	}
	else
	{
		// 画像セレクトを[画像なし]に変更
		Select[RESULT_SELECT_IMG] = RESULT_IMG_SELECT_NOTHING;
	}
}
