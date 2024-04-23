#include "ScenePlay.h"

// �v���C������
void Play::Init()
{
	player.Init();
	maps.Init();

	sound.Init();
	sound.Step(SOUND_TYPE_2, DX_PLAYTYPE_LOOP);

	// �X�R�A�̏�����
	Score::Init();

	BackGroundHandle = LoadGraph("../Data/PlayScene/BackGround.png");

	CarrotPoint = 0;

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

	if (player.ActiveFlg) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

// �v���C�`�揈��
void Play::Draw()
{
	DrawGraph(0, 0, BackGroundHandle, true);

	maps.Draw((int)screen.GetScreenX());

	player.Draw(screen.GetScreenX());
}

// �v���C�I������
void Play::Fin()
{
	sound.Fin();

	Score::Add(((int)player.GetPosX() / 16) + (CarrotPoint * 10));
	// �v���C�V�[���ɑJ��
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}

void Play::MapCollision() {
	// Y�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] != 0)
				continue;

			// ���������l����
			// �ǂ̕����ɐi��ł������`�F�b�N
			// ��Player�N���X�ɐi�ޕ������`�F�b�N����֐����������Ă��܂��B
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ���������l����
			// ��`�̓����蔻��p�̃f�[�^������
			// �v���C���[�̏��
			int Ax = (int)player.GetPosX();
			int Ay = (int)player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// �I�u�W�F�N�g�̏��
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ��Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
			Ay = (int)player.GetNextPosY();
			Ax = (int)player.GetPosX();

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
					player.AirFlg = false;
					player.Yspeed = 0.0f;
					player.JumpCount = 0.0f;
				}
			}
			else
				player.JumpFlg = true;
		}
	}

	// X�����̂ݓ����蔻����`�F�b�N����
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (maps.m_FileReadMapData[mapIndexY][mapIndexX] != 0)
				continue;

			// ���������l����
			// �ǂ̕����ɐi��ł������`�F�b�N
			// ��Player�N���X�ɐi�ޕ������`�F�b�N����֐����������Ă��܂��B
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ���������l����
			// ��`�̓����蔻��p�̃f�[�^������
			// �v���C���[�̏��
			int Ax = (int)player.GetPosX();
			int Ay = (int)player.GetPosY();
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

	//�΂˂Ƃ̓����蔻��
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			int Ax = (int)player.GetPosX();
			int Ay = (int)player.GetPosY();
			int Aw = PLAYER_WIDTH;
			int Ah = PLAYER_HEIGHT;

			// �I�u�W�F�N�g�̏��
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

			// �I�u�W�F�N�g�̏��
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