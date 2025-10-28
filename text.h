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
};

// enum	Item{
// 	HpPotion,
// 	ItemGold,
// };

typedef struct s_Inven{
	int	HpPotion;
	int	MpPotion;
} t_Inven;

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
	t_Inven Inv;
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

typedef struct s_Game{
	t_Player Player;
	t_Monster Monster;
} t_Game;
                                             
void	NewSet(t_Game *g);
void    FetchSet(t_Game *g);
void 	Save(t_Game *g);

void    Game(t_Game *g);

void    InDonGeon(t_Player *Player);
void    InMarket(t_Player *Player);
void    OpenStatus(t_Player *Player);
void    OpenItem(t_Player *Player);

#endif

/*
typedef enum e_ItemID { ITEM_HP=1, ITEM_MP=2 } t_ItemID;

typedef struct s_Slot {
    int item_id;            // ITEM_HP / ITEM_MP
    unsigned short count;
} t_Slot;

#define INVENTORY_SIZE 16
typedef struct s_Inventory {
    t_Slot slots[INVENTORY_SIZE];
} t_Inventory;

typedef struct s_Game {
    t_Player    player;
    t_Monster   monster;
    t_Inventory inv;
    int         floor;
} t_Game;

// 헬퍼
static int find_same(t_Inventory *inv, int item_id){
    for(int i=0;i<INVENTORY_SIZE;i++)
        if(inv->slots[i].item_id==item_id && inv->slots[i].count>0) return i;
    return -1;
}
static int find_empty(t_Inventory *inv){
    for(int i=0;i<INVENTORY_SIZE;i++)
        if(inv->slots[i].count==0) return i;
    return -1;
}

int inv_add(t_Inventory *inv, int item_id, unsigned short n){
    int s = find_same(inv, item_id);
    if(s<0) s = find_empty(inv);
    if(s<0) return 0;
    inv->slots[s].item_id = item_id;
    inv->slots[s].count  += n;
    return 1;
}

int use_item_slot(t_Game *g, int slot_idx, int hp_heal, int mp_heal){
    if(slot_idx<0 || slot_idx>=INVENTORY_SIZE) return 0;
    t_Slot *sl = &g->inv.slots[slot_idx];
    if(sl->count==0) return 0;

    if(sl->item_id == ITEM_HP){
        g->player.Hp += hp_heal; clamp_up(&g->player.Hp, g->player.MaxHp);
    } else if(sl->item_id == ITEM_MP){
        // g->player.Mp += mp_heal; clamp_up(&g->player.Mp, g->player.MaxMp);
    } else return 0;

    sl->count--;
    if(sl->count==0) sl->item_id=0;
    return 1;
}
*/