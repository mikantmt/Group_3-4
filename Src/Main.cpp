//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include "../Src/Common.h"
#include "../Src/Shimizu/Input/Input.h"
#include "../Src/Oda/Scene/Scene.h"
#include "../Src/Oda/Scene/Title/SceneTitle.h"
#include "../Src/Oda/Scene/Play/ScenePlay.h"
#include "../Src/Oda/Scene/Result/SceneResult.h"


//extern宣言
SCENE_ID g_CurrentSceneId = SCENE_ID_INIT_TITLE;

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く

	//クラス宣言
	Scene* Scene = nullptr;

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}

		//画面に表示されたものを初期化
		ClearDrawScreen();

		StepInput();

		switch (g_CurrentSceneId)
		{

		case SCENE_ID_INIT_TITLE:

			Scene = new Title;
			if (Scene) {
				Scene->Init();
			}

			break;
		case SCENE_ID_LOOP_TITLE:
			
			if (Scene) {
				Scene->Step();
				Scene->Draw();
			}

			
			break;
		case SCENE_ID_FIN_TITLE:
			if (Scene) {
				Scene->Fin();
				delete Scene;
				Scene = nullptr;
			}
			break;

		case SCENE_ID_INIT_PLAY:

			Scene = new Play;
			if (Scene) {
				Scene->Init();
			}

			break;
		case SCENE_ID_LOOP_PLAY:

			if (Scene) {
				Scene->Step();
				Scene->Draw();
			}


			break;
		case SCENE_ID_FIN_PLAY:
			if (Scene) {
				Scene->Fin();
				delete Scene;
				Scene = nullptr;
			}
			break;

		case SCENE_ID_INIT_RESULT:

			Scene = new Result;
			if (Scene) {
				Scene->Init();
			}

			break;
		case SCENE_ID_LOOP_RESULT:

			if (Scene) {
				Scene->Step();
				Scene->Draw();
			}


			break;
		case SCENE_ID_FIN_RESULT:
			if (Scene) {
				Scene->Fin();
				delete Scene;
				Scene = nullptr;
			}
			break;
		default:
			break;
		}

		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------

		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

