#pragma once

class Score {
public:
	static FILE* fScore;

	static int ScoreNum;		// �X�R�A�̒l
	static int HighScoreNum;	// �n�C�X�R�A�̒l

	// �X�R�A�̏�����
	static void Init();

	// �n�C�X�R�A�̏�����
	static void Reset();

	// �X�R�A�̉��Z
	static void Add(int AddScoreNum);

	// �n�C�X�R�A�̍X�V
	static void Update();

	//�n�C�X�R�A�̓ǂݍ���
	static void Read();
};
