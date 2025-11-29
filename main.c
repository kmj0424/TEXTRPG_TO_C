#include "text.h"

int main()
{
	t_Game g;

	int	Input = 0;

	memset(&g, 0, sizeof(t_Game));
	setlocale(LC_ALL, "");
    printf("(1)새게임 (2)불러오기 (3)나가기\n");
	scanf("%d", &Input);
	if (Input == New)
	{
		NewSet(&g);
		printf("새 정보를 저장합니다.\n");
		OpenStatus(&g.Player);
		Save(&g);
		Game(&g);
	}
	else if (Input == Fetch)
		FetchSet(&g);
	else (Input == Exit)
		;
	return 0;
}
