#include "text.h"

void Save(t_Game *g)
{
	FILE *fp = fopen("SaveFile.txt", "wb");
	if (!fp) {
		perror("파일 쓰기 실패\n");
		return;
	}
	fwrite(g, sizeof(t_Game), 1, fp);
	fclose(fp);
}
