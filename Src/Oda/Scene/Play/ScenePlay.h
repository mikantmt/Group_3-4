#pragma once
#include "../../Scene/Scene.h"
#include "../../../Shimizu/Player/Player.h"
#include "../../../Shimizu/MapChip/MapChip.h"
#include "../../../Shimizu/Collision/Collision.h"
#include "../../../Shimizu/Screen/Screen.h"
#include "../../Score/Score.h"

class Play : public Scene {
private:
	Player player;
	MapChip maps;
	Collision collision;
	Screen screen;

	int BackGroundHandle;

	//マップとの当たり判定
	void MapCollision();
public:
	int CarrotPoint;

	void Init();
	void Step();
	void Draw();
	void Fin();
};