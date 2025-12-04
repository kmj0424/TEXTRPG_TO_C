#include "text.h"

void    FetchSet(t_Game *g)
{
	FILE *fp = fopen("SaveFile.txt", "rb");
	if (!fp)
	{
		perror("파일 열기 실패\n");
		return ;
	}
	if (!fread(&g->Player, sizeof(t_Player), 1, fp))
	{
		perror("파일 읽기 실패\n");
		fclose(fp);
		exit(1);
	}
	fclose(fp);
	Game(g);
}
