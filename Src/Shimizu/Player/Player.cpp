#include "Player.h"

void Player::Init() {
	Player_X = 0.0f;
	Player_Y = 0.0f;
	Yspeed   = 0.0f;

	JumpFlg = false;
}

void Player::Player_Move() {
	//移動処理
	Player_X++;

	//ジャンプ処理==============================
	Yspeed += GRAVITY;
	Player_Y += Yspeed;

	if (IsKeyPush(KEY_INPUT_SPACE)) {
		JumpFlg = true;
	}

	if (JumpFlg) {
		Player_Y -= JUMPPOWER;
	}

	//ここは仮置き
	if (Player_Y > 750.0f) {
		Player_Y = 750.0f;
		JumpFlg = false;
		Yspeed = 0.0f;
	}
	//==========================================
	
}

void Player::Draw() {
	DrawFormatString(Player_X, Player_Y, GetColor(255, 0, 0), "*");
}