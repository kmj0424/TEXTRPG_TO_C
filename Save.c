#include "text.h"

void Save(t_Game *g)
{
	FILE *fp = fopen("SaveFile.txt", "wb");
	if (!fp)
	{
		perror("파일 쓰기 실패\n");
		return ;
	}
	if (!fwrite(&g->Player, sizeof(t_Player), 1, fp))
	{
		perror("저장 실패\n");
		fclose(fp);
		exit(1);
	}
	fclose(fp);
}
