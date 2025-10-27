#include "text.h"

void    FetchSet(t_Player *Player)
{
	FILE *fp = fopen("SaveFile.txt", "rb");
	if (!fp) {
		perror("파일 열기 실패");
		return;
	}

	fread(Player, sizeof(t_Player), 1, fp);
	fclose(fp);
	Game(Player);
}
