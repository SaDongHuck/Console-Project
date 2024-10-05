#include "slidemap.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib> 
#include "util.h"
#include "monster.h"
using namespace std;
void slidemap::next_map()
{

	map = new int* [25];
	for (int i = 0; i < 25; i++)
	{
		map[i] = new int[25];
	}

	int next_map1[25][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,1},
		{1,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1},
		{1,0,0,0,0,3,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,3,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,3,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int next_map2[25][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},
		{1,0,1,1,0,1,1,1,1,0,0,3,0,0,0,0,0,0,0,0,0,1,1,0,1},
		{1,0,0,0,0,0,0,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,1},
		{1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1},
		{1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,3,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,3,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,3,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int next_map3[25][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,6,1,0,0,0,0,0,3,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1},
		{1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int next_map4[25][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,3,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,5,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int(*maps[4])[25][25] = { &next_map1, &next_map2, &next_map3, &next_map4 };
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			map[i][j] = (*maps[cureent_map])[i][j];
		}
	}
	mapx = 23;
	mapy = 1;
	cureent_map++;
}

void slidemap::make_map()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			int temp = map[i][j];
			if (temp == 0)
			{
				cout << "  ";
			}
			else if (temp == 1)
			{
				setColoer(lightcyan, black);
				cout << "▦ ";
			}
			else if (temp == 2)
			{
				setColoer(yellow, black);
				cout << "○ ";
			}
			else if (temp == 3)
			{
				setColoer(lightred, black);
				cout << "● ";
			}
			else if (temp == 4)
			{
				setColoer(lightpurple, black);
				cout << "☞ ";
			}
			else if (temp == 5)
			{
				setColoer(lightpurple, black);
				cout << "◆ ";
			}
			else if (temp == 6)
			{
				setColoer(yellow, black);
				cout << "★ ";
			}
		}
		cout << '\n';
	}
}

