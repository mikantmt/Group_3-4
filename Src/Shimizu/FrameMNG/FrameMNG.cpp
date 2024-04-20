#include "DxLib.h"
#include "FrameMNG.h"


void FrameRateInfo::CalcFPS()
{
	// �O���FPS���v�Z�������Ԃ���̌o�ߎ��Ԃ����߂�
	int difTime = currentTime - calcFpsTime;

	// �O���FPS���v�Z�������Ԃ���
	// 1�b�ȏ�o�߂��Ă�����FPS���v�Z����
	if (difTime > 1000) {
		// �t���[���񐔂��~���b�ɍ��킹��
		// �����܂ŏo�������̂�float�ɃL���X�g
		float frameCount = (float)(count * 1000.0f);

		// FPS�����߂�
		// ���z�̐��l��60000/1000��60�ƂȂ�
		fps = frameCount / difTime;

		// �t���[�����[�g�J�E���g���N���A
		count = 0;

		// FPS���v�Z�������Ԃ��X�V
		calcFpsTime = currentTime;
	}
}

void FrameRateInfo::DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(1180, 704, color, "FPS[%.2f]", fps);
}