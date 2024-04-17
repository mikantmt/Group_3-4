#include "DxLib.h"

#ifndef __COLLISION_H__
#define __COLLISION_H__

class Collision {
private:
	bool click_flag;

	int x;
	int y;
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	//矩形との当たり判定
	bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

	//箱同士の当たり判定(オブジェクト1の座標,オブジェクト1のサイズ,オブジェクト2の座標,オブジェクト2のサイズ)すべてVECTOR型
	bool IsHitBox(VECTOR Obj1, VECTOR Size1, VECTOR Obj2, VECTOR Size2);

	//円との当たり判定
	bool IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2);

	//球同士の当たり判定(オブジェクト1の座標,オブジェクト1の半径,オブジェクト2の座標,オブジェクト2の半径)
	bool IsHitSphere(VECTOR Obj1, float radius1, VECTOR Obj2, float radius2);

	//矩形とマウスポインタの当たり判定
	//引数(X座標,Y座標,幅,高さ)
	bool RectToMousePointa(float X, float Y, float W, float H);

	//矩形とクリック当たり判定
	bool IsClickOnRect(float X, float Y, float W, float H);
};

#endif
