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
	thief *p = new thief("����",90,10,20,100,my_shop, 20, 5, 5, 10);
	archer* a = new archer("�ü�", 90, 10, 20,100,my_shop, 20, 5, 5, 10);
	pirate* i = new pirate("����", 90, 10, 20,100,my_shop, 20, 5, 5, 10);
	s->set_shop(&my_shop);
	init();
	while (1) {
		setColoer(lightgreen, black);
		title();
		setColoer(lightpurple, black);
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// ���ӽ���
				int choice;
				system("cls");
				cout << "������ �����ϼ���" << '\n';
				cout << "1.����" << '\n';
				cout << "2.�ü�" << '\n';
				cout << "3.����" << '\n';
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
					cout << "�߸� �Է� �ϼ̽��ϴ�" << '\n';
					break;
				}
				system("cls");
				s->set_player(player);
				s->next_map();
				while (1)
				{
					s->make_map();
					cout << "Ű�� �Է��� �ּ��� w a s d" << '\n';
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
						cout << "�߸� �Է� �ٽ� ���� " << '\n';
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
	system("mode con cols=56 lines=28 | title ���� RPG");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // false �Ǵ� 0 : ����� 
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