void slidemap::dungeon_map()
{
	if (mapx == 23 && mapy == 23)
	{
		system("cls");
		setColoer(green, black);
		cout << "다음 맵으로 이동 합니다" << '\n';
		cout << "===============================================" << '\n';
		cout << "####      ###     ##    ###    #   #   #   ###" << '\n';
		cout << "#  #     #   #   #  #   #  #   #   #   #  #    " << '\n';
		cout << "####     #   #   ####   #  #   #   ##  #  #  ##" << '\n';
		cout << "#    #   #   #   #  #   #  #   #   #  ##  #   #" << '\n';
		cout << "#    #    ###    #  #   ###    #   #   #   ###" << '\n';
		cout << "===============================================" << '\n';
		Sleep(3000);
		next_map();
	}

	if (mapx == 2 && mapy == 16) {
			cout << "상점에 도착했습니다." << '\n';
			player_unit->buy_item();
		}


	if (mapx == 3 && mapy == 22)
	{
		if (!monstertriiger) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("정식기사A", 80, 20, 25, myshop, 0, 10);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger = true;

			if (battleResult) {
				cout << "축하합니다! 정식기사A를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 4 && mapy == 5)
	{
		if (!monstertriiger1) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("정식기사B", 90, 20, 25, myshop,0,10);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger1 = true;

			if (battleResult) {
				cout << "축하합니다! 정식기사B를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 12 && mapy == 9)
	{
		if (!monstertriiger2) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("정식기사C", 85, 25, 25, myshop,0,10);
			bool battleResult  = battle_map(*player_unit, *m);
			delete m;
			monstertriiger2 = true;

			if (battleResult) {
				cout << "축하합니다! 정식기사C를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 7 && mapy == 9)
	{
		if (!monstertriiger3) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("변형된 티노", 70, 20, 25, myshop, 0, 10);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger3 = true;
			if (battleResult) {
				cout << "축하합니다! 변형된 티노를 물리쳤습니다.." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 19 && mapy == 16)
	{
		if (!monstertriiger4) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("변형된 티루", 73, 20, 25, myshop,0,10);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger4 = true;
			if (battleResult) {
				cout << "축하합니다! 변형된 티루를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 3 && mapy == 2) {
		if (!eventTrigger1) {
			cout << "메소를 얻었습니다! 500메소 추가!" << '\n';
			player_unit->addGold(500); // 플레이어의 골드에 500 추가
			eventTrigger1 = true; // 이벤트 발생 기록
		}
	}

	if (mapx == 15 && mapy == 7) {
		if (!eventTrigger2) {
			cout << "메소를 얻었습니다! 700메소 추가!" << '\n';
			player_unit->addGold(700); // 플레이어의 골드에 500 추가
			eventTrigger2 = true; // 이벤트 발생 기록
		}
	}
	
}

void slidemap::dungeon_map2()
{
	if (mapx == 5 && mapy == 7) {
		if (!eventTrigger3) {
			cout << "메소를 얻었습니다! 500메소 추가!" << '\n';
			player_unit->addGold(500); // 플레이어의 골드에 500 추가
			eventTrigger3 = true; // 이벤트 발생 기록
		}
	}

	if (mapx == 17 && mapy == 9)
	{
		if (!monstertriiger5) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("정식기사D", 95, 25, 25, myshop,0,20);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger5 = true;
			if (battleResult) {
				cout << "축하합니다! 정식기사D를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 13 && mapy == 15)
	{
		if (!monstertriiger6) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("정식기사E", 105, 25, 25, myshop,0,20);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger6 = true;
			if (battleResult) {
				cout << "축하합니다! 정식기사E를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 12 && mapy == 5)
	{
		if (!monstertriiger7) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("다크니스", 88, 25, 25, myshop,0,20);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger7 = true;
			if (battleResult) {
				cout << "축하합니다! 다크니스를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 4 && mapy == 11)
	{
		if (!monstertriiger8) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("상급기사A", 110, 25, 30, myshop,0,20);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger8 = true;
			if (battleResult) {
				cout << "축하합니다! 상급기사A를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 18 && mapy == 19)
	{
		if (!monstertriiger9) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("라이트닝", 95, 25, 25, myshop,0,20);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriiger9 = true;
			if (battleResult) {
				cout << "축하합니다! 라이트닝를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}
}

void slidemap::dungeon_map3()
{

	if (mapx == 15 && mapy == 22)
	{
		if (!monstertriger10) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("상급기사B", 115, 27, 37, myshop,0,30);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriger10 = true;
			if (battleResult) {
				cout << "축하합니다! 상급기사B를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 8 && mapy == 22)
	{
		if (!monstertriger11) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("상급기사C", 110, 27, 27, myshop,0,30);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriger11 = true;
			if (battleResult) {
				cout << "축하합니다! 상급기사C를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 1 && mapy == 23)
	{
		if (!monstertriger12) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("변형된 슬라임", 110, 27, 27, myshop,0,30);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriger12 = true;
			if (battleResult) {
				cout << "축하합니다! 변형된 슬라임를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 1 && mapy == 2)
	{
		if (!monstertriger13) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("변형된 리본돼지", 110, 27, 27, myshop,0,30);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriger13 = true;
			if (battleResult) {
				cout << "축하합니다! 변형된 리본돼지를 물리쳤습니다." << '\n';
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 8 && mapy == 15) {
		if (!eventTrigger4) {
			cout << "메소를 얻었습니다! 500메소 추가!" << '\n';
			player_unit->addGold(500); // 플레이어의 골드에 500 추가
			eventTrigger4 = true; // 이벤트 발생 기록
		}
	}

}

void slidemap::dungeon_map4()
{
	if (mapx == 9 && mapy == 11)
	{
		if (!monstertriger14) {
			shop myshop(0);
			system("cls");
			cout << "몬스터를 만났습니다" << '\n';
			monster* m = new monster("시그너스", 160, 35, 50, myshop, 0, 60);
			bool battleResult = battle_map(*player_unit, *m);
			delete m;
			monstertriger14 = true;
			if (battleResult) {
				cout << "축하합니다! 보스 시그너스 를 물리쳤습니다.\n게임을 종료 합니다" << '\n';
				exit(0);
			}
			else {
				cout << "게임 오버." << '\n';
				exit(0); // 프로그램 종료
			}
		}
	}

	if (mapx == 10 && mapy == 15) {
		cout << "상점에 도착했습니다." << '\n';
		player_unit->buy_item();
	}

}



bool slidemap::battle_map(unit&player, monster&m)
{
	while (true) {
		srand(time(NULL));
		// 플레이어 턴
		setColoer(lightred, black);
		cout << "======================================" << '\n';
		cout << "####    ###   #####   ##       ###### " << '\n';
		cout << "#  #   #   #  #####   ##       #      " << '\n';
		cout << "####   #   #    #     ##       #      " << '\n';
		cout << "#  #   #####    #     ##       ###### " << '\n';
		cout << "#  #   #   #    #     #####    #      " << '\n';
		cout << "###    #   #    #     #####    ###### " << '\n';
		cout << "======================================" << '\n';
		setColoer(yellow, black);
		cout << "================" << '\n';
		cout << "사용자 순서입니다" << '\n';
		cout << "================" << '\n';
		player.status();
		cout << '\n';
		m.status();
		cout << '\n';
		cout << "========================================" << '\n';
		cout << "1. 공격 2. 스킬 3.기본공격 4.HP회복 5.MP회복" << '\n';
		cout << "========================================" << '\n';
		int input;
		cin >> input;
		switch (input) {
		case 1:
			player.Attack(m); //공격
			break;
		case 2:
			player.Skill(m); //스킬
			break;
		case 3:
			player.Basic_attak(m); //기본공격
			break;
		case 4:
			player.HP();// 회복
			break;
		case 5:
			player.MP(); // 마나회복
		default:
			cout << "잘못 입력 하셨습니다." << '\n';
			continue; // 다시 입력
		}

		if (m.Gethealth() <= 0) {
			cout << "승리 하였습니다!" << '\n';
			player_unit->addGold(500);
			player_unit->Sethealth(player_unit->Gethealth() + 5);
			return true; // 전투 종료
		}

		// 몬스터 턴
		cout << "================" << '\n';
		cout << "몬스터 순서입니다" << '\n';
		cout << "================" << '\n';
		int m_input = rand() % 2 + 1; // 랜덤으로 공격 또는 스킬 선택
		switch (m_input) {
		case 1:
			m.Attack(player); // 공격
			break;
		case 2:
			m.Skill(player); // 스킬
			break;
		}

		if (player.Gethealth() <= 0) {
			cout << "게임에 졌습니다!" << '\n';
			return false;// 전투 종료
		}
	}

}

void slidemap::W_w()
{
	if (mapx > 0 && map[mapx - 1][mapy] != 1)
	{
		int temp = map[mapx][mapy];
		map[mapx][mapy] = map[mapx - 1][mapy];
		map[mapx - 1][mapy] = temp;
		mapx--;
		dungeon_map();
		dungeon_map2();
		dungeon_map3();
		dungeon_map4();
	}
}

void slidemap::S_s()
{
	if (mapx < 24 && map[mapx + 1][mapy] != 1)
	{
		int temp = map[mapx][mapy];
		map[mapx][mapy] = map[mapx + 1][mapy];
		map[mapx + 1][mapy] = temp;
		mapx++;
		dungeon_map();
		dungeon_map2();
		dungeon_map3();
		dungeon_map4();
	}
}

void slidemap::A_a()
{
	if (mapy > 0 && map[mapx][mapy - 1] != 1)
	{
		int temp = map[mapx][mapy];
		map[mapx][mapy] = map[mapx][mapy - 1];
		map[mapx][mapy - 1] = temp;
		mapy--;
		dungeon_map();
		dungeon_map2();
		dungeon_map3();
		dungeon_map4();
	
	}
}

void slidemap::D_d()
{
	if (mapy < 24 && map[mapx][mapy + 1] != 1)
	{
		int temp = map[mapx][mapy];
		map[mapx][mapy] = map[mapx][mapy + 1];
		map[mapx][mapy + 1] = temp;
		mapy++;
		dungeon_map();
		dungeon_map2();
		dungeon_map3();
		dungeon_map4();
	}
}



slidemap::slidemap() :mapx(23), mapy(1), cureent_map(0), eventTriggered(false), player_unit(nullptr), player_shop(nullptr),
monstertriiger(false), monstertriiger1(false), monstertriiger2(false), monstertriiger3(false), monstertriiger4(false),
monstertriiger5(false), monstertriiger6(false), monstertriiger7(false), monstertriiger8(false), monstertriiger9(false),
monstertriger10(false), monstertriger11(false), monstertriger12(false), monstertriger13(false),
eventTrigger1(false), eventTrigger2(false), eventTrigger3(false), eventTrigger4(false)
{

}

slidemap::~slidemap()
{
	for (int i = 0; i < 25; i++)
	{
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
	map = nullptr;
}

