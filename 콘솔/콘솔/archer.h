#pragma once
#ifndef ARCHER_H
#define ARCHER_H

#include "unit.h"
#include "shop.h"
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

class archer : public unit
{
private:
	int arrowcount;
	int white_position;
	int red_position1;
	int orange_position1;
	int blue_position;
	int grape_juice;
public:
	archer(const string& n, int a, int b, int c, int d ,shop& g, int arrow, int wh, int bl, int f)
		: unit(n,a,b,c,d,g,f), arrowcount(arrow), white_position(wh), blue_position(bl), red_position1(0), orange_position1(0),
	grape_juice(0){}
	~archer()
	{

	}
	void Setwhite_position(int k)override { white_position = k; }
	int Getwhite_position()const { return white_position; }
	void Setred_position1(int u)override { red_position1 = u; }
	int Getred_position1()const { return red_position1; }
	void Setorange_position1(int r)override { orange_position1 = r; }
	int Getorange_position1()const { return orange_position1; }
	void Setblue_position(int bl) override { blue_position = bl; }
	int Getblue_position()const override { return blue_position; }
	void Setgrape_juice(int q) override { grape_juice = q; }
	int Getgrpae_juice() const override { return grape_juice; }
	void Setweapon(int e)override { arrowcount = e; }
	int Getweapon()const { return arrowcount; }

	void status() override
	{
		cout << "플레이어 이름 : " << name << '\n';
		cout << "채력 : " << Gethealth() << '\n';
		cout << "MP : " << GetMP() << '\n';
		cout << "공격력 : " << attack << '\n';
		cout << "방어력 : " << Getdefense() << '\n';
		cout << "현재 매소 : " << player_shop.Getgold() << '\n';
		cout << "현재 화살 수 : " << Getweapon() << '\n';
	}

	void Attack(unit& target) override
	{
		if (Getweapon() <= 0) {
			cout << "화살이 없어서 공격을 할 수 없습니다.\n";
			return;
		}


		int AttackDamage = 8;

		cout << name << "이(가) 화살을 발사합니다.\n";
		Setweapon(Getweapon() - 1);
		cout << "현재 화살 수는 " << Getweapon() << "개 남았습니다.\n";
		target.Sethealth(target.Gethealth() - AttackDamage);
		cout << "데미지는 " << AttackDamage << "만큼 받았습니다. "
			<< "적 채력은 " << target.Gethealth() << " 남았습니다.\n";
	}

	void Basic_attak(unit& target) override
	{
		int BasicDamage = 3;
		cout << name << "이(가) 기본 공격을 합니다.\n";
		target.Sethealth(target.Gethealth() - BasicDamage);
		cout << "데미지는 " << BasicDamage << "만큼 받았습니다. "
			<< "적 채력은 " << target.Gethealth() << " 남았습니다.\n";

	}

	void Skill(unit& target) override
	{
		if (Getweapon() <= 0) {
			cout << "화살이 없어서 스킬을 사용할 수 없습니다.\n";
			return;
		}

		if (GetMP() <= 0) {
			cout << "MP 부족해서 스킬을 사용할 수 없습니다\n";
			return;
		}


	
		int choice;
		cout << "스킬을 선택 하시오" << '\n';
		cout << "1.피어싱(30)" << '\n';
		cout << "2.스나이핑(20)" << '\n';
		cout << "3.스트레이프(25)" << '\n';
		cout << "4.프리져(40)" << '\n';
		cin >> choice;
		int skillDamage = 0;
		switch (choice)
		{
		case 1: skillDamage = 30;
			SetMP(GetMP() - 8);
			break;
		case 2: skillDamage = 20;
			SetMP(GetMP() - 3);
			break;
		case 3: skillDamage = 25;
			SetMP(GetMP() - 5);
			break;
		case 4: skillDamage = 40;
			SetMP(GetMP() - 10);
			break;
		default:
			cout << "잘못 입력 하셨습니다 " << '\n';
			break;
		}
		cout << name << "이(가) 스킬을 사용합니다.\n";
		Setweapon(Getweapon() - 1);
		cout << "현재 표창 수는 " << Getweapon() << "개 남았습니다.\n";
		target.Sethealth(target.Gethealth() - skillDamage);
		cout << "스킬 데미지는 " << skillDamage << "만큼 받았습니다. "
			<< "적 채력은 " << target.Gethealth()<< " 남았습니다.\n";
		cout << "현재 MP는 " << GetMP() << "남았습니다" << '\n';
		
	}

