#pragma once
// �t���[�����[�g���
class FrameRateInfo
{
public:
	int currentTime;	// ���݂̎���
	int lastFrameTime;	// �O��̃t���[�����s����
	int count;			// �t���[���J�E���g�p
	int calcFpsTime;	// FPS���v�Z��������
	float fps;			// �v������FPS(�\���p)

	void CalcFPS();

	void DrawFPS();
};