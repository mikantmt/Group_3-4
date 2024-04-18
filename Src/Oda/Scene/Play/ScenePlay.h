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

	//PressEnter���ߕϐ�
	int m_BlendAlpha = 255;
	bool m_blendfrag = false;

	//�}�b�v�Ƃ̓����蔻��
	void MapCollision();
public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};