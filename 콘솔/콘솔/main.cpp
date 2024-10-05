#include <iostream>
#include <windows.h>
#include <conio.h>
#include "util.h"
#include "slidemap.h"
#include "shop.h"
#include "thief.h"
#include "archer.h"
#include "pirate.h"
#include "main.h"
using namespace std;

void init();
void title();
void gotoxy(int, int);

int main()
{
	slidemap* s = new slidemap();
	shop my_shop(500);
	unit* player = nullptr;
	thief *p = new thief("도적",90,10,20,100,my_shop, 20, 5, 5, 10);
	archer* a = new archer("궁수", 90, 10, 20,100,my_shop, 20, 5, 5, 10);
	pirate* i = new pirate("해적", 90, 10, 20,100,my_shop, 20, 5, 5, 10);
	s->set_shop(&my_shop);
	init();
	while (1) {
		setColoer(lightgreen, black);
		title();
		setColoer(lightpurple, black);
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// 게임시작
				int choice;
				system("cls");
				cout << "직업을 선택하세요" << '\n';
				cout << "1.도적" << '\n';
				cout << "2.궁수" << '\n';
				cout << "3.해적" << '\n';
				cin >> choice;
				switch (choice)
				{
				case 1:
					player = p;
					break;
				case 2:
					player = a;
					break;
				case 3:
					player = i;
				default:
					cout << "잘못 입력 하셨습니다" << '\n';
					break;
				}
				system("cls");
				s->set_player(player);
				s->next_map();
				while (1)
				{
					s->make_map();
					cout << "키를 입력해 주세요 w a s d" << '\n';
					char input = _getch();
					switch (input)
					{
					case 'W':
					case 'w':
						s->W_w();
						break;
					case 'S':
					case 's':
						s->S_s();
						break;
					case 'A':
					case 'a':
						s->A_a();
						break;
					case 'D':
					case 'd':
						s->D_d();
						break;
					case 'z':
					case 'Z':
						player->show_inventory();
						break;
					default:
						cout << "잘못 입력 다시 ㄱㄱ " << '\n';
						continue;
						break;
					}
				}
			delete p;
			delete s;
		}
		system("cls");
	}
	return 0;
}

void init()
{
	system("mode con cols=56 lines=28 | title 턴제 RPG");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // false 또는 0 : 숨기기 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void title()
{
	cout << " ######         #       #######   ##        ########" << '\n';
	cout << " #      #     #    #    #######   ##        #        " << '\n';
	cout << " #      #     #    #       #      ##        #        " << '\n';
	cout << " ######       ######       #      ##        #########" << '\n';
	cout << " #      #     #    #       #      ##        #        " << '\n';
	cout << " #      #     #    #       #      ######    #        " << '\n';
	cout << " ######       #    #       #      ######    ########" << '\n';

}



