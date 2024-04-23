#include "DxLib.h"
#include "Score.h"

FILE* Score::fScore;

int Score::ScoreNum;			// �X�R�A�̒l
int Score::HighScoreNum;	// �n�C�X�R�A�̒l

// �X�R�A�̏�����
void Score::Init()
{
	Score::ScoreNum = 0;
}

// �n�C�X�R�A�̏�����
void Score::Reset()
{
	// �n�C�X�R�A�ɃX�R�A����
	Score::HighScoreNum = 0;

	// �t�@�C�����J��(�Ȃ��ꍇ�͎����ŐV�K�쐬����)
	errno_t err;
	err = fopen_s(&Score::fScore, "../Data/Score/Score.txt", "w+");

	// �t�@�C�����J�����E�܂��͐V�K�쐬�ł���
	if (Score::fScore != NULL)
	{
		// �t�@�C���͕���
		fclose(Score::fScore);
	}
}

// �X�R�A�̉��Z
void Score::Add(int AddScoreNum)
{
	Score::ScoreNum += AddScoreNum;
}

// �n�C�X�R�A�̍X�V
void Score::Update()
{
	// �ۑ����ꂽ�n�C�X�R�A���傫��������
	if (Score::ScoreNum > Score::HighScoreNum)
	{
		// �n�C�X�R�A�ɃX�R�A����
		Score::HighScoreNum = Score::ScoreNum;

		// �t�@�C�����J��(�Ȃ��ꍇ�͎����ŐV�K�쐬����)
		errno_t err;
		err = fopen_s(&Score::fScore, "../Data/Score/Score.txt", "w+");

		// �t�@�C�����J�����E�܂��͐V�K�쐬�ł���
		if (Score::fScore != NULL)
		{
			fprintf(fScore, "%d", HighScoreNum);

			// �t�@�C���͕���
			fclose(Score::fScore);
		}
	}
}

void Score::Read() {
	errno_t err;
	err = fopen_s(&Score::fScore, "../Data/Score/Score.txt", "r");

	if (Score::fScore != NULL)
	{
		fscanf_s(fScore, "%d", &HighScoreNum);

		// �t�@�C���͕���
		fclose(Score::fScore);
	}
}