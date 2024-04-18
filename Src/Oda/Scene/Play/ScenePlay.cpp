#include "ScenePlay.h"

// �v���C������
void Play::Init()
{
	player.Init();

	maps.Init();
	// �^�C�g���̃��[�v�����֑J��
	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

// �v���C�ʏ폈��
void Play::Step()
{
	screen.StepScreen(player.GetPosX(), player.GetPosY());

	player.Step();

	MapCollision();

	player.UpdatePos();

	if (IsKeyPush(KEY_INPUT_A)) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// �v���C�`�揈��
void Play::Draw()
{
	maps.Draw(screen.GetScreenX());

	player.Draw(screen.GetScreenX());

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 255, 0), "�v���C");
}

// �v���C�I������
void Play::Fin()
{
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}

void Play::MapCollision() {
	// Y�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] == -1)
				continue;

			// ���������l����
			// �ǂ̕����ɐi��ł������`�F�b�N
			// ��Player�N���X�ɐi�ޕ������`�F�b�N����֐����������Ă��܂��B
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ���������l����
			// ��`�̓����蔻��p�̃f�[�^������
			// �v���C���[�̏��
			int Ax = player.GetPosX();
			int Ay = player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// �I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ��Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
			Ay = player.GetNextPosY();
			Ax = player.GetPosX();

			// �������Ă��邩�`�F�b�N
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
				// ������̏C��
				if (dirArray[0]) {
					// ���������l����
					// �߂荞�ݗʂ��v�Z����
					int overlap = By + Bh - Ay;
					player.SetNextPosY(Ay + overlap);
				}

				// �������̏C��
				if (dirArray[1]) {
					// ���������l����
					// �߂荞�ݗʂ��v�Z����
					int overlap = Ay + Ah - By;
					player.SetNextPosY(Ay - overlap);
					player.JumpFlg = false;
					player.Yspeed = 0.0f;
				}
			}
		}
	}

	// X�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] == -1)
				continue;

			// ���������l����
			// �ǂ̕����ɐi��ł������`�F�b�N
			// ��Player�N���X�ɐi�ޕ������`�F�b�N����֐����������Ă��܂��B
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ���������l����
			// ��`�̓����蔻��p�̃f�[�^������
			// �v���C���[�̏��
			int Ax = player.GetPosX();
			int Ay = player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// �I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ��X�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
			Ay = player.GetNextPosY();
			Ax = player.GetNextPosX();

			// �������Ă��邩�`�F�b�N
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
				// �������̏C��
				if (dirArray[2]) {
					// ���������l����
					// �߂荞�ݗʂ��v�Z����
					int overlap = Bx + Bw - Ax;
					player.SetNextPosX(Ax + overlap);
				}

				// �E�����̏C��
				if (dirArray[3]) {
					// ���������l����
					// �߂荞�ݗʂ��v�Z����
					int overlap = Ax + Aw - Bx;
					player.SetNextPosX(Ax - overlap);
				}
			}
		}
	}
}