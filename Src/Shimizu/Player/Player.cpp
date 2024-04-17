#include "Player.h"

void Player::Init() {
	Player_X = 0.0f;
	Player_Y = 0.0f;
	Yspeed   = 0.0f;

	JumpFlg = false;
}

void Player::Step() {
	PlayerNext_X = Player_X;
	PlayerNext_Y = Player_Y;

	//�ړ�����
	PlayerNext_X++;

	//�W�����v����==============================
	Yspeed += GRAVITY;
	PlayerNext_Y += Yspeed;

	if (IsKeyPush(KEY_INPUT_SPACE)) {
		JumpFlg = true;
	}

	if (JumpFlg) {
		PlayerNext_Y -= JUMPPOWER;
	}
}

void Player::Draw() {
	DrawBox(Player_X, Player_Y, Player_X + PLAYER_WIDTH, Player_Y + PLAYER_HEIGHT, GetColor(255, 0, 0), false);
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
	// �E�����̃`�F�b�N
	if (PlayerNext_X > Player_X) {
		_dirArray[3] = true;
	}

	// �������̃`�F�b�N
	if (PlayerNext_X < Player_X) {
		_dirArray[2] = true;
	}

	// �������̃`�F�b�N
	if (PlayerNext_Y > Player_Y) {
		_dirArray[1] = true;
	}

	// ������̃`�F�b�N
	if (PlayerNext_Y < Player_Y) {
		_dirArray[0] = true;
	}
}


