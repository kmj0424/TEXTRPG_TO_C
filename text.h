#ifndef TEXT_H
# define TEXT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "get_next_line.h"
//#include <./mlx/mlx.h>

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
	DonGeon = 1,
	MyInfo,
	Market,
	SavePoint,
	Back,
};

enum Market{
	Purchase = 1,
	Sale,
}

enum	Item{
	HpPotion,
	ItemGold,
}

typedef struct s_Player{
	char	Name[10];
	char	Job[10];
	int		Lv;
	int		Exp;
	int		Hp;
	int		MaxHp;
	int 	MaxAtt;
	int 	MinAtt;
	int		Gold;
}   t_Player;

typedef struct s_Monster{
	char	*Job;
	int		Hp;
	int		MaxHp;
	int		MaxAtt;
	int		MinAtt;
	int		Gold;
	int		GivenItem[3];
}	t_Monster;
                                             
void	NewSet(t_Player *Player);
void    FetchSet(t_Player *Player);
void 	Save(t_Player *Player);
void    FetchSet(t_Player *Player);
void    Game(t_Player *Player);
void    InDonGeon(t_Player *Player);
void    InMarket(t_Player *Player);
void    OpenStatus(t_Player *Player);
void    OpenItem(t_Player *Player);

#endif