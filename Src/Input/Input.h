#pragma once

// 入力制御初期化
void InitInput();

// 入力制御ステップ
// 他のStepより早く呼ぶ
void StepInput();

// 今押された
bool IsKeyPush(int key_code);

//押され続けている
bool IsKeyKeep(int key_code);

//たった今離されたか
bool IsKeyRelease(int key_code);