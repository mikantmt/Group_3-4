#include "Animation.h"

void cAnimation::Init() {
	Handle[EAnimeKindWalk][0] = LoadGraph("../Data/PlayScene/player/Rabbit1.png");
	Handle[EAnimeKindWalk][1] = LoadGraph("../Data/PlayScene/player/Rabbit2.png");
	animeUsedNum[EAnimeKindWalk] = 2;

	currentAnimeKind = EAnimeKindWalk;
	AnimeIndex = 0;
	AnimeTime = 0.0f;
}

void cAnimation::Set(EAnimeKind anime) {
	currentAnimeKind = anime;
}

void cAnimation::Step(int Key1, int Key2, int Key3) {
	if (IsButtonDown(Key1) || IsButtonDown(Key2)) {
		if (currentAnimeKind != EAnimeKindWalk) {
			currentAnimeKind = EAnimeKindWalk;
			AnimeIndex = 0;
			AnimeTime = 0.0f;
		}
	}
	else
	{
		if (currentAnimeKind != EAnimeKindWait) {
			currentAnimeKind = EAnimeKindWait;
			AnimeIndex = 0;
			AnimeTime = 0.0f;
		}
	}

	if (IsKeyKeep(Key3)) {
		if (currentAnimeKind != EAnimeKindJump) {
			currentAnimeKind = EAnimeKindJump;
			AnimeIndex = 0;
			AnimeTime = 0.0f;
		}
	}

	AnimeTime += 1.0f / FRAME_RATE;

	if (AnimeTime >= CHANGE_ANIME_TIME) {
		AnimeTime = 0.0f;	//リセット
		AnimeIndex++;		//アニメ番号を進める

		if (AnimeIndex >= animeUsedNum[currentAnimeKind]) {
			AnimeIndex = 0;
		}
	}
}

void cAnimation::Step(int Key1) {
	if (IsKeyKeep(Key1)) {
		if (currentAnimeKind != EAnimeKindJump) {
			currentAnimeKind = EAnimeKindJump;
			AnimeIndex = 0;
			AnimeTime = 0.0f;
		}
	}
	else
	{
		if (currentAnimeKind != EAnimeKindWalk) {
			currentAnimeKind = EAnimeKindWalk;
			AnimeIndex = 0;
			AnimeTime = 0.0f;
		}
	}

	AnimeTime += 1.0f / FRAME_RATE;

	if (AnimeTime >= CHANGE_ANIME_TIME) {
		AnimeTime = 0.0f;	//リセット
		AnimeIndex++;		//アニメ番号を進める

		if (AnimeIndex >= animeUsedNum[currentAnimeKind]) {
			AnimeIndex = 0;
		}
	}
}

void cAnimation::Draw(float X, float Y, float dif) {
	DrawGraph(X - dif, Y, Handle[currentAnimeKind][AnimeIndex], true);
}

void cAnimation::Fin() {
	for (int anime_kind_index = 0; anime_kind_index < EAnimeKindNum; anime_kind_index++){
		for (int image_index = 0; image_index < ANIME_IMG_MAX; image_index++){
			DeleteGraph(Handle[anime_kind_index][image_index]);
		}
	}
}