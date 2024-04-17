#include "MapChip.h"

void MapChip::Init() {
	MapID = MAP;

	// 画像ロード
	LoadDivGraph(MapCipFilePath[MAP],
		MapCipNum[MAP],
		MapCipImageSplitNum[MAP][0], MapCipImageSplitNum[MAP][1],
		MAPCIP_X_SIZE, MAPCIP_Y_SIZE, MapCipHandle);

	Read();
}

void MapChip::Step() {

}

void MapChip::Draw(int X) {
	for (int MapChipYIndex = 0; MapChipYIndex < MAPCIP_Y_MAXNUM; MapChipYIndex++) {
		for (int MapChipXIndex = 0; MapChipXIndex < MAPCIP_X_MAXNUM; MapChipXIndex++) {
				int mapciptype = m_FileReadMapData[MapChipYIndex][MapChipXIndex];
				DrawGraph(MAPCIP_X_SIZE * MapChipXIndex - (int)X, MAPCIP_Y_SIZE * MapChipYIndex,
					MapCipHandle[mapciptype], true);
		}
	}
}

void MapChip::Read() {
	FILE* fp;

	fopen_s(&fp, CsvFilePath[MapID], "r");

	int mapIndexX = 0;
	int mapIndexY = 0;

	while (true) {
		// 数値部分を読み込む
		fscanf_s(fp, "%d", &m_FileReadMapData[mapIndexY][mapIndexX]);
		mapIndexX++;

		// 「,」を飛ばすために読み込みを実行
		char chara = fgetc(fp);

		// EOFの場合は読み込み終了
		if (chara == EOF) {
			break;
		}

		// 改行コードの場合は保存先を変更する
		if (chara == '\n') {
			mapIndexY++;
			mapIndexX = 0;
		}
	}

	fclose(fp);
}

void MapChip::Fin() {

}

