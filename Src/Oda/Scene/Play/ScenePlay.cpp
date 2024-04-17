#include "ScenePlay.h"

// プレイ初期化
void Play::Init()
{
	player.Init();
	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// プレイ通常処理
void Play::Step()
{
	player.Player_Move();

	if (IsKeyPush(KEY_INPUT_A)) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// プレイ描画処理
void Play::Draw()
{
	player.Draw();

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "プレイ");
}

// プレイ終了処理
void Play::Fin()
{
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}