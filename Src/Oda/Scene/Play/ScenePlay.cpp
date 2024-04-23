#include "ScenePlay.h"

// プレイ初期化
void Play::Init()
{
	player.Init();
	maps.Init();

	sound.Init();
	sound.Step(SOUND_TYPE_2, DX_PLAYTYPE_LOOP);

	// スコアの初期化
	Score::Init();

	BackGroundHandle = LoadGraph("../Data/PlayScene/BackGround.png");

	CarrotPoint = 0;

	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// プレイ通常処理
void Play::Step()
{
	screen.StepScreen(player.GetPosX(), player.GetPosY());

	player.Step();

	MapCollision();

	player.UpdatePos();

	if (player.ActiveFlg) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// プレイ描画処理
void Play::Draw()
{
	DrawGraph(0, 0, BackGroundHandle, true);

	maps.Draw((int)screen.GetScreenX());

	player.Draw(screen.GetScreenX());
}

// プレイ終了処理
void Play::Fin()
{
	sound.Fin();

	Score::Add(((int)player.GetPosX() / 16) + (CarrotPoint * 10));
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}

void Play::MapCollision() {
	// Y方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] != 0)
				continue;

			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			int Ax = (int)player.GetPosX();
			int Ay = (int)player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// オブジェクトの情報
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ※Y方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = (int)player.GetNextPosY();
			Ax = (int)player.GetPosX();

			// 当たっているかチェック
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
				// 上方向の修正
				if (dirArray[0]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = By + Bh - Ay;
					player.SetNextPosY(Ay + overlap);
				}

				// 下方向の修正
				if (dirArray[1]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = Ay + Ah - By;
					player.SetNextPosY(Ay - overlap);
					player.JumpFlg = false;
					player.AirFlg = false;
					player.Yspeed = 0.0f;
					player.JumpCount = 0.0f;
				}
			}
			else
				player.JumpFlg = true;
		}
	}

	// X方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] != 0)
				continue;

			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			int Ax = (int)player.GetPosX();
			int Ay = (int)player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// オブジェクトの情報
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ※X方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = player.GetNextPosY();
			Ax = player.GetNextPosX();

			// 当たっているかチェック
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
				// 左方向の修正
				if (dirArray[2]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = Bx + Bw - Ax;
					player.SetNextPosX(Ax + overlap);
				}

				// 右方向の修正
				if (dirArray[3]) {
					// ★ここを考える
					// めり込み量を計算する
					int overlap = Ax + Aw - Bx;
					player.SetNextPosX(Ax - overlap);
				}
			}
		}
	}

	//ばねとの当たり判定
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			int Ax = (int)player.GetPosX();
			int Ay = (int)player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// オブジェクトの情報
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] == 2) {
				if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
					player.JumpFlg = false;
					player.AirFlg = false;
					player.Yspeed = 0.0f;
					player.JumpCount = 0.0f;

					player.Yspeed = player.Yspeed - 3.0f;
				}
			}
		}
	}

	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			int Ax = (int)player.GetPosX();
			int Ay = (int)player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// オブジェクトの情報
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] == 3) {
				if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
					maps.m_FileReadMapData[mapIndexY][mapIndexX] = -1;
					CarrotPoint += 1;
				}
			}
		}
	}

	if (collision.IsHitRect(9568, 0, 32, SCREEN_SIZE_Y, (int)player.GetPosX(), (int)player.GetPosY(), 32, 64)) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}