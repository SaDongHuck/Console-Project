#pragma once
#include "unit.h"
#include "shop.h"

class thief;
class monster;

class slidemap
{
private:
	int** map;
	int mapx, mapy;
	int cureent_map;
	bool eventTriggered;
	bool eventTrigger1, eventTrigger2, eventTrigger3, eventTrigger4;
	bool monstertriiger, monstertriiger1, monstertriiger2, monstertriiger3,
		monstertriiger4, monstertriiger5, monstertriiger6, monstertriiger7,
		monstertriiger8, monstertriiger9, monstertriger10, monstertriger11,
		monstertriger12, monstertriger13, monstertriger14;
	unit* player_unit;
	shop* player_shop;
public:
	void next_map();
	void make_map();
	void dungeon_map();
	void dungeon_map2();
	void dungeon_map3();
	void dungeon_map4();
	bool battle_map(unit& player, monster& m);
	void W_w();
	void S_s();
	void A_a();
	void D_d();
	slidemap();
	~slidemap();
	void set_player(unit* player) { player_unit = player; }
	void set_shop(shop* shop_obj) { player_shop = shop_obj; }
};
