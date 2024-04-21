#include "SceneTitle.h"
#include "../../Score/Score.h"

// タイトル初期化
void Title::Init()
{
	// スコアの初期化
	Score::Init();

	collision.Init();

	// タイトル画像ハンドル
	TitleImgHandle[TITLE_BACKGROUND] = LoadGraph(TITLE_BG_PATH);
	TitleImgHandle[TITLE_START] = LoadGraph(START_IMG_PATH);
	TitleImgHandle[TITLE_QUIT] = LoadGraph(QUIT_IMG_PATH);

	// 画像サイズ
	for (int SizeIndex = 0; SizeIndex < TITLE_SELECT_NUM; SizeIndex++)
	{
		ImgSize[SizeIndex] = IMG_SIZE_SMALL;
	}

	// セレクト変数
	Select = TITLE_SELECT_NOTHING;

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
	DrawGraph(0, 0, TitleImgHandle[TITLE_BACKGROUND], true);

	// 選択描画処理
	DrawSelect();

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "タイトル");
}

// タイトル終了処理
void Title::Fin()
{
	// タイトル画像ハンドル
	for (int ImgIndex = 0; ImgIndex < TITLE_IMG_NUM; ImgIndex++)
	{
		DeleteGraph(TitleImgHandle[ImgIndex]);
	}
	
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}

// 選択描画処理
void Title::DrawSelect()
{
	if (Select == TITLE_SELECT_START)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_START], false, false);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == TITLE_SELECT_QUIT)
	{
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_BIG, 0.0f, TitleImgHandle[TITLE_QUIT], false, false);
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
	else if (Select == TITLE_SELECT_NOTHING)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, TRANSPARENCY_HALF);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 150, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_START], false, false);
		DrawRotaGraph(SCREEN_SIZE_X / 2, (SCREEN_SIZE_Y / 2) + 250, IMG_SIZE_SMALL, 0.0f, TitleImgHandle[TITLE_QUIT], false, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, TRANSPARENCY_MINIMUM);
	}
}

// スタート処理
void Title::Start() {
	// セレクトをStartに変更
	Select = TITLE_SELECT_START;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (START_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 150) - (START_IMG_SIZE_H / 2), START_IMG_SIZE_W, START_IMG_SIZE_H))
	{
		// タイトル終了シーンへ
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}


// ゲーム終了処理
void Title::QuitGame() {
	// セレクトをQuitに変更
	Select = TITLE_SELECT_QUIT;

	// 画像をクリックしたら
	if (collision.IsClickOnRect((SCREEN_SIZE_X / 2) - (QUIT_IMG_SIZE_W / 2), ((SCREEN_SIZE_Y / 2) + 250) - (QUIT_IMG_SIZE_H / 2), QUIT_IMG_SIZE_W, QUIT_IMG_SIZE_H))
	{
		// ゲーム終了
		DxLib_End();
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
		Select = TITLE_SELECT_NOTHING;
	}
}
