#include "Sound.h"

void cSound::Init() {
	for (int i = 0; i < SOUND_TYPE_NUM; i++) {
		Sound[i] = LoadSoundMem(SoundPath[i]);
	}
}

void cSound::Step(SOUND_TYPE sound,int playtype) {
	PlaySoundMem(Sound[sound], playtype);
}

void cSound::Fin() {
	for (int i = 0; i < SOUND_TYPE_NUM; i++) {
		DeleteSoundMem(Sound[i]);
	}
}