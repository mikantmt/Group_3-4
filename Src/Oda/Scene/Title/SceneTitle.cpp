#include "SceneTitle.h"

// タイトル初期化
void Title::Init()
{
	collision.Init();

	sound.Init();
	sound.Step(SOUND_TYPE_3, DX_PLAYTYPE_LOOP);

	Score::Read();

	// タイトル画像ハンドル
	TitleImgHandle[TITLE_BACKGROUND] = LoadGraph(TITLE_BG_PATH);
	TitleImgHandle[TITLE_START] = LoadGraph(START_IMG_PATH);
	TitleImgHandle[TITLE_QUIT] = LoadGraph(QUIT_IMG_PATH);
	TitleImgHandle[TITLE_UPDATE] = LoadGraph(UPDATE_IMG_PATH);

	// セレクト変数
	for (int SelectIndex = 0; SelectIndex < TITLE_SELECT_NUM; SelectIndex++)
	{
		Select[SelectIndex] = 0;
	}

	// 角度変数
	Angle = ANGLE_MINIMUM;

	// 回転判定
	isRotate = false;

	// 透明度変数
	Transparency = TRANSPARENCY_HALF;

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

	// セレクト変数処理
	SelectProcessing();

	// ハイスコア初期化
	Reset();
}

// タイトル描画処理
void Title::Draw()
{
	//透過処理
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_BlendAlpha);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// タイトル背景描画
	DrawGraph(0, 0, TitleImgHandle[TITLE_BACKGROUND], true);

	// 更新画像描画
	DrawRotaGraph(SCREEN_SIZE_X - 40, 40, 0.05f, Angle, TitleImgHandle[TITLE_UPDATE], true, false);

	// 選択描画処理
	DrawSelect();
}

// タイトル終了処理
void Title::Fin()
{
	// タイトル画像ハンドル
	for (int ImgIndex = 0; ImgIndex < TITLE_IMG_NUM; ImgIndex++)
	{
		DeleteGraph(TitleImgHandle[ImgIndex]);
	}

	sound.Fin();

	// 透明度変数
	Transparency = TRANSPARENCY_MINIMUM;

	// 角度変数
	Angle = ANGLE_MINIMUM;

	// 回転判定
	isRotate = false;
	
	// シーンセレクトが[はじめ]であれば
	if (Select[TITLE_SELECT_SCENE] == TITLE_SCENE_SELECT_START)
	{
		// セレクト変数
		for (int SelectIndex = 0; SelectIndex < TITLE_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// プレイシーンに遷移
		g_CurrentSceneId = SCENE_ID_INIT_PLAY;
	}
	// シーンセレクトが[おわり]であれば
	else if (Select[TITLE_SELECT_SCENE] == TITLE_SCENE_SELECT_QUIT)
	{
		// セレクト変数
		for (int SelectIndex = 0; SelectIndex < TITLE_SELECT_NUM; SelectIndex++)
		{
			Select[SelectIndex] = 0;
		}

		// ゲーム終了
		DxLib_End();
	}
}

// 選択描画処理
void Title::DrawSelect()
{
	// 画像セレクトが[はじめ]であれば
	if (Select[TITLE_SELECT_IMG] == TITLE_IMG_SELECT_START)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_START], true, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_CHANGE);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// 画像セレクトが[おわり]であれば
	else if (Select[TITLE_SELECT_IMG] == TITLE_IMG_SELECT_QUIT)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_QUIT], true, false);
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_CHANGE);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	// 画像セレクトが[画像なし]であれば
	else if (Select[TITLE_SELECT_IMG] == TITLE_IMG_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_CHANGE);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], true, false);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// スタート処理
void Title::Start() {
	// 画像セレクトを[はじめ]に変更
	Select[TITLE_SELECT_IMG] = TITLE_IMG_SELECT_START;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (START_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (START_IMG_SIZE_H / 2), START_IMG_SIZE_W, START_IMG_SIZE_H))
	{
		// シーンセレクトを[はじめ]に変更
		Select[TITLE_SELECT_SCENE] = TITLE_SCENE_SELECT_START;

		// タイトル終了シーンへ
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}


// ゲーム終了処理
void Title::QuitGame() {
	// 画像セレクトを[おわり]に変更
	Select[TITLE_SELECT_IMG] = TITLE_IMG_SELECT_QUIT;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (QUIT_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (QUIT_IMG_SIZE_H / 2), QUIT_IMG_SIZE_W, QUIT_IMG_SIZE_H))
	{
		// シーンセレクトを[おわり]に変更
		Select[TITLE_SELECT_SCENE] = TITLE_SCENE_SELECT_QUIT;

		// タイトル終了シーンへ
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

// セレクト変数処理
void Title::SelectProcessing() {
	if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (START_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (START_IMG_SIZE_H / 2), START_IMG_SIZE_W, START_IMG_SIZE_H))
	{
		// スタート処理
		Start();
	}
	else if (collision.RectToMousePointa((SCREEN_SIZE_X / 2) - (QUIT_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (QUIT_IMG_SIZE_H / 2), QUIT_IMG_SIZE_W, QUIT_IMG_SIZE_H))
	{
		// ゲーム終了処理
		QuitGame();
	}
	else
	{
		// 画像セレクトを[画像なし]に変更
		Select[TITLE_SELECT_IMG] = TITLE_IMG_SELECT_NOTHING;
	}
}

// ハイスコア初期化
void Title::Reset()
{
	// 画像をクリックしたら
	if (collision.IsClickOnRect(SCREEN_SIZE_X - 70, 10, 60, 60))
	{
		// ハイスコアを初期化
		Score::Reset();

		// 回転判定をtrue
		isRotate = true;
	}

	// 回転判定がtrueであれば
	if (isRotate == true) {
		// 画像を回転させる
		Angle -= 0.1f;
	}

	// 角度がマックスまで行ったら
	if (Angle < -ANGLE_MAX)
	{
		// 角度と回転判定を初期化
		isRotate = false;
		Angle = 0;
	}
}