	void show_inventory() override
	{
		cout << "인벤토리 입니다!!" << '\n';
		cout << "화살 : " << Getweapon() << '\n';
		cout << "하얀 포션 : " << Getwhite_position() << '\n';
		cout << "빨간 포션 : " << Getred_position1() << '\n';
		cout << "주황 포션 : " << Getorange_position1() << '\n';
		cout << "파란 포션 : " << Getblue_position() << '\n';
		cout << "포도 주스 : " << Getgrpae_juice() << '\n';
	}

	void buy_item() override
	{
		player_shop.buy_item(*this);
	}

	void HP() override
	{
		int choice;
		const int white_position_heal = 100;
		const int red_position1_heal = 60;
		const int orange_position1_heal = 80;
		if (Getwhite_position() > 0 || Getred_position1() > 0 || Getorange_position1() > 0)
		{
			cout << "1.하얀 포션" << Getwhite_position() << "(개) 남음" << '\n';
			cout << "2.빨간 포션" << Getred_position1() << "(개) 남음" << '\n';
			cout << "3.주황 포션" << Getorange_position1() << "(개) 남음" << '\n';
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (Getwhite_position() > 0) {
					cout << "하얀 포션을 선택했습니다" << '\n';
					Setwhite_position(Getwhite_position() - 1);
					Sethealth(Gethealth() + white_position_heal);
					cout << "현재 채력은 " << Gethealth() << "입니다" << '\n';
				}
				else {
					cout << "하얀 포션이 없습니다!" << '\n';
				}
				break;
			case 2:
				if (Getred_position1() > 0) {
					cout << "빨간 포션을 선택했습니다" << '\n';
					Setred_position1(Getred_position1() - 1);
					Sethealth(Gethealth() + red_position1_heal);
					cout << "현재 채력은 " << Gethealth() << "입니다" << '\n';
				}
				else {
					cout << "빨강 포션이 없습니다 " << '\n';
				}
				break;
			case 3:
				if (Getorange_position1() > 0)
				{
					cout << "주황 포션을 선택했습니다" << '\n';
					Setorange_position1(Getorange_position1() - 1);
					Sethealth(Gethealth() + orange_position1_heal);
					cout << "현재 채력은 " << Gethealth() << "입니다" << '\n';
				}
				else {
					cout << "주황 포션이 없습니다 " << '\n';
				}
				break;
			default:
				cout << "잘못 입력 하셨습니다 " << '\n';
				break;
			}
		}
	}

	void MP() override
	{
		int choice;
		const int blue_position_heal = 70;
		const int grape_juice_heal = 100;
		if (Getblue_position() > 0 || Getgrpae_juice() > 0)
		{
			cout << "1.파란 포션" << Getblue_position() << "(개) 남음" << '\n';
			cout << "2.포도 주스" << Getgrpae_juice() << "(개) 남음" << '\n';
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (Getblue_position() > 0) {
					cout << "파란 포션을 선택했습니다" << '\n';
					Setblue_position(Getblue_position() - 1);
					SetMP(GetMP() + blue_position_heal);
					cout << "현재 마나는 " << GetMP() << "입니다" << '\n';
				}
				else {
					cout << "파란 포션이 없습니다!" << '\n';
				}
				break;
			case 2:
				if (Getgrpae_juice() > 0) {
					cout << "포도 주스를 선택했습니다" << '\n';
					Setred_position1(Getred_position1() - 1);
					SetMP(GetMP() + grape_juice_heal);
					cout << "현재 채력은 " << GetMP() << "입니다" << '\n';
				}
				else {
					cout << "포도 주스가 없습니다 " << '\n';
				}
				break;
			default:
				cout << "잘못 입력 하셨습니다 " << '\n';
				break;
			}
		}
	}

};


#endif