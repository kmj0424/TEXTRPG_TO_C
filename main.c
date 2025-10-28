#include "text.h"

int main()
{
	t_Game g;

	int	Input;

	memset(&g, 0, sizeof(t_Game));
    printf("(1)새게임 (2)불러오기 (3)나가기\n");
	scanf("%d", &Input);
	if (Input == New)
	{
		NewSet(&g);
	}
	if (Input == Fetch)
	{
		FetchSet(&g);
	}
	if (Input == Exit)
		;// free();
	return 0;
};