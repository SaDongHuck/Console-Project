#pragma once
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;
#ifndef KEY_CODE
#define KEY_CODE
// 키보드 값  
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택(스페이스바) 
#endif

void gotoxy(int, int);
int keyControl();
int menuDraw();
void infoDraw();

int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') { // 스페이스바(공백)이 선택 버튼  
		return SUBMIT;
	}
}

int menuDraw() {
	int x = 24;
	int y = 12;
	gotoxy(x - 2, y); // -2 한 이유는 > 를 출력해야하기 때문에  
	cout << ("> 게임시작");
	while (1) { // 무한반복  
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기  
		switch (n) {
		case UP: { // 입력된 키의 값이 UP인경우 (w) 
			if (y > 12) { // y는 12~14까지만 이동  
				gotoxy(x - 2, y); // x-2 하는 이유는 ">"를 두칸 이전에 출력하기위해  
				cout << (" "); // 원래 위치를 지우고  
				gotoxy(x - 2, --y); // 새로 이동한 위치로 이동하여  
				cout << (">"); // 다시 그리기  
			}
			break;
		}

		case DOWN: { // 입력된 키의 값이 DOWN인경우 (s) 
			if (y < 14) { // 최대 14  
				cout << (x - 2, y);
				cout << (" ");
				gotoxy(x - 2, ++y);
				cout << (">");
			}
			break;
		}

		case SUBMIT: {
			return y - 12; // 스페이스바(선택)되었을 경우 y-12
			// y 시작 위치가 12였으므로 y-12 를 하면 0, 1, 2 세 숫자를 받을 수 있다. 
		}
		}
	}
}

void infoDraw() {
	system("cls"); // 화면 모두 지우기  
	cout << ("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: W, A, S, D\n");
	printf("                    선택: 스페이스바\n\n\n\n\n\n\n");
	printf("               개발자: codevkr.tistory.com\n\n");
	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
