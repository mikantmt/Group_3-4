#include "Player.h"

void Player::Init() {
	Player_X = 160.0f;
	Player_Y = SCREEN_SIZE_Y - 300;
	Yspeed   = 0.0f;
	JumpCount = 0.0f;

	ActiveFlg = false;
	JumpFlg   = false;
	AirFlg    = false;

	anime.Init();

	gamebase.Init();
}

void Player::Step() {
	PlayerNext_X = Player_X;
	PlayerNext_Y = Player_Y;

	PlayerNext_X+=2;

	//ジャンプ処理==============================
	Yspeed += GRAVITY;
	PlayerNext_Y += Yspeed;

	//スペースキーが押されている && JumpCountが6以下
	if (IsKeyKeep(KEY_INPUT_SPACE) && JumpCount < 6 && !AirFlg) {
		JumpFlg = true;
		JumpCount++;
	}

	if (JumpFlg) {
		PlayerNext_Y -= (JUMPPOWER * JumpCount);
	}

	//==========================================
	
	//アニメーション処理==============================
	anime.Step(KEY_INPUT_SPACE);
	//================================================

	//スクリーンより下に行けばゲームオーバー
	if (SCREEN_SIZE_Y < Player_Y) {
		ActiveFlg = true;
	}
}

void Player::Draw(float X) {
	anime.Draw(Player_X, Player_Y, X);
	DrawBox(Player_X - X, Player_Y, Player_X + PLAYER_WIDTH - X, Player_Y + PLAYER_HEIGHT, GetColor(255, 0, 0), false);
}


void Player::SetNextPosX(int _posX) {
	PlayerNext_X = (float)_posX;
}

void Player::SetNextPosY(int _posY) {
	PlayerNext_Y = (float)_posY;
}

void Player::UpdatePos() {
	Player_X = PlayerNext_X;
	Player_Y = PlayerNext_Y;
}

void Player::GetMoveDirection(bool* _dirArray) {
	// 右方向のチェック
	if (PlayerNext_X > Player_X) {
		_dirArray[3] = true;
	}

	// 左方向のチェック
	if (PlayerNext_X < Player_X) {
		_dirArray[2] = true;
	}

	// 下方向のチェック
	if (PlayerNext_Y > Player_Y) {
		_dirArray[1] = true;
	}

	// 上方向のチェック
	if (PlayerNext_Y < Player_Y) {
		_dirArray[0] = true;
	}
}


