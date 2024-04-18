#include "DxLib.h"
#include "Score.h"

FILE* Score::fScore;

int Score::ScoreNum;			// スコアの値
int Score::HighScoreNum;	// ハイスコアの値

// スコアの初期化
void Score::Init()
{
	Score::ScoreNum = 0;
}

// ハイスコアの初期化
void Score::Reset()
{
	// ハイスコアにスコアを代入
	Score::HighScoreNum = 0;

	// ファイルを開く(ない場合は自動で新規作成する)
	errno_t err;
	err = fopen_s(&Score::fScore, "Data/Score/Score.txt", "w+");

	// ファイルが開けた・または新規作成できた
	if (Score::fScore != NULL)
	{
		// ファイルは閉じる
		fclose(Score::fScore);
	}
}

// スコアの加算
void Score::Add()
{
	Score::ScoreNum += ADD_SCORE_NUM;
}

// ハイスコアの更新
void Score::Update()
{
	// 保存されたハイスコアより大きかったら
	if (Score::ScoreNum > Score::HighScoreNum)
	{
		// ハイスコアにスコアを代入
		Score::HighScoreNum = Score::ScoreNum;

		// ファイルを開く(ない場合は自動で新規作成する)
		errno_t err;
		err = fopen_s(&Score::fScore, "Data/Score/Score.txt", "w+");

		// ファイルが開けた・または新規作成できた
		if (Score::fScore != NULL)
		{
			// ファイルは閉じる
			fclose(Score::fScore);
		}
	}
}