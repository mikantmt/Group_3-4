#pragma once
#include "DxLib.h"

//サウンドの種類
enum SOUND_TYPE
{
	SOUND_TYPE_1 = 0,	
	SOUND_TYPE_2,
	SOUND_TYPE_3,
	SOUND_TYPE_JUMP,

	SOUND_TYPE_NUM,
};

class cSound {
private:

	//csvのファイルパス
	const char SoundPath[SOUND_TYPE_NUM][256] =
	{
		"../Data/BGM/Stage1.mp3",	//Sound1
		"../Data/BGM/Stage2.mp3",
		"../Data/BGM/TitleBGM.mp3",
		"../Data/BGM/Jump.mp3",
	};

	int Sound[SOUND_TYPE_NUM];

public:
	//LOOPの時はInit,Stepを同時に呼ぶ
	void Init();
	//サウンド再生(サウンドの種類,再生タイプ(ノーマル,バックグラウンド,ループ))
	void Step(SOUND_TYPE sound, int playtype);
	void Fin();
};