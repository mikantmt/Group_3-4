#pragma once
#include "../../Scene/Scene.h"
#include "../../../Shimizu/Player/Player.h"
#include "../../../Shimizu/MapChip/MapChip.h"
#include "../../../Shimizu/Collision/Collision.h"
#include "../../../Shimizu/Screen/Screen.h"

class Play : public Scene {
private:
	Player player;
	MapChip maps;
	Collision collision;
	Screen screen;

	//PressEnter“§‰ß•Ï”
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;

	//ƒ}ƒbƒv‚Æ‚Ì“–‚½‚è”»’è
	void MapCollision();
public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};