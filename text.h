#ifndef TEXT_H
# define TEXT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

enum Start{
	New = 1,
	Fetch,
	Exit,
};

enum Job{
	Fighter = 1,
	Mage,
	Assassin,
};

enum InGame{
	Dungeon = 1,
	MyInfo,
	Market,
	SavePoint,
	Back,
};

typedef struct s_Inven{
	int	HpPotion;
	int	MpPotion;
} t_Inven;

typedef struct s_Player{
	char	Name[35];
	char	Job[10];
	int		Lv;
	int		Exp;
	int		Hp;
	int		MaxHp;
	int		Mp;
	int		MaxMp;
	int 	MaxAtt;
	int 	MinAtt;
	int		SkillAtt;
	int		Gold;
	int		PlayerState;
	t_Inven Inv;
}   t_Player;

typedef struct s_Monster{
	char	Job[35];
	int		Hp;
	int		MaxHp;
	int		MaxAtt;
	int		MinAtt;
	int		Gold;
	int		GivenItem[3];
}	t_Monster;

typedef struct s_Game{
	t_Player Player;
	t_Monster Monster;
} t_Game;

void	NewSet(t_Game *g);
void    FetchSet(t_Game *g);
void 	Save(t_Game *g);

void    Game(t_Game *g);

void    InDungeon(t_Game *g);
int		RandNum(int i, int j);

void	Monset(t_Monster *Monster, char *MonLv);
void	EasyDun(t_Game *g);
void	NormalDun(t_Game *g);
void    HardDun(t_Game *g);

int		FightMon(t_Player *Player, t_Monster *Monster);

void    InMarket(t_Player *Player);

void    OpenStatus(t_Player *Player);
void    OpenItem(t_Player *Player);

#endif