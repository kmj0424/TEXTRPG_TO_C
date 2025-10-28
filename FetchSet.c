#include "text.h"

void    FetchSet(t_Game *g)
{
	FILE *fp = fopen("SaveFile.txt", "rb");
	if (!fp) {
		perror("파일 열기 실패");
		return;
	}

    fread(g, sizeof(t_Game), 1, fp);
	fclose(fp);
	Game(g);
}
