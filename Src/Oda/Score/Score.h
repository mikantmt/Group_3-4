#pragma once

// スコアの加算数
const int ADD_SCORE_NUM = 1;

class Score {
public:
	static FILE* fScore;

	static int ScoreNum;		// スコアの値
	static int HighScoreNum;	// ハイスコアの値

	// スコアの初期化
	static void Init();

	// ハイスコアの初期化
	static void Reset();

	// スコアの加算
	static void Add();

	// ハイスコアの更新
	static void Update();
};
