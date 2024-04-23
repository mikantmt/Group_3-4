#pragma once

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
	static void Add(int AddScoreNum);

	// ハイスコアの更新
	static void Update();

	//ハイスコアの読み込み
	static void Read();
};
