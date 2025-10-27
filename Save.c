#include "text.h"

void Save(t_Player *Player)
{
    FILE *fp = fopen("SaveFile.txt", "wb");
    if (!fp) {
        perror("파일 열기 실패");
        return;
    }
    fwrite(Player, sizeof(t_Player), 1, fp);
    fclose(fp);
}
